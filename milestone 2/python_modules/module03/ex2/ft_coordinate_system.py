import math, sys

def get_player_pos():
    while True:
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        try:
            x, y, z = map(float, raw.split(','))
            print(f"Got a first tuple: ({x}, {y}, {z})")
            print(f"It includes: X={x}, Y={y}, Z={z}")
            distance_to_center = math.sqrt((x) **2 + (y) **2 + (z) **2)
            distance_rounded = round(distance_to_center, 4)
            print(f"Distance to center: {distance_rounded}")
            break
        except ValueError:
            print("Invalid syntax")
            continue
    return distance_rounded  # fix 1

if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print("Get a first set of coordinates")
    distance_rounded = get_player_pos()  # fix 1
    print("\nGet a second set of coordinates")
    while True:
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")  # fix 2
        try:
            x, y, z = map(float, raw.split(','))
            distance_to_center_second = math.sqrt((x) **2 + (y) **2 + (z) **2)
            distance_rounded_second = round(distance_to_center_second, 4)
            distance_diff = distance_rounded_second - distance_rounded
            print(f"Distance between the 2 sets of coordinates: {distance_diff}")
            break
        except ValueError as e:
            print(f"Error on parameter: {e}")