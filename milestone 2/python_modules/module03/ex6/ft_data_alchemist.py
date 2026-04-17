import random

if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")

    players = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma', 'Gregory', 'john', 'kevin', 'Liam']
    print(f"Initial list of players: {players}")

    all_capitalized = [name.capitalize() for name in players]
    print(f"New list with all names capitalized: {all_capitalized}")

    only_capitalized = [name for name in players if name[0].isupper()]
    print(f"New list of capitalized names only: {only_capitalized}")

    score_dict = {name: random.randint(0, 1000) for name in all_capitalized}
    print(f"Score dict: {score_dict}")

    average = round(sum(score_dict.values()) / len(score_dict), 2)
    print(f"Score average is {average}")

    high_scores = {name: score for name, score in score_dict.items() if score > average}
    print(f"High scores: {high_scores}")