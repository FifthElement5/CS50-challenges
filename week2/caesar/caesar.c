#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //must accept single command-line argument k, non-negative
    if (argc != 2)
    {
        //print error essage printf and return 1
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    //if not a number shloud print Usage: ./caesar key, retunr 1
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //printf("%s\n", key);
    }
    //prompt user for a string
    string plaintext = get_string("plaintext:  ");
    //printf("%s\n", plaintext);

    //must calculate and return ciphertext
    int k = atoi(key);
    printf("ciphertext: ");
    for (int j = 0; j < strlen(plaintext); j++)
    {

        if (isupper(plaintext[j]))
        {
            printf("%c", (((plaintext[j] - 65) + k) % 26) + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (((plaintext[j] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");

}