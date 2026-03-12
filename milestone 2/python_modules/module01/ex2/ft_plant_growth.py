class Plant:
    def __init__(self, n, h, a):
        self.name = n
        self.height = h
        self.age = a


plantObj1 = Plant("Rose", 25, 30)
plantObj2 = Plant("Lily", 5, 2)
plantObj3 = Plant("Apple tree", 450, 675)


def ft_plant_growth():
    startheight1 = plantObj1.height

    i = 1
    while i <= 7:
        print(f"=== Day {i} ===")
        print(f"{plantObj1.name}: {plantObj1.height}cm, {plantObj1.age} days old")
        print(f"{plantObj2.name}: {plantObj2.height}cm, {plantObj2.age} days old")
        print(f"{plantObj3.name}: {plantObj3.height}cm, {plantObj3.age} days old")
        print()

        plantObj1.height += 1
        plantObj2.height += 1
        plantObj3.height += 1
        plantObj1.age += 1
        plantObj2.age += 1
        plantObj3.age += 1
        i += 1

    print(f"Growth this week: {plantObj1.height - startheight1}cm")


if __name__ == "__main__":
    ft_plant_growth()
