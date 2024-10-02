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
    //n->next = NULL;   // (*n).next = null

    n->next = list; //polczenie z noda z lista
    list = n;   // polaczenie listy z wskznikiem na nod
    }

    /// print a whole list
    node *ptr = list; /// pointer do listy
    while (ptr != NULL) // dopuki nie znajde sie w ostanim node
    {
        printf("%d\n ", ptr->number); // (*ptr).number  wejdz w noda i wydrujkuj
        ptr = ptr->next;
    }



}
