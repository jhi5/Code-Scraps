/**
 *greedy.c
 *problem set 1 for cs50
 *
 *J. Munford
 *jacobmunford@gmail.com
 *
 *Calculates the fewest number of coins to be
 *returned when presented with a dollar amount.
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float Dollar;

    /**Ask user for a dollar amount
     *Use do while loop
     *Cannot be negative
     */
  
    do
    {
        printf("How much money did ya give me again?");
        Dollar = GetFloat();
    }
        while (Dollar < 0);
        
    /**convert amount to cents
     *use roundf to prevent float probs
     */
     
    int cents = roundf((Dollar * 100));
    int qcount = 0;
    int dcount = 0;
    int ncount = 0;
    int pcount = 0;
     
    while (cents >= 25)
    {
        cents -= 25;
        qcount += 1;
    }
    
    while (cents >= 10)
    {
        cents -= 10;
        dcount += 1;         
    }
    
    while (cents >= 5)
    {
        cents -= 5;
        ncount += 1;
    }
    
    while (cents >= 1)
    {
        cents -= 1;
        pcount += 1;
    }
 
    int change_total = (qcount + dcount + ncount + pcount);
    
    {
        printf ("%d\n", change_total);
    }
    
        return 0;
    
}
