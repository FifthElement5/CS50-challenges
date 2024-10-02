#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //An array of integers

    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int k = sizeof(numbers)/sizeof(numbers[0]);
    printf("%dk", k);



    //Search fo a numver
    int n = get_int("Number: ");
    for (int i = 0; i < k; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;

}
