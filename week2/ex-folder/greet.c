#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // printf("hello, %s %s\n", argv[1], argv[2]);
    if (argc == 2) //name of the program & own name
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}