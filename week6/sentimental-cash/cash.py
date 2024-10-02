from cs50 import get_float


def main():

    # ask how many cents the costumer is owed
    dolars = get_dolars()
    cents = calculate_cents(dolars)
    print(f"{cents}")

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25
    print(f"{quarters}")

    #  Calculate the number of dimes to give the customer
    dimes = calulate_dimes(cents)
    cents = cents - dimes * 10
    print(f"{dimes}")

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # sum coins
    coins = int(quarters + dimes + nickels + pennies)

    # print total number of coins to give the customer
    print(f"Coins: {coins}")


def get_dolars():
    # prompt user for input
    while True:
        try:
            n = get_float("Change owed: ")
            if n > 0:
                return n
        except ValueError:
            print("Error")


def calculate_cents(dolars):
    return dolars * 100


def calculate_quarters(cents):
    return (cents - (cents % 25)) / 25


def calulate_dimes(cents):
    return (cents - (cents % 10)) / 10


def calculate_nickels(cents):
    return (cents - (cents % 5)) / 5


def calculate_pennies(cents):
    return (cents - (cents % 1)) / 1


main()