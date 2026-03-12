def ft_water_reminder():
    days_since_watering_str = input("Days since last watering: ")
    days_since_watering = int(days_since_watering_str)
    if days_since_watering > 2:
        print("Water the plants!")
    else:
        print("Plants are fine.")


ft_water_reminder()
