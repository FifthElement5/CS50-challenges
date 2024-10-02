#include <stdio.h>
#include <stdlib.h>
// linked list syntax
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[]) ///argument count and argument vector comments linie arguments
{
    //pierwszu wskaznik to listy , null zeby nie bylo smieci
    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        // tworzenie listy
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node)); /// temporaty przestrzen dla pojedynczego noda
        if (n == NULL)
        {
            return 1;
        }
        n->number = number; /// (*n).number
       // n->next = NULL;     // (*n).next

        n->next = list;
        list = n;

    }

    // drukowanie listy
    node *ptr = list;
    while ( ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    /// uwalnianie pamieci
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;

    }


}
