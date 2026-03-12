class Plant:
    def __init__(self, n, h, a):
        self.name = n
        self.height = h
        self.age = a


class SecurePlant(Plant):
    def __init__(self, n, h, a):
        super().__init__(n, h, a)

    def get_height(self):
        return self.height

    def get_age(self):
        return self.age

    def set_height(self, new_height):
        if new_height <= 0:
            print(f"Invalid operation attempted: height {new_height}cm [REJECTED]")
            print("Security: Negative height rejected")
        elif new_height >= 0:
            self.height = new_height
            print(f"Height updated: {new_height}cm [OK]")

    def set_age(self, new_age):
        if new_age <= 0:
            print(f"Invalid operation attempted: {new_age} days [REJECTED]")
            print("Security: Negative age rejected")
        elif new_age >= 0:
            self.age = new_age
            print(f"Age updated: {new_age} days [OK]")

    def print_info(self):
        print(f"Current plant: {self.name} ({self.height}cm, {self.age} days)")


if __name__ == "__main__":
    rose = SecurePlant("Rose", 1, 1)
    print("=== Garden Security System ===")
    print(f"Plant created: {rose.name}")
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    print()
    rose.print_info()
