def check_plant_health(plant_name: str, water_level: int, sunlight_hours: int):
    try:
        if not plant_name:
            raise ValueError("Plant name cannot be empty!")
    except ValueError as e:
        print(f"Error: {e}")
        return

    try:
        if water_level > 10:
            raise ValueError(
            f"Water level {water_level} is too high (max 10)")
        elif water_level < 1:
            raise ValueError(
            f"Water level {water_level} too low (min 1)")
    except ValueError as e:
        print(f"Error: {e}")

    try:
        if sunlight_hours > 12:
            raise ValueError(
                f"Sunlight hours {sunlight_hours} is too high (max 12)")
        elif sunlight_hours < 2:
            raise ValueError(
                f"Sunlight hours {sunlight_hours} is too low (min 2)")
    except ValueError as e:
        print(f"Error: {e}")

    if ((water_level <= 10 and water_level >= 1)
    and (sunlight_hours <= 12 and sunlight_hours >= 2)
    and (plant_name is not None)):
        print(f"Plant '{plant_name}' is healthy!")


def test_plant_checks():
    print("\nTesting good values...")
    check_plant_health("tomato", 4, 8)
    print("\nTesting empty plant name...")
    check_plant_health("", 8, 4)
    print("\nTesting bad water level...")
    check_plant_health("apple", 15, 6)
    print("\nTesting bad sunlight hours...")
    check_plant_health("rosemary", 7, 0)


if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===")
    test_plant_checks()
    print("\nAll error raising tests completed!")