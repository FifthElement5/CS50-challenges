#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wczytaj(char *s)
{

    scanf("%s", s);
}

int main(void)
{
    //open CSV file
    FILE *file = fopen("phonebook.csv", "a");

    //get name and number
    char name[40];
    printf("Name: ");
    wczytaj(name);
    char number[40];
    printf("number: ");
    wczytaj(number);

    //char *number = get_string("Number: ");

    //print to file
    fprintf(file, "%s,%s\n", name, number);

    //close file
    fclose(file);

}
