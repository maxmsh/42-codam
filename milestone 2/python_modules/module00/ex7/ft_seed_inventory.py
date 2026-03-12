def ft_seed_inventory(seed_type: str, quantity: int, unit: str):
    seed_type = seed_type.capitalize()
    if unit == "packets":
        print(f"{seed_type} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{seed_type} seeds: {quantity} {unit} total")
    elif unit == "area":
        unit = "square meters"
        print(f"{seed_type} seeds: covers {quantity} {unit}")
    else:
        print("Unknown unit type")


ft_seed_inventory("grams", 12, "")
