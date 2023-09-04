// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>     // SELF: Added
#include <string.h>     // SELF: Added
#include <stdio.h>      // SELF: Added
#include <strings.h>    // SELF: Added

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// -> changed to 26 (letters) * max length of a word; hash function sums values of each char in a word
const unsigned int N = 26 * LENGTH;

// SELF: Added to store SIZE value globally
unsigned int SIZE = 0;

// Hash table
node *table[N];

// TODO: Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word from the input
    int index = hash(word);

    // Loop through linked-list nodes in a hashed table
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare word with a node's word; if equal, return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// TODO: Hashes word to a number
unsigned int hash(const char *word)
{
    int result = 0;

    // Loop through each char of a word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If it's a letter A-Z, add 0-25 to the result
        if (isalpha(word[i]))
        {
            result += toupper(word[i]) - 'A';
        }
    }
    return result;
}

// TODO: Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // Get-loop all strings (words) in a dictionary file
    char buffer[LENGTH + 1];
    int index;
    while (fscanf(file, "%s", buffer) != EOF)
    {
        // Create a new node for word
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Could not allocate memory for new word.\n");
            return false;
        }

        // Get hashed value
        index = hash(buffer);

        // Set node's word value
        strcpy(new->word, buffer);

        // Set node's next value by prepending to a hashed table
        new->next = table[index];
        table[index] = new;

        // Increase SIZE value
        SIZE++;
    }

    // Free dictionary file
    fclose(file);

    return true;
}

// TODO: Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return SIZE;
}

// TODO: Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor, *next;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            next = cursor->next;
            free(cursor);
            cursor = next;
        }
    }
    return true;
}
