class Plant:
    def __init__(self, n, h, a):
        self.name = n
        self.height = h
        self.age = a


plant_one = Plant("Rose", 14, 7)
plant_two = Plant("Tulip", 4, 28)
plant_three = Plant("Marigold", 7, 61)
plant_four = Plant("Lily", 45, 146)
plant_five = Plant("Apple tree", 345, 12)


def ft_plant_factory():
    print("=== Plant Factory Output ===")
    print(f"Created: {plant_one.name}, ({plant_one.height}cm, {plant_one.age} days)")
    print(f"Created: {plant_two.name}, ({plant_two.height}cm, {plant_two.age} days)")
    print(f"Created: {plant_three.name}, ({plant_three.height}cm, {plant_three.age} days)")
    print(f"Created: {plant_four.name}, ({plant_four.height}cm, {plant_four.age} days)")
    print(f"Created: {plant_five.name}, ({plant_five.height}cm, {plant_five.age} days)")
    print()
    print("Total plants created: 5")


if __name__ == "__main__":
    ft_plant_factory()
