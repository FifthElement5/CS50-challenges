#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
//    //get a string
//    char *s = get_string("s: ");
//    if (s == NULL)
//    {
//     return 1;
//    }

//    //allocate memory for another string
//    char *t = malloc(strlen(s) + 1);
//    if (t == NULL)
//    {
//     return 1;
//    }

   //copy string into memory, including '\0'
//    for (int i = 0, n = strlen(s); i <= n; i++)
//    {
//     t[i] = s[i];
//    }
//     strcpy(t, s);

//    //capitalize copy
//    t[0] = toupper(t[0]);

//     printf("s: %s %p\n", s, s);
//     printf("t: %s %p\n", t, t);

//     free(t);
//     return 0;



    // Get a string
    string s = get_string("s: ");


    //copy string's address
    string t = s;

    // //capitalize forst letter in string
    // //strlen is used to make sure string t exist
    // if (strlen(t) > 0)
    // {
     t[0] = toupper(t[0]);
    // }

    //print string twice
    printf("s: %s %p\n", s, s);
    printf("t: %s %p\n", t, t);

}
