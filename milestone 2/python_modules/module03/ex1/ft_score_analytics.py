import sys


if __name__ == "__main__":
    program_name = sys.argv[0]

    scores = []
    invalid_found = False

    for x in sys.argv[1:]:
        try:
            scores.append(int(x))
        except ValueError:
            print(f"Invalid parameter: '{x}'")
            invalid_found = True
    
    if invalid_found:
        print(f"No scores provided. Usage: python3 {program_name} <score1> <score2> ...")
        sys.exit(1)


    players = len(scores)

    if players < 2:
        print(f"No scores provided. Usage: python3 {program_name} <score1> <score2> ...")
        sys.exit(1)
    
    total = sum(scores)
    average = total / players
    maximum = max(scores)
    minimum = min(scores)
    score_range = maximum - minimum

    print("=== Player Score Analytics ===")
    print(f"Scores processed: {scores}")
    print(f"Total players: {players}")
    print(f"Total score: {total}")
    print(f"Average score: {average}")
    print(f"High score: {maximum}")
    print(f"Low score: {minimum}")
    print(f"Score range: {score_range}")