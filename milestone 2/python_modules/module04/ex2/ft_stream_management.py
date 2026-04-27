import sys

if __name__ == "__main__":
    argc = len(sys.argv)

    if argc > 1:
        try:
            filename: str = sys.argv[1]

            if "/etc/" in filename:
                raise PermissionError(f"[Errno 13] Permission denied: "
                                      f"'{filename}'")

            sys.stdout.write("=== Cyber Archives Recovery & Preservation ==="
                         "\n")
            sys.stdout.write(f"Accessing file '{filename}'\n")

            f = open(filename, "r")
            content = f.read()

            sys.stdout.write("---\n\n")
            sys.stdout.write(content)
            sys.stdout.write("\n\n---")
            f.close()
            sys.stdout.write(f"\nFile '{filename}' closed.\n")

            sys.stdout.write("\nTransform data: \n")
            sys.stdout.write("---\n\n")

            lines = content.rstrip("\n").split("\n")

            newlines = []
            for line in lines:
                newlines.append(line + "#")
            
            new_content = "\n".join(newlines)

            sys.stdout.write(new_content)
            sys.stdout.write("\n\n---")

            sys.stdout.write("\nEnter new file name (or empty): ")
            save: str = sys.stdin.readline().strip()
            sys.stdout.write(f"Saving data to '{save}'\n")

            if save == "":
                sys.stdout.write("Not saving data.\n")
            elif "/etc/" in save:
                raise ValueError(f"[Errno 13] Permission denied: "
                                      f"'{save}'\n"
                                      "Data not saved.")
            else:
                f = open(save, "w")
                sys.stdout.write(f"Saving data to '{save}'\n")
                f.write(new_content)
                f.close()
                sys.stdout.write(f"Data saved in file '{save}'\n")
                
        except FileNotFoundError as e:
            sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        except PermissionError as e:
            sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        except ValueError as e:
            sys.stderr.write(f"[STDERR] Error opening file '{save}': {e}\n")
    else:
        sys.stdout.write("Usage: ft_stream_management.py <file>\n")