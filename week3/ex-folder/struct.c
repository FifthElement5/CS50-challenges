#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "55555";

    people[1].name = "David";
    people[1].number = "88888";

    people[2].name = "Iza";
    people[2].number = "77777";


    //search for name
    string name = get_string("Name ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}