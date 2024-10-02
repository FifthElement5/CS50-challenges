from sys import argv

g = input("Greeting: ")

# convert greeting to lower and withou space
g = g.lower().strip()

if g.startswith("hello"):
    print("$0")
elif g.startswith("h"):
    print("$20")
else:
    print("$100")
