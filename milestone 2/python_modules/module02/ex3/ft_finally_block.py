def water_plants(plant_list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            print(f"Watering {plant}")
    except TypeError:
        print(f"Error: can't water {plant} - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")
    print("Watering completed successfully!\n")

def test_watering_system():
    for label, plants in [("normal", ["tomato", "lettuce", "carrots"]), ("error", ["tomato", None, "carrots"])]:
        print(f"Testing {label} watering...")
        water_plants(plants)

if __name__ == "__main__":
    print("=== Garden Watering System ===")
    test_watering_system()
    print("Cleanup always happens, even with errors!")