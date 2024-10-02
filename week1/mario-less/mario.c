#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get size of grid
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //Print # and . and " "
    //Loop for rows
    for (int i = 0; i < n; i++)
    {
        //Inner loop for . and " "
        for (int x = 0; x < n - i - 1; x++)
        {
            printf(" ");
        }
        //Inner Loop for #
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}


