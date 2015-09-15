#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // establish key variable
    int key;    
    
    // check for correct number of arguments
    if (argc != 2)
    {
        // return if incorrect
        printf("Usage: ./caesar key text \n");
        return 1;
    }
    else
    {
        // get the key for the cipher
        key = atoi(argv[1]);
    }
    
    // get pre-ciphered string (aka pre)
    string plain = GetString();
    int i = 0;
    
    for (i = 0; i < strlen(plain); i++)
    {
        // check for alphabeticals (check whole strlen)
        if (isalpha(plain[i]))
        {
            // check for case
            if (isupper(plain[i]))
            {
                // convert numerical, find modulo, convert ascii
                printf ("%c", ((((plain[i] - 65) + key) % 26) + 65)); 
            }
            
            if (islower(plain[i]))
            {
                // convert numerical, find modulo, convert ascii
                printf ("%c", ((((plain[i] - 97) + key) % 26) + 97));
            }    
        }
        else
        {
             // if non alphabetical do not cipher
            printf ("%c", plain[i]);
        
        }     
      
    }      

    printf ("\n");
    return 0;
    
}
    
        
