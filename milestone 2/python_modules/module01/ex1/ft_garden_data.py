class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


plantObj1 = Plant("Rose", 25, 30)
plantObj2 = Plant("Lily", 5, 2)
plantObj3 = Plant("Apple tree", 450, 675)

if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    print(f"{plantObj1.name}: {plantObj1.height}cm, {plantObj1.age} days old")
    print(f"{plantObj2.name}: {plantObj2.height}cm, {plantObj2.age} days old")
    print(f"{plantObj3.name}: {plantObj3.height}cm, {plantObj3.age} days old")
