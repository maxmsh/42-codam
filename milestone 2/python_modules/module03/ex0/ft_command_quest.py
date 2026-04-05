import sys

if __name__ == "__main__":
    print("=== Command Quest ===")

    if len(sys.argv) == 1:
        print("No arguments provided!")
        print(f"Program name: {sys.argv[0]}")
        print(f"Total arguments: {len(sys.argv)}")

    elif len(sys.argv) > 1:
        print(f"Program name: {sys.argv[0]}")
        print(f"Arguments received: {len(sys.argv)}")

        i = 1
        for args in sys.argv[1:]:
            print(f"Argument {i}: {args}")
            i += 1

        print(f"Total arguments: {len(sys.argv)}")
        