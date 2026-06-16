def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(
        artifacts,
        key=lambda a: a['power'],
        reverse=True
    )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda m: m['power'] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda s: f"* {s} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    return {
        'max_power': max(mages, key=lambda m: m['power'])['power'],
        'min_power': min(mages, key=lambda m: m['power'])['power'],
        'avg_power': round(
            sum(map(lambda m: m['power'], mages)) / len(mages), 2
        )
    }


if __name__ == "__main__":
    artifacts = [
        {'name': 'Crystal Orb', 'power': 85, 'type': 'orb'},
        {'name': 'Fire Staff', 'power': 92, 'type': 'staff'},
        {'name': 'Shadow Blade', 'power': 78, 'type': 'sword'},
    ]
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    first = sorted_artifacts[0]
    second = sorted_artifacts[1]
    print(
        f"{first['name']} ({first['power']} power)"
        f" comes before {second['name']}"
        f" ({second['power']} power)"
    )

    mages = [
        {'name': 'Aldric', 'power': 90, 'element': 'fire'},
        {'name': 'Sylva', 'power': 45, 'element': 'water'},
        {'name': 'Toryn', 'power': 70, 'element': 'earth'},
    ]
    print("\nTesting power filter...")
    strong_mages = power_filter(mages, 60)
    print(f"Mages with power >= 60: {[m['name'] for m in strong_mages]}")

    spells = ['fireball', 'heal', 'shield']
    print("\nTesting spell transformer...")
    print(*spell_transformer(spells))

    print("\nTesting mage stats...")
    stats = mage_stats(mages)
    print(
        f"Max: {stats['max_power']},"
        f" Min: {stats['min_power']},"
        f" Avg: {stats['avg_power']}"
    )
