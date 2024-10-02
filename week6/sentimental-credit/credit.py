from cs50 import get_int

def main():

# get card number
    n = get_number()


    # calculate checksum
    card_digits = n
    sum_y = int(0)
    sum_x = int(0)
    #first2_digits = int
    #first_digit = int


    while card_digits > 0:
        # last-digit
        y = int(card_digits % 10)
        sum_y = sum_y + y

        # second-digit
        x = int((card_digits % 100) / 10)

        #multipy every other by 2
        multi2x = 2 * x

        # if has two digits...
        if multi2x > 9:
            digit_1 = int(multi2x % 10)
            digit_2 = int((multi2x - digit_1) / 10)
            multi2x = digit_1 + digit_2

        sum_x = sum_x + multi2x

        # - two last digits
        card_digits = (card_digits - x) / 100

        # print(f"{sum_x}")

    # check for card length
    card_length = n
    length = int(0)
    while card_length > 0:
        card_length //= 10
        length += 1


   # print(f"{n}")
    # print(f"{length}")
    # check for card starting digits
    first_digit = int(n // pow(10, length - 1))
    first2_digits = int(n // pow(10, length - 2))
    print(f"{first_digit}")

    # print if valid
    total = sum_y + sum_x

    print(f"{total}")
    if total % 10 == 0 and (length == 13 or length == 16) and first_digit == 4:
        print("VISA")
    elif total % 10 == 0 and length == 15 and (first2_digits == 34 or first2_digits == 37):
        print("Amex")
    elif total % 10 == 0 and length == 16 and (first2_digits == 51 or first2_digits == 52 or first2_digits == 53 or first2_digits == 55):
        print("Mastercard")
    else:
        print("Invalid")






# prompt user for a card number
def get_number():
    while True:
        try:
            n = get_int("N: ")
            if n > 1:
                return n
        except ValueError:
            print("Error")

main()
