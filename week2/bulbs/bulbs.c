#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // prompt user for a message using get_string

    string message;
    do
    {
        message = get_string("Message: ");
    }
    while (message < 0);
    //printf("Message: %s\n", message);
    //convert the given string into binary(string to chart and chart to binary)

    for (int i = 0; i < strlen(message); i++)
    {
        //convert string to chart
        char charNumber = message[i];
        int binary[BITS_IN_BYTE];
        printf("%i\n", charNumber);
        int quotient = charNumber;
        int reminder;

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            //convert decimel to binary
            reminder = quotient % 2;
            binary[j] = reminder;
            quotient /= 2;
             printf("C%i ", quotient);
             printf("%i ", reminder);

        }
        //print a series of yellow and dark using reverse loop
        for (int x = BITS_IN_BYTE - 1; x >= 0; x--)
        {
            print_bulb(binary[x]);
        }
        printf("%i", reminder);
        printf("\n");
    }






}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
