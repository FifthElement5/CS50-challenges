#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("What' your age? ");
    string number = get_string("What's your phone number? ");

    int n = 4;
    for (int i = 0; i < n; i++) //loops 0 1 2 3
    {
        for (int j = 0; j < n-1; j++)//loops in i 0 1 2
        {
    printf("Age is %i. Name is %s. Phone is %s.", age, name, number);
        }
        printf("\n");
    }

}