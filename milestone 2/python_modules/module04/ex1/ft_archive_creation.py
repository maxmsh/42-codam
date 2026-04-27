import sys

if __name__ == "__main__":
    argc: int = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            if "/etc/" in filename:
                raise PermissionError(f"[Errno 13] Permission denied: "
                                      f"'{filename}'")

            print("=== Cyber Archives Recovery & Preservation ===")
            print(f"Accessing file '{filename}'")

            with open(filename, "r") as file:
                content: str = file.read()
            
            print("---\n")
            print(content)
            print("---")
            print(f"File '{filename}' closed.\n")

            print("Transform data: ")
            print("---\n")

            lines: list = content.rstrip("\n").split("\n")

            newlines: list = []
            for line in lines:
                newlines.append(line + "#")
            
            new_content: str = "\n".join(newlines)

            print(new_content)
            print("\n---")

            save: str = input("Enter new file name (or empty): ")

            if save == "":
                print("Not saving data.")
            else:
                with open(save, "w") as file:
                    file.write(new_content)

        except FileNotFoundError as e:
            print(f"Error opening file '{filename}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{filename}': {e}")
        
    else:
        print("Usage ft_archive_creation.py <file>")