from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1.capabilities import HealCapability, TransformCapability


def test_healing(factory: HealingCreatureFactory) -> None:
    print("Testing Creature with healing capability")
    for label, creature in [
        ("base", factory.create_base()),
        ("evolved", factory.create_evolved()),
    ]:
        print(f" {label}:")
        print(creature.describe())
        print(creature.attack())
        if isinstance(creature, HealCapability):
            print(creature.heal())


def test_transform(factory: TransformCreatureFactory) -> None:
    print("Testing Creature with transform capability")
    for label, creature in [
        ("base", factory.create_base()),
        ("evolved", factory.create_evolved()),
    ]:
        print(f" {label}:")
        print(creature.describe())
        print(creature.attack())
        if isinstance(creature, TransformCapability):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())


heal_factory = HealingCreatureFactory()
transform_factory = TransformCreatureFactory()

test_healing(heal_factory)
print()
test_transform(transform_factory)
