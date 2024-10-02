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
    while(n < 1);




    //caclculate checksum
    int sum_y = 0;
    int sum_x = 0;
    int length = 0;
    // int second_digit = 0;
    // int first_digit =0;
    long c = n;
    while (c > 0)
    {
    //last-digit
    int y = (c % 10);
    printf("Last: %i\n", y);
    sum_y = sum_y + y;
       length++;
    //secod-to-last digit
    int x = (c % 100)/10;
     printf("Second: %i\n", x);
    //multiply every other by 2
    int multi2x = 2 * x;
    //if has two digits...
    if (multi2x > 9){
      int digit_1 = multi2x % 10;
      int digit_2 = (multi2x - digit_1)/10;
      multi2x = digit_1 + digit_2;
    }
    sum_x = sum_x + multi2x;
      length++;
    //-two last digits


        //     if (n < 100 && n > 9)
        // {
        //      second_digit = n % 10;
        //      first_digit = (n - second_digit)/10;
        // }

        c = (c - x)/100;
        printf("%ld\n", c);





    }
    // long first = n - 1;
    printf("%ld\n", n);

    int total = sum_y + sum_x;
    if (total % 10 == 0)
    {
        printf("Visa Card\n");
    } else
    {
       printf("Invalid\n");
    }
    printf("Total %i\n", total);


    //check for card length and starting digits

    //print if valid

    }





