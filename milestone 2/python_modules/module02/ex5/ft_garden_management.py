class GardenError(Exception): pass
class PlantError(GardenError): pass
class WaterError(GardenError): pass

class GardenManager:
    def __init__(self):
        self.plants = {}

    def add_plant(self, name):
        if not name:
            raise PlantError("Plant name cannot be empty!")
        self.plants[name] = {"water": 5, "sun": 8}
        print(f"Added {name} successfully!")

    def water_plants(self):
        print("Opening watering system")
        for plant in self.plants:
            print(f"Watering {plant} - success")
            self.plants[plant]["water"] += 1
        print("closing watering system (cleanup)\n")

    def check_health(self, name):
        if name not in self.plants:
            raise PlantError(f"{name} not found in garden!")
        if self.plants[name]["water"] > 10:
            raise WaterError(f"Water level {self.plants[name]['water']} is too high (max 10)")
        print(f"{name}: healthy (water: {self.plants[name]['water']}, sun: {self.plants[name]['sun']})")

def check_garden_management():
    print("=== Garden Management System ===\n")
    manager = GardenManager()
    print("Adding plants to garden...")
    try:
        for name in ["tomato", "lettuce", ""]:
            manager.add_plant(name)
    except PlantError as e:
        print(f"Error adding plant: {e}\n")
    print("Watering plants...")
    manager.water_plants()
    print("Checking plant health...")
    manager.plants["lettuce"]["water"] = 15
    for plant in ["tomato", "lettuce"]:
        try:
            manager.check_health(plant)
        except WaterError as e:
            print(f"Error checking {plant}: {e}\n")
    print("Testing error recovery...")
    try:
        raise WaterError("Not enough water in tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print("System recovered and continuing...")
    print("\nGarden management system test complete!")

if __name__ == "__main__":
    check_garden_management()
