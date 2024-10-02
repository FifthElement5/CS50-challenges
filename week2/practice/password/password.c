// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int lower = 0;
    int upper = 0;
    int number = 0;
    int symbol = 0;
    //loops a string
    for (int i = 0; i < strlen(password); i++)
    {
        //check if is lower case
        if (islower(password[i]))
        {
            lower++;
        }
        //check if is upper case
        if (isupper(password[i]))
        {
            upper++;
        }
        //check if it's a number
        if (isdigit(password[i]))
        {
            number++;
        }
        //check if it's a symbol
        if (ispunct(password[i]))
        {
            symbol++;
        }
    }
    //
    if (lower > 0 && upper > 0 && number > 0 && symbol > 0)
    {
        return true;
    }
    return false;
}
