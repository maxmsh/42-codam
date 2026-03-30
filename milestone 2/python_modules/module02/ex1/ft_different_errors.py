class SignalException(Exception):
    pass


def garden_operations(value: str, silent: bool = False) -> None:
    try:
        if isinstance(value, str) and "." not in value and "key" not in value:
            if not silent:
                print("\nTesting ValueError...")
            int(value)
    except ValueError as e:
        if not silent:
            print(f"Caught {type(e).__name__}: {e}")
        else:
            raise SignalException
            return

    try:
        if isinstance(value, int):
            if not silent:
                print("\nTesting ZeroDivisionError...")
            num = int(value)
            num / 0
    except ZeroDivisionError as e:
        if not silent:
            print(f"Caught {type(e).__name__}: {e}")
        else:
            raise SignalException
            return

    try:
        if isinstance(value, str) and "." in value:
            if not silent:
                print("\nTesting FileNotFoundError...")
            open(str(value), "r")
    except FileNotFoundError as e:
        if not silent:
            print(f"Caught {type(e).__name__}: {e}")
        else:
            raise SignalException
            return

    try:
        if isinstance(value, str) and "key" in value:
            if not silent:
                print("\nTesting KeyError...")
            mydict = {"name": "dictionary"}
            print(mydict[str(value)])
    except KeyError as e:
        if not silent:
            print(f"Caught {type(e).__name__}: {e}")
        else:
            raise SignalException
            return


def test_error_types():
    garden_operations("abc")
    garden_operations(15)
    garden_operations("missing.txt")
    garden_operations("missing_key")
    print("\nTesting multiple errors together...")
    try:
        garden_operations("s", silent=True)
        garden_operations(8, silent=True)
        garden_operations("orion", silent=True)
        garden_operations("missin", silent=True)
    except (SignalException):
        print("Caught an error, but program still continues!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
    print("\nAll error types tested succesfully!")
