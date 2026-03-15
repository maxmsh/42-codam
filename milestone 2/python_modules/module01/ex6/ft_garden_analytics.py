class Plant:
    def __init__(self, name, height):
        self.name = name
        self.height = height
        self.growth = 0

    def grow(self):
        self.growth += 1
        print(f"{self.name} grew 1cm")

    def get_height(self):
        return self.height + self.growth

    def get_growth(self):
        return self.growth

    def get_points(self):
        return self.height + self.growth

    def info(self):
        print(f"- {self.name}: {self.get_height()}cm", end="")


class FloweringPlant(Plant):
    def __init__(self, name, height, color):
        super().__init__(name, height)
        self.color = color

    def info(self):
        super().info()
        print(f", {self.color} flowers (blooming)", end="")


class PrizeFlower(FloweringPlant):
    def __init__(self, name, height, color, points):
        super().__init__(name, height, color)
        self.points = points

    def get_points(self):
        return self.get_height() + self.points * 4

    def info(self):
        super().info()
        print(f", prize points: {self.points}")


class Garden:
    def __init__(self, owner):
        self.owner = owner
        self._plants = []

    def add_plant(self, plant):
        print(f"Added {plant.name} to {self.owner}'s garden")
        self._plants.append(plant)

    def grow_plants(self):
        print(f"\n{self.owner} is helping all plants grow...")
        for p in self._plants:
            p.grow()
        print()

    def get_plants(self):
        return self._plants


class GardenManager:
    def __init__(self):
        self._gardens = []

    @staticmethod
    def create_garden_network(gardeners):
        mgr = GardenManager()
        for name in gardeners:
            mgr.add_garden(name)
        return mgr

    def add_garden(self, name):
        self._gardens.append(Garden(name))

    def find_garden(self, name):
        for g in self._gardens:
            if g.owner == name:
                return g
        return None

    def add_plant(self, garden_name, plant):
        g = self.find_garden(garden_name)
        if g:
            g.add_plant(plant)

    def grow_plants(self, garden_name):
        g = self.find_garden(garden_name)
        if g:
            g.grow_plants()

    def get_scores(self):
        parts = []
        for g in self._gardens:
            score = sum(p.get_points() for p in g.get_plants())
            parts.append(f"{g.owner}: {score}")
        print("Garden scores - " + ", ".join(parts))

    def get_gardencount(self):
        print(f"Total gardens managed: {len(self._gardens)}")

    class GardenStats:
        @staticmethod
        def report(garden):
            print(f"\n=== {garden.owner}'s Garden Report ===\n")
            GardenManager.GardenStats.get_plants(garden)
            GardenManager.GardenStats.get_plant_stats(garden)
            GardenManager.GardenStats.get_plant_types(garden)
            GardenManager.GardenStats.validate_heights(garden)
            print()

        @staticmethod
        def get_plants(garden):
            print("Plants in garden:")
            for p in garden.get_plants():
                p.info()
                print()
            print()

        @staticmethod
        def get_plant_stats(garden):
            plants = garden.get_plants()
            total_growth = sum(p.get_growth() for p in plants)
            print(
                f"Plants added: {len(plants)}, "
                f"total growth: {total_growth}cm"
            )

        @staticmethod
        def get_plant_types(garden):
            regular = flowering = prize = 0
            for p in garden.get_plants():
                if isinstance(p, PrizeFlower):
                    prize += 1
                elif isinstance(p, FloweringPlant):
                    flowering += 1
                else:
                    regular += 1
            print(
                f"Plant types: {regular} regular, "
                f"{flowering} flowering, "
                f"{prize} prize flowers"
            )

        @staticmethod
        def validate_heights(garden):
            ok = all(p.get_height() >= 0 for p in garden.get_plants())
            print(f"Height validation test: {ok}")


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")

    manager = GardenManager.create_garden_network(["Alice", "Bob"])

    manager.add_plant("Alice", Plant("Oak Tree", 100))
    manager.add_plant("Alice", FloweringPlant("Rose", 25, "red"))
    manager.add_plant("Alice", PrizeFlower("Sunflower", 50, "yellow", 10))
    manager.grow_plants("Alice")

    manager.add_plant("Bob", FloweringPlant("Rose", 92, "red"))

    alice_garden = manager.find_garden("Alice")
    if alice_garden:
        GardenManager.GardenStats.report(alice_garden)

    manager.get_scores()
    manager.get_gardencount()
