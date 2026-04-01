class GardenError(Exception):
    def __init__(self, name: str, desc: str):
        self.name = name
        self.desc = desc
        super().__init__(desc)
    pass


class PlantError(GardenError):
    pass
        
class WaterError(GardenError):
    pass
        
def check_garden():
    raise GardenError("Garden", "The tomato plant is wilting!")

def check_plant():
    raise PlantError("Plant", "The tomato plant is wilting!")

def check_water():
    raise WaterError("Water", "Not enough water in the tank!")

def custom_garden_errors():
    try:
        check_plant()
    except PlantError as e:
            print(f"\nTesting {e.name}Error...\nCaught {e.name}Error: {e.desc}\n")
    try:
        check_water()
    except WaterError as e:
            print(f"\nTesting {e.name}Error...\nCaught {e.name}Error: {e.desc}\n")

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")
    custom_garden_errors()
    print("All custom error types work correctly!")