
import random
import sys

from config_parser import parse_config
from insert_42_mark import forty_two_mark
from maze_gen import gt_maze_gen, hk_maze_gen


# class Maze:
#     def __init__(self, height: int, width: int, entry: tuple[int, int],
#                  exit: tuple[int, int], perfect: bool, seed: int) -> None:
#         if width <= 0:
#             raise ValueError("Error: Width has to be 1 or larger.")
#         if height <= 0:
#             raise ValueError("Error: Height has to be 1 or larger.")

#         self.width = width
#         self.height = height
#         self.perfect = perfect
#         self.seed = seed
#         self.x = 0
#         self.y = 0
#         self.list_dict = {}
#         self.locked_cells: set[tuple[int, int]] = set()

#         self.entry = self.coord_val(entry, name="Entry")
#         self.exit = self.coord_val(exit, name="Exit")
#         if self.entry == self.exit:
#             raise ValueError("Error: Entry and Exit cannot be the same.")

#         if not seed:
#             random.seed(self.seed)
#             self.generate()

#     def _boundry_check(self, coord: tuple[int, int]) -> bool:
#         x, y = coord
#         return 0 <= x < self.width and 0 <= y < self.height

#     def _validate_coord(self, coord: tuple[int, int],
#                         name: str = "coordinate") -> tuple[int, int]:
#         if not self._in_bounds(coord):
#             raise ValueError(f"Error: {name} {coord} is out of bounds.")
#         return coord

#     def _make_grid(self) -> dict:
#         grid: dict = {}
#         for row in range(self.height):
#             grid[row] = {}
#             for col in range(self.width):
#                 # Bit layout: N=0b1000  S=0b0100  E=0b0010  W=0b0001
#                 grid[row][col] = {"visited": False, "walls": 0b1111}
#         return grid

#     def select(self) -> str:
#         choice = []
#         x, y = self.x, self.y
#         if x > 0 and not self.list_dict[y][x - 1]["visited"]:
#             choice.append("W")
#         if x < self.width - 1 and not self.list_dict[y][x + 1]["visited"]:
#             choice.append("E")
#         if y > 0 and not self.list_dict[y - 1][x]["visited"]:
#             choice.append("N")
#         if y < self.height - 1 and not self.list_dict[y + 1][x]["visited"]:
#             choice.append("S")
#         if not choice:
#             return "not_found"
#         return random.choice(choice)


# ALGORITHMS = {
#     "gt": gt_maze_gen,
#     "hk": hk_maze_gen,
# }


# def generate(maze: Maze, alg: str) -> None:
#     alg_fn = ALGORITHMS.get(alg)
#     if alg_fn is None:
#         known = ", ".join(ALGORITHMS.keys())
#         raise ValueError(
#             f"Unknown algorithm '{alg}'. Known algorithms: {known}"
#         )
#     random.seed(maze.seed)
#     alg_fn(maze)


# def main(argv: list[str]) -> int:
#     if len(argv) != 2:
#         print("Error: No valid arguments.\nRun program with config.txt")
#         return 2

#     config_path = argv[1]

#     try:
#         cfg = parse_config(config_path)
#     except FileNotFoundError:
#         print(f"Error: Config file not found: {config_path!r}")
#         return 1
#     except ValueError as e:
#         print(e)
#         return 1

#     try:
#         maze = Maze(
#             height=cfg.height,
#             width=cfg.width,
#             entry=cfg.entry,
#             exit=cfg.exit,
#             perfect=cfg.perfect,
#             seed=cfg.seed,
#         )
#         maze.locked_cells = forty_two_mark(maze)
#         generate(maze, cfg.alg)
#     except ValueError as e:
#         print(e)
#         return 1


# if __name__ == "__main__":
#     main(sys.argv)

class Maze:
    def __init__(
        self,
        width: int,
        height: int,
        entry: tuple[int, int],
        exit: tuple[int, int],
        perfect: bool,
        seed: int,
    ) -> None:
        if width <= 0:
            raise ValueError("Error: Width has to be 1 or larger.")
        if height <= 0:
            raise ValueError("Error: Height has to be 1 or larger.")

        # Bug 1 was hier: self.width = height (height ipv width)
        self.width = width
        self.height = height
        self.perfect = perfect
        self.seed = seed

        # Bug 2+3: coord_val en boundry_check waren geneste functies
        # die ná hun aanroep werden gedefinieerd, en ten onrechte 'self'
        # als parameter hadden. Ze zijn nu gewone class-methoden geworden.
        self.entry = self.coord_val(entry, name="Entry")
        self.exit = self.coord_val(exit, name="Exit")

        if self.entry == self.exit:
            raise ValueError("Error: Entry and Exit cannot be the same.")

    def boundry_check(self, coord: tuple[int, int]) -> bool:
        x, y = coord
        if x < 0 or x >= self.width:
            return False
        if y < 0 or y >= self.height:
            return False
        return True

    def coord_val(self, coord: tuple[int, int], name: str = "coordinate") -> tuple[int, int]:
        if not self.boundry_check(coord):
            raise ValueError(f"Error: {name} is out of bounds.")
        # Bug 3 was ook: coord_val gaf niks terug (geen return)
        return coord


if __name__ == "__main__":
    pass
