cd// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    //must accept a single command-line
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    string word = argv[1];
    string result = replace(word);
    printf("%s\n", result);

}
//function to replace vowels with numbers
string replace(string input)
{
    string output = input;
    for (int i = 0; i < strlen(input); i++)
    {
        //changes to lowercase
        char l = tolower(input[i]);
        printf("%c\n", input[i]);

        switch (l)
        {
            case 'a':
                output[i] = '6';
                break;

            case 'e':
                output[i] = '3';
                break;

            case 'i':
                output[i] = '1';
                break;

            case 'o':
                output[i] = '0';
                break;

            default:
                output[i] = input[i];
                break;
        }

    }
    return output;
}

