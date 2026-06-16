from abc import ABC, abstractmethod
from typing import Any, Protocol, Union


class ExportPlugin(Protocol):
    """Protocol defining the interface for export plugins."""

    def process_output(
        self, data: list[tuple[int, str]]
    ) -> None:
        """Export a list of (rank, value) tuples."""
        ...


class DataProcessor(ABC):
    """Abstract base class defining the common processing interface."""

    name: str = "Data Processor"

    def __init__(self) -> None:
        self._storage: list[tuple[int, str]] = []
        self._counter: int = 0

    @property
    def total_processed(self) -> int:
        """Total items ever ingested by this processor."""
        return self._counter

    @property
    def remaining(self) -> int:
        """Items currently stored, not yet extracted."""
        return len(self._storage)

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Return True if data is appropriate for this processor."""
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        """Store data internally after processing."""
        pass

    def output(self) -> tuple[int, str]:
        """Extract and remove the oldest stored item with its rank."""
        if not self._storage:
            raise IndexError("No data available in processor")
        return self._storage.pop(0)


class NumericProcessor(DataProcessor):
    """Processes int, float, and mixed lists of both."""

    name = "Numeric Processor"

    def validate(self, data: Any) -> bool:
        if isinstance(data, bool):
            return False
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(
                isinstance(item, (int, float))
                and not isinstance(item, bool)
                for item in data
            )
        return False

    def ingest(
        self,
        data: Union[int, float, list[Union[int, float]]]
    ) -> None:
        if not self.validate(data):
            raise TypeError("Improper numeric data")
        items: list[Union[int, float]] = (
            data if isinstance(data, list) else [data]
        )
        for item in items:
            self._storage.append((self._counter, str(item)))
            self._counter += 1


class TextProcessor(DataProcessor):
    """Processes str and lists of strings."""

    name = "Text Processor"

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(item, str) for item in data)
        return False

    def ingest(self, data: Union[str, list[str]]) -> None:
        if not self.validate(data):
            raise TypeError("Improper text data")
        items: list[str] = (
            data if isinstance(data, list) else [data]
        )
        for item in items:
            self._storage.append((self._counter, item))
            self._counter += 1


class LogProcessor(DataProcessor):
    """Processes dict[str, str] and lists thereof."""

    name = "Log Processor"

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in data.items()
            )
        if isinstance(data, list):
            return all(
                isinstance(entry, dict) and all(
                    isinstance(k, str) and isinstance(v, str)
                    for k, v in entry.items()
                )
                for entry in data
            )
        return False

    def ingest(
        self,
        data: Union[dict[str, str], list[dict[str, str]]]
    ) -> None:
        if not self.validate(data):
            raise TypeError("Improper log data")
        items: list[dict[str, str]] = (
            data if isinstance(data, list) else [data]
        )
        for item in items:
            log_str = ": ".join(item.values())
            self._storage.append((self._counter, log_str))
            self._counter += 1


class DataStream:
    """Routes a mixed data stream to registered processors."""

    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        """Add a data processor to the stream."""
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        """Route each element to the first compatible processor."""
        for element in stream:
            handled = False
            for proc in self._processors:
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break
            if not handled:
                print(
                    "DataStream error - "
                    f"Can't process element in stream: {element}"
                )

    def print_processors_stats(self) -> None:
        """Print total and remaining counts for each processor."""
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for proc in self._processors:
            print(
                f"{proc.name}: "
                f"total {proc.total_processed} items processed, "
                f"remaining {proc.remaining} on processor"
            )

    def output_pipeline(
        self, nb: int, plugin: ExportPlugin
    ) -> None:
        """Consume nb items per processor and export via plugin."""
        for proc in self._processors:
            results: list[tuple[int, str]] = []
            for _ in range(nb):
                if proc.remaining == 0:
                    break
                results.append(proc.output())
            if results:
                plugin.process_output(results)


class CSVExportPlugin:
    """Exports data as a comma-separated values string."""

    def process_output(
        self, data: list[tuple[int, str]]
    ) -> None:
        values = ",".join(value for _, value in data)
        print("CSV Output:")
        print(values)


class JSONExportPlugin:
    """Exports data as a JSON object keyed by item rank."""

    def process_output(
        self, data: list[tuple[int, str]]
    ) -> None:
        pairs = ", ".join(
            f'"item_{rank}": "{value}"'
            for rank, value in data
        )
        print("JSON Output:")
        print("{" + pairs + "}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")

    stream = DataStream()
    print("Initialize Data Stream...")
    stream.print_processors_stats()

    print("\nRegistering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())

    batch1: list[Any] = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {
                'log_level': 'WARNING',
                'log_message': 'Telnet access! Use ssh instead',
            },
            {
                'log_level': 'INFO',
                'log_message': 'User wil is connected',
            },
        ],
        42,
        ['Hi', 'five'],
    ]
    print(f"Send first batch of data on stream: {batch1}")
    stream.process_stream(batch1)
    stream.print_processors_stats()

    print(
        "\nSend 3 processed data from each processor "
        "to a CSV plugin:"
    )
    stream.output_pipeline(3, CSVExportPlugin())
    stream.print_processors_stats()

    batch2: list[Any] = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {
                'log_level': 'ERROR',
                'log_message': '500 server crash',
            },
            {
                'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days',
            },
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello',
    ]
    print(f"\nSend another batch of data: {batch2}")
    stream.process_stream(batch2)
    stream.print_processors_stats()

    print(
        "\nSend 5 processed data from each processor "
        "to a JSON plugin:"
    )
    stream.output_pipeline(5, JSONExportPlugin())
    stream.print_processors_stats()
