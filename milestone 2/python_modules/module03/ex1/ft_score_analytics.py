import sys
name = sys.argv[0]
scores = sys.argv[1:]
argc = len(sys.argv)
players = argc - 1

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    try:
        if argc > 2:
            total = 0

            for score in scores:
                total += int(score)

            average = total / players
            print(f"Scores processed: {scores}")
            print(f"Total players: {players}")
            print(f"Total score: {total}")
            print(f"Average score: {average}")
            print(f"High score: {max(scores)}")
            print(f"Low score: {min(scores)}")
        elif argc <= 3:
            print(f"No scores provided. Usage: python3 {name} <score1> <score2>")
    except:
        raise ValueError("Invalid input!")