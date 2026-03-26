def garden_operations(value) -> None:
    try:
        # div = value(int) / 0
        return int(value)
    except ValueError as e:
        print(f"Caught {type(e).__name__}: {e}")
    # try:
    #     return div
    # except ZeroDivisionError as e:
    #     print(f"Caught {type(e).__name__}: {e}")
    # try:
    #     return open(value, 'r')
    # except FileNotFoundError as e:
    #     print(f"Caught {type(e).__name__}: {e}")
    # try:
    #     d = {}
    #     print(d[value])
    # except KeyError as e:
    #     print(f"Caught {type(e).__name__}: {e}")


def test_error_types():
    print("\nTesting ValueError...")
    garden_operations("abc")
    # print("\nTesting ZeroDivisionError...")
    # garden_operations(15)
    # print("\nTesting FileNotFoundError...")
    # garden_operations('missing.txt')
    # print("\nTesting KeyError...")
    # garden_operations('missing_key')


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
    print("\nAll error types tested succesfully!")
