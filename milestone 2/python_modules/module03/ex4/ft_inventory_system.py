import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===\n")

    inventory: dict = {}

    for param in sys.argv[1:]:
        if ':' not in param:
            print(f"Error - invalid parameter '{param}'")
            continue

        parts: list = param.split(':')
        if len(parts) != 2:
            print(f"Error - invalid parameter '{param}'")
            continue

        name, quantity = parts

        if name in inventory:
            print(f"Redundant item '{name}' - discarding")
            continue

        try:
            inventory[name] = int(quantity)
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")

    print(f"Got inventory: {inventory}")

    if len(inventory) == 0:
        print("No valid items in inventory.")
    else:
        item_list: list = list(inventory.keys())
        print(f"Item list: {item_list}")

        total: int = sum(inventory.values())
        print(f"Total quantity of the {len(inventory)} items: {total}")

        for name, qty in inventory.items():
            percentage: float = round(qty / total * 100, 1)
            print(f"Item {name} represents {percentage}%")

        most  = min(((k, i) for i, k in enumerate(inventory) if inventory[k] == max(inventory.values())), key=lambda x: x[1])[0]
        least = min(((k, i) for i, k in enumerate(inventory) if inventory[k] == min(inventory.values())), key=lambda x: x[1])[0]

        print(f"Item most abundant: {most} with quantity {inventory[most]}")
        print(f"Item least abundant: {least} with quantity {inventory[least]}")

        inventory.update({'magic_item': 1})
        print(f"Updated inventory: {inventory}")