import sys

if __name__ == "__main__":
    argc: int = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            print("=== Cyber Archives Recovery ===")
            print(f"Accessing file '{filename}'")
            with open(filename, "r") as file:
                print("---\n\n")
                content = file.read()
                print(content)
                print("---")
                print(f"File '{filename}' closed.")
        except FileNotFoundError as e:
            print(f"Error opening file '{filename}': {e}")
    else:
        print("Usage: ft_ancient_text.py <file>")