/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define SIZE 1000000
#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};

int hash (const char* word)
{
    int hash = 0;
    int n;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else 
        {
            n = 27;
        }
        
        hash = ((hash << 3) + n) % SIZE;
        
    }
    
    return hash;
    
}

int d_size = 0;

bool load(const char* dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    
    if (fp == NULL)
    {
        return false;
    }
    
    char word[LENGTH+1];
    
    while (fscanf(fp, "%s\n", word) != EOF)
    {
        d_size++;
        
        node* newWord = malloc(sizeof(node));
        
        strcpy(newWord->word, word);
        
        int index = hash(word);
        
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }
        
    }
    
    fclose(fp);
    
    return true;
    
}
        
    
   

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char temp[LENGTH + 1];
    int len = strlen(word);
    
    for (int i = 0; i < len; i++)
    {
        temp[i] = tolower(word[i]);
        temp[len] = '\0';
    }
    
    int index = hash(temp);
    
    if (hashtable[index] == NULL)
    {
        return false;
    }
    
    node* cursor = hashtable[index];
    
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        
        cursor = cursor->next;
        
    }
    
    return false;
    
}
            
    
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (d_size > 0)
    {
        return d_size;
    }
    else
    {
        return 0;
    }
    
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   int index = 0;
   
   while (index < SIZE)
   {
       if (hashtable[index] == NULL)
       {
           index++;
       }
       else
       {
           while(hashtable[index] != NULL)
           {
               node* cursor = hashtable[index];
               hashtable[index] = cursor->next;
               free(cursor);
           }
           
           index++;
       }
   }
   
   return true;
   
}   
        
          
   

    
