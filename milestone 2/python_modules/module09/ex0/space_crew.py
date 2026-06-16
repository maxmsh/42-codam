"""
Exercise 2: Space Crew Management
Demonstrates nested Pydantic models and complex cross-model validation.
"""

from datetime import datetime
from enum import Enum
from typing import List

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    """Recognised crew ranks in ascending order of seniority."""

    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    """Represents a single crew member assigned to a space mission."""

    # Unique member identifier: 3 to 10 characters
    member_id: str = Field(..., min_length=3, max_length=10)

    # Full name: 2 to 50 characters
    name: str = Field(..., min_length=2, max_length=50)

    # Military/professional rank
    rank: Rank

    # Age in years: must be between 18 (adult) and 80
    age: int = Field(..., ge=18, le=80)

    # Area of expertise: 3 to 30 characters
    specialization: str = Field(..., min_length=3, max_length=30)

    # Years of relevant experience: 0 (fresh cadet) to 50
    years_experience: int = Field(..., ge=0, le=50)

    # Whether this member is currently available for duty; defaults to True
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    """
    Represents a complete space mission including its crew manifest.

    Safety rules enforced by the model validator:
    - mission_id must start with "M"
    - crew must include at least one Commander or Captain
    - missions longer than 365 days need ≥ 50 % experienced crew (5+ years)
    - every crew member must be active
    """

    # Unique mission identifier: 5 to 15 characters
    mission_id: str = Field(..., min_length=5, max_length=15)

    # Descriptive mission name: 3 to 100 characters
    mission_name: str = Field(..., min_length=3, max_length=100)

    # Target destination: 3 to 50 characters
    destination: str = Field(..., min_length=3, max_length=50)

    # Scheduled launch date and time
    launch_date: datetime

    # Planned mission length: 1 day to 10 years (3650 days)
    duration_days: int = Field(..., ge=1, le=3650)

    # Crew manifest: at least 1, at most 12 members
    crew: List[CrewMember] = Field(..., min_length=1, max_length=12)

    # Current planning status; defaults to "planned"
    mission_status: str = Field(default="planned")

    # Approved budget in millions of USD: 1.0 to 10 000.0
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate_mission_safety(self) -> "SpaceMission":
        """Enforce crew and mission safety requirements."""

        # Rule 1: mission_id must carry the "M" prefix
        if not self.mission_id.startswith("M"):
            raise ValueError('Mission ID must start with "M"')

        # Rule 2: at least one senior officer must be aboard
        senior_ranks = {Rank.captain, Rank.commander}
        has_senior = any(m.rank in senior_ranks for m in self.crew)
        if not has_senior:
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )

        # Rule 3: long missions need a majority of experienced crew
        if self.duration_days > 365:
            experienced = sum(
                1 for m in self.crew if m.years_experience >= 5
            )
            ratio = experienced / len(self.crew)
            if ratio < 0.5:
                raise ValueError(
                    "Long missions (> 365 days) require at least 50 % "
                    "of crew with 5+ years of experience"
                )

        # Rule 4: no inactive crew members may join a mission
        inactive = [m.name for m in self.crew if not m.is_active]
        if inactive:
            raise ValueError(
                f"All crew members must be active. "
                f"Inactive: {', '.join(inactive)}"
            )

        return self


def main() -> None:
    """
    Demonstrate a valid mission with nested crew and an expected error.
    """
    print("Space Mission Crew Validation")
    print("=" * 41)

    # --- Build valid crew members ---
    commander = CrewMember(
        member_id="CM001",
        name="Sarah Connor",
        rank=Rank.commander,
        age=42,
        specialization="Mission Command",
        years_experience=18,
    )

    navigator = CrewMember(
        member_id="CM002",
        name="John Smith",
        rank=Rank.lieutenant,
        age=35,
        specialization="Navigation",
        years_experience=10,
    )

    engineer = CrewMember(
        member_id="CM003",
        name="Alice Johnson",
        rank=Rank.officer,
        age=29,
        specialization="Engineering",
        years_experience=6,
    )

    # --- Valid mission ---
    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date="2024-07-20T08:30:00",
        duration_days=900,
        crew=[commander, navigator, engineer],
        budget_millions=2500.0,
    )

    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(
            f"  - {member.name} ({member.rank.value})"
            f" - {member.specialization}"
        )

    print("=" * 41)

    # --- Invalid mission: no Commander or Captain ---
    cadet_only = CrewMember(
        member_id="CM099",
        name="Bob Cadet",
        rank=Rank.cadet,
        age=22,
        specialization="Maintenance",
        years_experience=0,
    )

    try:
        SpaceMission(
            mission_id="M2024_BAD",
            mission_name="Doomed Mission",
            destination="Venus",
            launch_date="2024-09-01T06:00:00",
            duration_days=30,
            crew=[cadet_only],   # violates the senior-officer rule
            budget_millions=50.0,
        )
    except ValidationError as error:
        print("Expected validation error:")
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
