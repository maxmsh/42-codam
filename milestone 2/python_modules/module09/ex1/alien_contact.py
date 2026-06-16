"""
Exercise 1: Alien Contact Logs
Demonstrates custom cross-field validation using @model_validator.
"""

from datetime import datetime
from enum import Enum
from typing import Optional

from pydantic import BaseModel, Field, ValidationError, model_validator


class ContactType(str, Enum):
    """The four recognised categories of alien contact."""

    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    """
    Validates alien contact reports received by the Observatory.

    Business rules enforced by the model validator:
    - contact_id must start with "AC"
    - physical contact reports must be verified
    - telepathic contact requires at least 3 witnesses
    - signal strength above 7.0 requires a received message
    """

    # Unique report identifier: 5 to 15 characters
    contact_id: str = Field(..., min_length=5, max_length=15)

    # Exact moment of contact
    timestamp: datetime

    # Where the contact occurred: 3 to 100 characters
    location: str = Field(..., min_length=3, max_length=100)

    # Category of contact
    contact_type: ContactType

    # Signal intensity on a 0.0–10.0 scale
    signal_strength: float = Field(..., ge=0.0, le=10.0)

    # How long the contact lasted: 1 minute to 24 hours (1440 minutes)
    duration_minutes: int = Field(..., ge=1, le=1440)

    # Number of people who witnessed the contact: 1 to 100
    witness_count: int = Field(..., ge=1, le=100)

    # Text of any message received, optional and capped at 500 characters
    message_received: Optional[str] = Field(default=None, max_length=500)

    # Whether this report has been independently verified; defaults to False
    is_verified: bool = Field(default=False)

    @model_validator(mode="after")
    def validate_business_rules(self) -> "AlienContact":
        """
        Apply cross-field business rules after individual field
        validation.
        """

        # Rule 1: contact_id must begin with the "AC" prefix
        if not self.contact_id.startswith("AC"):
            raise ValueError('Contact ID must start with "AC" (Alien Contact)')

        # Rule 2: physical contact must have been independently verified
        if self.contact_type == ContactType.physical and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")

        # Rule 3: telepathic contact is only credible with at least 3 witnesses
        if (
            self.contact_type == ContactType.telepathic
            and self.witness_count < 3
        ):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )

        # Rule 4: strong signals (> 7.0) should carry a decoded message
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError(
                "Strong signals (> 7.0)" "should include received messages"
            )

        return self


def main() -> None:
    """
    Demonstrate a valid contact report and expected validation errors.
    """
    print("Alien Contact Log Validation")
    print("=" * 38)

    # --- Valid contact report ---
    contact = AlienContact(
        contact_id="AC_2024_001",
        timestamp="2024-11-15T03:47:00",
        location="Area 51, Nevada",
        contact_type=ContactType.radio,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
        is_verified=True,
    )

    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    print(f"Message: '{contact.message_received}'")

    print("=" * 38)

    # --- Invalid report: telepathic with only 1 witness ---
    try:
        AlienContact(
            contact_id="AC_BAD_001",
            timestamp="2024-11-16T01:00:00",
            location="Roswell, New Mexico",
            contact_type=ContactType.telepathic,
            signal_strength=5.0,
            duration_minutes=10,
            witness_count=1,  # violates the 3-witness rule
            is_verified=False,
        )
    except ValidationError as error:
        print("Expected validation error:")
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
