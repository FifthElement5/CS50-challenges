import csv

with open("favorites.csv", "r") as file:
    # reader = csv.reader(file)
    reader = csv.DictReader(file)
    # next(row)
    # scratch, c, python = 0, 0, 0

    # creats empty dictionary
    # counts = dict()
    counts = {}
    for row in reader:
        # favorite = row[1]
        favorite = row['problem']
        print(favorite)

        # if favorite == "Scratch":
        #     scratch += 1
        # elif favorite == "C":
        #     c += 1
        # elif favorite == "Python":
        #     python += 1

        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# print(f"Scratch: {scratch}")
# print(f"C: {c}")
# print(f"Python: {python}")
# function for reverse order

def get_value(language):
    return counts[language]

# for favorite in sorted(counts, key=get_value, reverse=True):
for favorite in sorted(counts, key=lambda problem: counts[problem], reverse=True):
    print(f"{favorite}: {counts[favorite]}")

favorite = input("Favorite: ")
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")