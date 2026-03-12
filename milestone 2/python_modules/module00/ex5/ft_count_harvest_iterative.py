def ft_count_harvest_iterative():
    counter = 0

    print("Days until harvest: ", end="")
    days_till_harvest = int(input())

    while counter < days_till_harvest:
        counter += 1
        print(f"Day {counter}")
    print("Harvest time!")


ft_count_harvest_iterative()
