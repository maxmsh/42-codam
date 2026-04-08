import sys


if __name__ == "__main__":

    program_name = sys.argv[0]
    scores = list(map(int, sys.argv[1:]))
    players = len(scores)
    total = sum(scores)
    average = total / players
    maximum = max(scores)
    minimum = min(scores)
    range = maximum - minimum

    print("=== Player Score Analytics ===")
    try:
        if players >= 2:
            print(f"Scores processed: {scores}")
            print(f"Total players: {players}")
            print(f"Total score: {total}")
            print(f"Average score: {average}")
            print(f"High score: {maximum}")
            print(f"Low score: {minimum}")
            print(f"Score range: {range}")
        else:
            print(f"No scores provided. Usage: python3 {program_name} <score1> <score2>")
    except:
        for score in scores:
            raise ValueError(f"Invalid parameter: {score}")