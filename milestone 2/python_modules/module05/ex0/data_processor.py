from abc import ABC, abstractmethod
from typing import Any, Union
 
 
class DataProcessor(ABC):
    """Abstract base class defining the common processing interface."""
 
    def __init__(self) -> None:
        self._storage: list[tuple[int, str]] = []
        self._counter: int = 0
 
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
 
    def validate(self, data: Any) -> bool:
        if isinstance(data, bool):
            return False
        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            return all(
                isinstance(item, (int, float)) and not isinstance(item, bool)
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
 
 
if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
 
    # --- NumericProcessor ---
    print("\nTesting Numeric Processor...")
    num_proc = NumericProcessor()
 
    print(f" Trying to validate input '42': {num_proc.validate(42)}")
    print(f" Trying to validate input 'Hello': {num_proc.validate('Hello')}")
 
    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")  # type: ignore[arg-type]
    except TypeError as e:
        print(f"  Got exception: {e}")
 
    num_data: list[Union[int, float]] = [1, 2, 3, 4, 5]
    print(f" Processing data: {num_data}")
    num_proc.ingest(num_data)
    print(" Extracting 3 values...")
    for _ in range(3):
        rank, value = num_proc.output()
        print(f"  Numeric value {rank}: {value}")
 
    # --- TextProcessor ---
    print("\nTesting Text Processor...")
    txt_proc = TextProcessor()
 
    print(f" Trying to validate input '42': {txt_proc.validate(42)}")
 
    txt_data = ['Hello', 'Nexus', 'World']
    print(f" Processing data: {txt_data}")
    txt_proc.ingest(txt_data)
    print(" Extracting 1 value...")
    rank, value = txt_proc.output()
    print(f"  Text value {rank}: {value}")
 
    # --- LogProcessor ---
    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
 
    print(f" Trying to validate input 'Hello': {log_proc.validate('Hello')}")
 
    log_data = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    print(f" Processing data: {log_data}")
    log_proc.ingest(log_data)
    print(" Extracting 2 values...")
    for _ in range(2):
        rank, value = log_proc.output()
        print(f"  Log entry {rank}: {value}")
