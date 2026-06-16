"""
Exercise 0: Space Station Data
Demonstrates basic Pydantic model creation with BaseModel and Field validation.
"""

from datetime import datetime
from typing import Optional

from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    """Validates incoming data streams from space station monitoring
    systems."""

    # Station identifier: between 3 and 10 characters
    station_id: str = Field(..., min_length=3, max_length=10)

    # Human-readable name: between 1 and 50 characters
    name: str = Field(..., min_length=1, max_length=50)

    # Number of crew members currently aboard: 1 to 20
    crew_size: int = Field(..., ge=1, le=20)

    # Current power level as a percentage: 0.0 to 100.0
    power_level: float = Field(..., ge=0.0, le=100.0)

    # Current oxygen level as a percentage: 0.0 to 100.0
    oxygen_level: float = Field(..., ge=0.0, le=100.0)

    # Date and time of the last maintenance performed
    # Pydantic automatically converts ISO 8601 strings to datetime objects
    last_maintenance: datetime

    # Whether the station is currently active; defaults to True
    is_operational: bool = Field(default=True)

    # Free-text notes, optional and capped at 200 characters
    notes: Optional[str] = Field(default=None, max_length=200)


def main() -> None:
    """
    Demonstrate valid station creation and expected validation errors.
    """
    print("Space Station Data Validation")
    print("=" * 40)

    # --- Valid station ---
    station = SpaceStation(
        station_id="ISS001",
        name="International Space Station",
        crew_size=6,
        power_level=85.5,
        oxygen_level=92.3,
        # Passing a string: Pydantic converts it to datetime automatically
        last_maintenance="2024-11-01T08:00:00",
        is_operational=True,
        notes="All systems nominal.",
    )

    print("Valid station created:")
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    print(f"Status: {'Operational' if station.is_operational else 'Offline'}")

    print("=" * 40)

    # --- Invalid station: crew_size exceeds the maximum of 20 ---
    try:
        SpaceStation(
            station_id="BAD001",
            name="Overloaded Station",
            crew_size=25,  # violates le=20
            power_level=70.0,
            oxygen_level=80.0,
            last_maintenance="2024-10-15T12:00:00",
        )
    except ValidationError as error:
        print("Expected validation error:")
        # Print only the human-readable message of the first error
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
