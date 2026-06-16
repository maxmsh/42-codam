from abc import ABC, abstractmethod
from typing import Any, Union


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
        self, data: Union[int, float, list[Union[int, float]]]
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
        items: list[str] = data if isinstance(data, list) else [data]
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
                isinstance(entry, dict)
                and all(
                    isinstance(k, str) and isinstance(v, str)
                    for k, v in entry.items()
                )
                for entry in data
            )
        return False

    def ingest(
        self, data: Union[dict[str, str], list[dict[str, str]]]
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


if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")

    stream = DataStream()
    print("Initialize Data Stream...")
    stream.print_processors_stats()

    print("\nRegistering Numeric Processor")
    stream.register_processor(NumericProcessor())

    batch: list[Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {
                "log_level": "INFO",
                "log_message": "User wil is connected",
            },
        ],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print("\nRegistering other data processors")
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()

    print(
        "\nConsume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )
    processors = stream._processors
    for _ in range(3):
        processors[0].output()
    for _ in range(2):
        processors[1].output()
    for _ in range(1):
        processors[2].output()
    stream.print_processors_stats()
