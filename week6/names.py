import sys

names = ["Bill", "Charlie", "Fred", "George", "Iza", "Niko"]

name = input("Name: ")

# for n in names:
#     if name == n:

if name in names:
        print("Found")
        sys.exit(0)

print("Not found")
sys.exit(1)