/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

int i; 
 
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    // TODO: implement an O(n^2) sorting algorithm
    for (i = 0; i < n; i++)
    {
    
        if (values[i] > values[i + 1])
        {   
            int temp;
            temp = values[i + 1];
            values[i + 1] = values[i];
            values[i] = temp;
        }    
            
    }
    
}
   
bool search(int value, int values[], int n)
{
   
    sort(values, n);

    for (i = 0; i < n; i++)
    {
        int median;
        int start;
        int end;
        start = 0;
        end = values[n];
                
        while (start < end)
        {
        
        median = (start + end) / 2;
                           
            if (median == value)
            {
                return true;
            }
            else if (median > value)
            {
                end = median - 1;
            }
            else if (median < value)
            {
                start = median + 1;
            }
            else 
            {
                break;
            }
                     
        }

        return false;

    }

    return NULL;

}
   
