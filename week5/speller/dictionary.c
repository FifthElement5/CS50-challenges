// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//global variables for word counting
unsigned int size_count;
unsigned int hash_index;


// TODO: Choose number of buckets in hash table
const unsigned int N = 100;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to obtain a hash value
    hash_index = hash(word);
    //access linked list at that index
    //cursor set to first item in linked list
    node *cursor = table[hash_index];
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash
    //inspiration of hash function from Doug Lloyd CS50/Hash Funcion week5
    int sum = 0;
    //loop a word
    for (int i = 0; word[i] != '\0'; i++)
    {
        //changing chars to upper
        //adding ascii value of word
        sum += toupper(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return false;
    }
    char word[LENGTH + 1];

    //create a new node for each word
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("ERROR");
            return 1;
        }
        //copy word into a node
        strcpy(n->word, word);

        //hash word to obtain hash value
        hash_index = hash(word);
        //insert a new node
        n->next = table[hash_index];
        table[hash_index] = n;
        size_count++;





    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //
    if (size_count > 0)
    {
        return size_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //loop through bucket
    for (int i = 0; i < N; i++)
    {
        //set cursor to first item
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

    }
    return true;
}
