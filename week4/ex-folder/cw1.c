#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wpisz(char *s)
{
    scanf("%s", s);

}

int main()
{
    char s[10];
    printf("\npodaj: ");
    wpisz(s);
    printf("podales:%s\n", s);
    printf("%p\n", s);
    for (char *z = s; *z !=0; z++ )
    {
        printf(" %c", *z);
    }
    int size =strlen(s);
    char *t = malloc(size + 1);
    for(int i =0; i <= size; i++)
    {
        t[i]=s[i];
    }
    printf(" %d rozmiar \n", size);
    printf("t: %s\n", t);

    free(t);
}
