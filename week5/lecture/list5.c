#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} node;

int main(int argc, char *argv[]) /// arguments count , arguments vetor : nazwa to argv[0] strings
{                                  /// po ./list wpsuje to co chce
    node *list = NULL;// incjujje liste i przypisuje null

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); // atoi asci to integer
        // printf("%s \n", argv[i]);
         printf("%i \n", number);


    node *n = malloc(sizeof(node)); // tymczasowy node
    if (n == NULL)
    {
        //free mamory
        return 1;
    }
    n->number = number; // idz to tego co wskzuje wskaznik i przypisz licze po =
    n->next = NULL;   // (*n).next = null

    // if list is empty
    if (list == NULL)
    {
        //this node is te whole list
        list = n;
    }
    //if number belongs at beginning of list
    else if (n->number < list->number)
    {
        n->next = list;
        list = n;
    }

    // if number belongs later in list
    else
    {
        for (node *ptr = list; ptr !=NULL; ptr = ptr->next)
        {
            // if at the end of list
            printf("%i\n", ptr->number);
            if (ptr->next == NULL)
            {
                ptr->next = n;
                break;
            }
            //if in middle of list
            if(n->number < ptr->next->number)
            {
                n->next = ptr->next;
                ptr->next = n;
                break;
            }
        }

    }


}
}
