// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
bool isloaded = false;
unsigned int numwords = 0;
// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hash = 0;
    int n;
    for (int i = 0; word [i] != '\0'; i++)
    {
        //check if character is an alpahbet
        if (isalpah(isword[i]))
        {
            n = word[i] - 'a' + 1;
        }else
        {
            n = 27
        }

        hash = ((hah<< 3) + n) % N;
    }
    return hash;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = malloc(sizeof(node));
    cursor->next = table[index];
    while (cursor->next != NULL)
    {
        if (strcasecmp(word, cursor->word))
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    node *n = malloc(sizeof(node));
    //create an empty node
    //open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("The dictionary return NULL when attempting to open");
        return 1;
    }
    //read strings from File
    char word[LENGTH + 1];
    for (int c =(file, "%s", word); c != EOF; c = (file, "%s", word) )
    {
       //create a new node for each word using malloc
       //check if there's enough memory
       //copy word into the node using strcpy
       np = malloc(sizeof(node));
       if (np == NULL)
       {
           printf("Not enough space to create a new node");
           return 1;
       }
       strcpy(np->word, word)
       int index = hash(word);
       np->next = table[index];
       table[index] = np;
       numwords ++;
    }
    fclose(file);
    isloaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(isloaded)
    {
        return numwords;
    }
    if(!isloaded)
    {
        return 0;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < LENGTH; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = malloc(size(node));
            node *tmp = malloc(size(node));
            cursor = table[i]->next;
            while(cursor->next != NULL)
            {
                tmp = cursor;
                cursuor = cursor->next
                free(tmp)
            }
        }
    }
    return true;
}
