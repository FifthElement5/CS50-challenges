

def main():
    height = get_height()
    # printing rows

    for i in range(height):
        # printing inner loop
        x = int(height - i - 1)
        for j in range(x):
            print(" ", end="")

        # inner loop with #
        y = int(height - x)
        for k in range(y):
            print("#", end="")

        # inner loop for inside space
        for l in range(2):
            print(" ", end="")

        # inner loop for second #
        for m in range(y):
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