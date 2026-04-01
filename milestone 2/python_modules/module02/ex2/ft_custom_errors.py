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
    raise GardenError("garden", "The tomato plant is wilting!")

def check_garden_again():
    raise GardenError("garden", "Not enough water in the tank!")

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
    print("Testing catching all garden errors...")
    
    for func in [check_garden, check_garden_again]:
        try:
            func()
        except GardenError as e:
            print(f"Caught a {e.name} error: {e.desc}")
        

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")
    custom_garden_errors()
    print("\nAll custom error types work correctly!")