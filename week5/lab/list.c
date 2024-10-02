#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

#define LIST_SIZE 3

void unload(node *list);
void visualize(node *list);


int main(void)
{
    node *list = NULL;

    //add items to list
    for (int i = 0; i < LIST_SIZE;i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        //TODO: add phrase to a new mode in link
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("ERROR");
            return 1;
        }

        n->phrase = phrase;
        n->next = list;

        list = n;
        //visualize list after adding
        visualize(list);
    }
    unload(list);
}
void unload(node *list)
{
    //todo:
    while (list != NULL)
    {
    node *ptr = list->next;
    free(list);
    list = ptr;
    }
}

void visualize(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\n", list);
        printf("Phrase: \"%s\"\n", list->phrase);
        printf("Next: %p\n\n", list->next);
        list = list->next;
    }
    printf("+--------------------+\n\n");
}

