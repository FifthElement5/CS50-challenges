# people = dict()
people = {
    "Carter": "777-33-777",
    "Iza": "5555-5555"

}

name = input("Name: ")
if name in people:
    number = people[name]
    # number = people["Iza"]
    print(f"Number: {number}")



