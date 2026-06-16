from typing import List, Tuple
from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    BattleStrategy,
    NormalStrategy,
    AggressiveStrategy,
    DefensiveStrategy,
)

Opponent = Tuple[CreatureFactory, BattleStrategy]


def battle(opponents: List[Opponent]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            factory_a, strategy_a = opponents[i]
            factory_b, strategy_b = opponents[j]
            creature_a = factory_a.create_base()
            creature_b = factory_b.create_base()

            print()
            print("* Battle *")
            print(creature_a.describe())
            print(" vs.")
            print(creature_b.describe())
            print(" now fight!")

            try:
                strategy_a.act(creature_a)
                strategy_b.act(creature_b)
            except ValueError as e:
                print(f"Battle error, aborting tournament: {e}")
                return


normal = NormalStrategy()
aggressive = AggressiveStrategy()
defensive = DefensiveStrategy()

flame = FlameFactory()
aqua = AquaFactory()
healing = HealingCreatureFactory()
transform = TransformCreatureFactory()

print("Tournament 0 (basic)")
print(" [ (Flameling+Normal), (Healing+Defensive) ]")
battle([(flame, normal), (healing, defensive)])

print()
print("Tournament 1 (error)")
print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")
battle([(flame, aggressive), (healing, defensive)])

print()
print("Tournament 2 (multiple)")
print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
battle([(aqua, normal), (healing, defensive), (transform, aggressive)])
