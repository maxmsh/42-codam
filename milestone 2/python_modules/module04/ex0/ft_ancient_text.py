import sys

if __name__ == "__main__":
    argc: int = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            print("=== Cyber Archives Recovery ===")
            print(f"Accessing file '{filename}'")

            if "/etc/" in filename:
                raise PermissionError(f"[Errno 13] Permission denied: "
                                      f"'{filename}'")

            f = open(filename, "r")
            print("---\n\n")
            content: str = f.read()
            print(content)
            print("---")
            f.close()
            print(f"File '{filename}' closed.")

        except FileNotFoundError as e:
            print(f"Error opening file '{filename}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{filename}': {e}")
    else:
        print("Usage: ft_ancient_text.py <file>")