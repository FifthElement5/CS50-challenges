#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt the user for card number
    long n;
    do
    {
        n = get_long("N: ");
    }
    while (n < 1);

    //caclculate checksum
    long card_digits = n;
    int sum_y = 0;
    int sum_x = 0;
    int first2_digits;
    int first_digit;

    while (card_digits > 0)
    {
        //last-digit
        int y = (card_digits % 10);
        sum_y = sum_y + y;
        //secod-to-last digit
        int x = (card_digits % 100) / 10;

        //multiply every other by 2
        int multi2x = 2 * x;
        //if has two digits...
        if (multi2x > 9)
        {
            int digit_1 = multi2x % 10;
            int digit_2 = (multi2x - digit_1) / 10;
            multi2x = digit_1 + digit_2;
        }

        sum_x = sum_x + multi2x;
        //-two last digits
        card_digits = (card_digits - x) / 100;

    }

    //check for card length
    long card_length = n;
    int length = 0;
    while (card_length > 0)
    {

        card_length /= 10;
        length++;
    }

    //check for card starting digits
    first_digit = n / pow(10, length - 1);
    first2_digits = n / pow(10, length - 2);

    //print if valid
    int total = sum_y + sum_x;
    if (total % 10 == 0 && (length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else if (total % 10 == 0 && length == 15 && (first2_digits == 34 || first2_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (total % 10 == 0 && length == 16 && (first2_digits == 51 || first2_digits == 52 ||
             first2_digits == 53 || first2_digits == 54 || first2_digits == 55))
    {

        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }



}