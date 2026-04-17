import random
import typing

def gen_event() -> typing.Generator:
    players = ['alice', 'bob', 'charlie', 'dylan']
    actions = ['run', 'eat', 'sleep', 'grab', 'move', 'climb', 'swim', 'release', 'use']
    while True:
        yield (random.choice(players), random.choice(actions))

def consume_event(event_list: list) -> typing.Generator:
    while len(event_list) > 0:
        event = random.choice(event_list)
        event_list.remove(event)
        yield event

if __name__ == "__main__":
    print("=== Game Data Stream Processor ===\n")

    stream = gen_event()
    for i in range(1000):
        name, action = next(stream)
        print(f"Event {i}: Player {name} did action {action}")

    event_list = [next(stream) for _ in range(10)]
    print(f"\nBuilt list of {len(event_list)} events: {event_list}")

    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {event_list}")