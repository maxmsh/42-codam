from alchemy.elements import create_air  # absolute import
from ..potions import strength_potion    # relative import
from elements import create_fire         # absolute import (root module)


def lead_to_gold() -> str:
    return (
        f"Recipe transmuting Lead to Gold: brew '{create_air()}'"
        f" and '{strength_potion()}' mixed with '{create_fire()}'"
    )
