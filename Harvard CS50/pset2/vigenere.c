#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // establish variables
    int i = 0;
    int j = 0; 
    int convert;
    
    
    // check for correct number of arguments
    if (argc != 2 && !isalpha(argv[1]))
    {
        // return if incorrect
        printf("Usage: ./vigenere alphakey \n");
        return 1;
    }

    string key = argv[1];      

    // check the key for alphas
    for (int l = 0; l < strlen(key); l++)
    {    
        if (!isalpha (key[l]))
        {
            printf("Key must be alphabetical. \n");
        }
    }          

    string plain = GetString();
           
    // converting the plaintext
       
    for (i = 0, j = 0; i < strlen(plain); i++, j++)
    {    
       if (!isalpha(key[j]))   
       {
           j = 0;
       }
     
       convert = key[j]; 
            
       // check for case
       if (isupper(plain[i]))
       {
       
           if (isupper(key[j]))
           {
                (convert = convert - 65);
           }
           
           if (islower(key[j]))
           {
                (convert = convert - 97);
           }  
           
           // convert numerical, find modulo, convert ascii
           printf ("%c", ((((plain [i] - 65) + convert) % 26) + 65)); 
      
       }
       
       if (islower(plain[i]))
       {
          
           if (isupper(key[j]))
           {
               (convert = convert - 65);
           }
           
           if (islower(key[j]))
           {
               (convert = convert - 97);
           }  
           
           // convert numerical, find modulo, convert ascii
           printf ("%c", ((((plain [i] - 97) + convert) %26) + 97));
      
      }    
       
      if (!isalpha(plain[i]))
      {
           // if non alphabetical do not cipher
           printf ("%c", plain[i]);
      }     
    
   }
          
   printf ("\n");
   return 0;
   
}
   


