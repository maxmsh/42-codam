import random

def gen_player_achievements():
    achievement_list: list = [
        'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner', 'Survivor',
        'Master Explorer', 'Treasure Hunter', 'Unstoppable', 'First Steps',
        'Collector Supreme', 'Untouchable', 'Sharp Mind', 'Boss Slayer', 'Hidden Path Finder'
    ]
    count: int = random.randint(1, len(achievement_list))
    return set(random.sample(achievement_list, k=count))


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")

    players: dict = {
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements(),
    }

    for name, achievements in players.items():
        print(f"Player {name}: {achievements}")

    all_achievements: set = set().union(*players.values())
    print(f"\nAll distinct achievements: {all_achievements}")

    common: set = set.intersection(*players.values())
    print(f"Common achievements: {common}")

    print()
    for name, achievements in players.items():
        others: set = set.union(*[ach for n, ach in players.items() if n != name])
        print(f"Only {name} has: {achievements.difference(others)}")

    print()
    for name, achievements in players.items():
        print(f"{name} is missing: {all_achievements.difference(achievements)}")