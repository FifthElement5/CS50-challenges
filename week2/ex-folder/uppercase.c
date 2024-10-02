#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0; i < strlen(s); i++)
    {
        if (islower(s[i]))  //(s[i] >= 'a' && s[1] <= 'z')
        {
            printf("%c", toupper(s[i]));     //("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}