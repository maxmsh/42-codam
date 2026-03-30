class GardenError(Exception):
    def __init__(self, name: str, msg: str):
        self.name = "Garden"
        self.msg = print("The tomato plant is wilting!")


class PlantError(GardenError):
    def __init__(self, name, msg):
        self.name = "Plant"
        self.subname = "tomato"
        super().__init__("Something went wrong with a plant.")
        
class WaterError(GardenError):
    def __init__(self, name, msg):
        self.name = "Water"
        super().__init__("Something went wrong with water.")
        
def custom_garden_errors():
    try:
        raise PlantError()
    except GardenError as e:
        print(f"Caught {e.name}Error: {e.desc}")

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    custom_garden_errors("tomato")
    print("All custom error types work correctly!")