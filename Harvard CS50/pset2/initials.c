#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    
    // Get the name
    string name = GetString();
    
    // Name can't be blank
    if (name != NULL)
    
    {
    
        // Print first initial capitalized
        printf("%c", toupper(name[0]));
        
        // Print initials, checks for spaces
        for (int i = 0; i < strlen(name); i++)
        {
          
            if (name[i] == ' ')
            {    
                printf ("%c", toupper(name[i + 1]));
            }
            
        }
   
        printf("\n");
   
    }
    
}    
