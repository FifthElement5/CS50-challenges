#include <stdio.h>

void wczytaj(char *s)
{
    scanf("%s", s);
}

int main(void)
{
    char answer[15];
    printf("Whats your name?\n");
    wczytaj(answer);
    printf("Podaels: %s\n", answer);
}
