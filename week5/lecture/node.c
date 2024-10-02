#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    //memory for numbers
    node *list = NULL;

    //for each comman-line argument
    for (int i = 1; i < argc; i++)
    {
        //convert argument to int
        int number = atoi(argv[i]);

        //allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        //prepend node to list
        n->next = list;
        list = n;
    }

        //print numbers
        //creat temporary variable that points at the same spot
        //that list points to
        node *ptr = list;
        while (ptr != NULL)
        {
            printf("%i\n", ptr->number);
            //updates ptr to point to the next node
            ptr = ptr->next;


        }

        //free memory
        ptr = list;
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }




}