import sys

if __name__ == "__main__":
    argc = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            print("=== Cyber Archives Recovery & Preservation ===")
            print(f"Accessing file '{filename}'")

            with open(filename, "r") as file:
                content = file.read()
            
            print("---\n")
            print(content)
            print("---")
            print(f"File '{filename}' closed.\n")

            print("Transform data: ")
            print("---\n")

            lines = content.rstrip("\n").split("\n")

            newlines = []
            for line in lines:
                newlines.append(line + "#")
            
            new_content = "\n".join(newlines)

            print(new_content)
            print("\n---")

            save = input("Enter new file name (or empty): ")

            if save == "":
                print("Not saving data.")
            else:
                with open(save, "w") as file:
                    file.write(new_content)

        except FileNotFoundError as e:
            print(f"Error opening file: '{filename}': {e}")
        
    else:
        print("Usage ft_archive_creation.py <file>")