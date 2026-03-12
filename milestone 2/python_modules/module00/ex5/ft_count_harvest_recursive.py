def ft_count_harvest_recursive(day, i):
    if i >= day:
        print(f"Day {day}")
        ft_count_harvest_recursive(day + 1, i)
    elif i <= day:
        print("Harvest time!")


if __name__ == "__main__":
    print("Days until harvest: ")
input_val = int(input())
ft_count_harvest_recursive(1, input_val)
