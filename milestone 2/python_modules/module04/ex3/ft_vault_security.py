def secure_archive(isOkay: bool, filename: str):
    try:
        if "/etc/" in filename:
            raise PermissionError(f"[Errno 13] Permission denied: '{filename}'")

        try:
            with open(filename, "r") as file:
                content = file.read()

            lines = content.split("\n")
            new_content = "\n".join(line + "\\n" for line in lines if line)

            secure_archive.cached_content = new_content

            print(f"({isOkay}, '{new_content}')")

        except FileNotFoundError as e:
            if isOkay and hasattr(secure_archive, "cached_content"):
                with open(filename, "w") as file:
                    file.write(secure_archive.cached_content)

                print(f"({isOkay}, 'Content successfully written to file')")
            else:
                print(f"({isOkay}, \"{e}\")")

    except PermissionError as e:
        print(f"({isOkay}, \"{e}\")")

if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")
    print("Using 'secure_archive' to read from a nonexistent file: ")
    secure_archive(False, "not/existing/file")
    print("")
    print("Using 'secure_archive' to read from an inaccessible file: ")
    secure_archive(False, "/etc/master.passwd")
    print("")
    print("Using 'secure_archive' to read from a regular file: ")
    secure_archive(True, "ancient_fragment.txt")
    print("")
    print("Using 'secure_archive' to write previous content to a new file: ")
    secure_archive(True, "new_fragment.txt")