import sys

if __name__ == "__main__":
    argc: int = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            print("=== Cyber Archives Recovery & Preservation ===")
            print(f"Accessing file '{filename}'")

            if "/etc/" in filename:
                raise PermissionError(f"[Errno 13] Permission denied: "
                                      f"'{filename}'")

            f = open(filename, "r")
            print("---\n\n")
            content: str = f.read()
            print(content)
            print("\n\n---")
            f.close()
            print(f"File '{filename}' closed.")

            print("\nTransform data: ")
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
            elif "/etc/" in save:
                raise PermissionError(f"[Errno 13] Permission denied: "
                                      f"'{save}'")
            else:
                print(f"Saving data to '{save}'")
                f = open(save, "w")
                f.write(new_content)
                f.close()
                print(f"Data saved in file '{save}'.")

        except FileNotFoundError as e:
            print(f"Error opening file '{filename}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{filename}': {e}")
        
    else:
        print("Usage ft_archive_creation.py <file>")