/**
 *mario.c
 *problem set 1 for cs50
 *
 *J. Munford
 *jacobmunford@gmail.com
 *
 *Creates a mario-style pyramid
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

/**ask for a number for pyramid height - define number as p_height
 *p_height must be between 0 and 23
 *use do while loop
 */

int main(void)
{
    int height;
    do
    {
        printf("How tall is your pyramid? Not higher than 23, right?\n");
        height = GetInt();
    }
    while (height < 1 || height > 23);
    
    /**
     *Create the pyramid using simple equations
     *Number of spaces = height - 1
     *Number of hashes = height + 2
     *New Line after each
     */

    for(int i = 0; i < height; i++)
    {
              
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
            
        }    
        
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
                  
        printf("\n");
     
    }
    
    return 0;
        
}
