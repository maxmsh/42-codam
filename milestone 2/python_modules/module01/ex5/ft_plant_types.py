import math


class Plant:
    def __init__(self, n, h, a):
        self.name = n
        self.height = h
        self.age = a

    def print_info(self):
        class_name = self.__class__.__name__
        print(f"{self.name} ({class_name}): {self.height} cm, ", end="")
        print(f"{self.age} days old ", end="")


class Flower(Plant):
    def __init__(self, n, h, a):
        super().__init__(n, h, a)
        self.color = "red"
        self.is_blooming = True

    def print_info(self):
        super().print_info()
        print(f"{self.color} color")
        self.check_blooming()

    def check_blooming(self):
        if self.is_blooming:
            print(f"{self.name} is blooming beautifully!")
        else:
            print(f"{self.name} is not ready yet!")


class Tree(Plant):
    def __init__(self, n, h, a):
        super().__init__(n, h, a)
        self.trunk_diameter = 50.0

    def produce_shade(self):
        shade_area = (self.trunk_diameter ** 2 * math.pi) / 4
        print(f"{self.name} provides {shade_area:.2f} square meters of shade")

    def print_info(self):
        super().print_info()
        print(f"{self.trunk_diameter} cm diameter")


class Vegetable(Plant):
    def __init__(self, n, h, a):
        super().__init__(n, h, a)
        self.harvest_season = "summer "
        self.nutritional_value = "is rich in vitamin C"

    def print_info(self):
        super().print_info()
        print(f"{self.harvest_season} harvest")

    def print_message(self):
        print(f"{self.name} {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===\n")

    rose = Flower("Rose", 25, 30)
    oak = Tree("Oak", 500, 1825)
    tomato = Vegetable("Tomato", 80, 90)

    rose.print_info()
    oak.print_info()
    oak.produce_shade()
    tomato.print_message()
    tomato.print_info()
