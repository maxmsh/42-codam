def garden_operations(input) -> int:
    try:
        if isinstance(input, int):
            return input
        else:
            return int(input)
    except ValueError:
        print("Caught ValueError: invalid literal for int()")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")


def test_error_types():
    print("Testing ValueError...")
    garden_operations("abc")
    print("Testing ZeroDivisionError...")
    garden_operations("0")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    print("")
    test_error_types()
