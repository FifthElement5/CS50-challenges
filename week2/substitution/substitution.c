#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //GET A KEY
    //must accpept a single line argument,key
    if (argc != 2)
    {
        //print error essage printf and return 1
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    //printf("%s\n", key);

    //VALIDATE key
    int length = strlen(key);
    //check key length
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {

        //check for non-alpabetic characters
        if (!isalpha(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        //check for repeated characters
        for (int j = i + 1; j < length; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {

                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
    }

    //get plaintext
    //prompt user for input using get_string
    string plaintext = get_string("plaintext:  ");
    int length_k = strlen(plaintext);

    //encipher
    //print ciphertext
    printf("ciphertext: ");
    for (int k = 0; k < length_k; k++)
    {
        //for each alphabetic characters, determine what letter it maps to
        //preserve case
        if (islower(plaintext[k]))
        {
            int plain = plaintext[k] - 97;
            printf("%c", tolower(key[plain]));
        }
        else if (isupper(plaintext[k]))
        {
            int plain = plaintext[k] - 65;
            printf("%c", toupper(key[plain]));
        }
        else
        {
            //leave non-alphabetic characters as it is
            printf("%c", plaintext[k]);
        }

    }
    printf("\n");
    return 0;
}