#include <stdio.h>
//#include <cs50.h>

int main(void)
{

    char *s = "HI!";
    printf("%s\n", s);
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("-------------------------GWAIZDKA DRUKUJE TO CO WSRODKU\n");
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("--------------------------\n");
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    int n = 50;
    printf("%i\n", n);
    // & Provides the address of something stored in memory.
    // * Instructs the compiler to go to a location in memory.
    printf("%p\n", &n);
        int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

}


