

def main():
    height = get_height()
    # printng rows
    for i in range(height):
        # printing inner loop with .
        x = int(height - i - 1)
        for j in range(x):
            print(" ", end="")
        # inner loops with #
        y = int(height - x)
        for k in range(y):
            print("#", end="")
        print()

# get size of grid


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
        except ValueError:
            print("Error")
            

main()