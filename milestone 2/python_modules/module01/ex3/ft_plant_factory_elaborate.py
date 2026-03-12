class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


def ft_plant_factory():
    amount = int(input("How many plants would you like to create? "))

    plants = []

    for i in range(amount):
        print(f"\nPlant {i + 1}")
        name = input("Name: ")
        height = int(input("Height: "))
        age = int(input("Age: "))
        plant = Plant(name, height, age)
        plants.append(plant)

    print("=== Plant Factory Output ===")
    for plant in plants:
        print(f"Created: {plant.name} ({plant.height}cm, {plant.age} days)")
    print(f"Total plants created: {len(plants)}")


if __name__ == "__main__":
    ft_plant_factory()
