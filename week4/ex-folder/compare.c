///#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define N 15



int main(void)
{

        //get two strings
    char s[N];
    printf("s:\n"); scanf("%s", s);
    char t[N];
    printf("t: \n"); scanf("%s", t);
    // Get two strings
    // char *s = get_string("s: ");
    // char *t = get_string("t: ");

    // Print strings
    printf("%s\n", s);
    printf("%p\n", t);

        // //print strings' addresses
    // printf("%s\n", s);
    // printf("%s\n", t);

    // //compare strings' addresses
    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}






