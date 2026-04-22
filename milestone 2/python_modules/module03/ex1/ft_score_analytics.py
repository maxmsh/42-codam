import sys


if __name__ == "__main__":
    program_name: str = sys.argv[0]

    scores: list = []
    invalid_found: bool = False

    for x in sys.argv[1:]:
        try:
            scores.append(int(x))
        except ValueError:
            print(f"Invalid parameter: '{x}'")
            invalid_found = True
    
    if invalid_found:
        print(f"No scores provided. Usage: python3 {program_name} <score1> <score2> ...")
        sys.exit(1)


    players: int = len(scores)

    if players < 2:
        print(f"No scores provided. Usage: python3 {program_name} <score1> <score2> ...")
        sys.exit(1)
    
    total: int = sum(scores)
    average: float = total / players
    maximum: int = max(scores)
    minimum: int = min(scores)
    score_range: int = maximum - minimum

    print("=== Player Score Analytics ===")
    print(f"Scores processed: {scores}")
    print(f"Total players: {players}")
    print(f"Total score: {total}")
    print(f"Average score: {average}")
    print(f"High score: {maximum}")
    print(f"Low score: {minimum}")
    print(f"Score range: {score_range}")