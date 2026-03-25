def check_temperature(temp_str) -> int:
    print(f"\nTesting temperature: {temp_str}")
    try:
        if not isinstance(temp_str, str):
            typecasted = int(temp_str)
        else:
            typecasted = int(temp_str)

        if typecasted > 40:
            raise ValueError("hot")
        elif typecasted < 0:
            raise ValueError("cold")
        else:
            print(f"{typecasted}°C is perfect for plants!")

    except ValueError as e:
        if str(e) == "hot":
            print(f"{typecasted}°C is too hot for plants (max 40°C)")
        elif str(e) == "cold":
            print(f"{typecasted}°C is too cold for plants (min 0°C)")
        else:
            print(f"{temp_str} is not a valid number")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    print("")
    check_temperature("25")
    print("")
    check_temperature("abc")
    print("")
    check_temperature("100")
    print("")
    check_temperature("-50")
    print("")
    print("All tests completed - program didn't crash!")
