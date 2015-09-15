/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

const int b_size = 512;

int main(int argc, char* argv[])
{
   //open card file
   FILE *file;  
   
   if ((file = fopen("card.raw", "r")) == NULL)
   {  
       printf ("Error!\n");
   }
   
   char jpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
   char jpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
     
   //Create a buffer
   char buffer[512];
   char check[4];
   int counter = 0;
   int open = 0;
   FILE *fw = NULL;
   
    while (fread(buffer, 512, 1, file))
    {
        for (int i = 0; i < 4; i++)
        {
            check[i] = buffer[i];
        }
       
        if((memcmp(jpg1, check, 4) == 0) || (memcmp(jpg2, check, 4)) == 0)
        {
       
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
                
            if(open == 0)
            {
                fw = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, fw);
                open = 1;
            }
                
            if(open == 1)
            {
                fclose(fw);
                fw = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, fw);
                counter++;
            }
        }
        else
        {
            if(open == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, fw );
            }
        }
   }

   
   if (fw)
   {
       fclose(fw);
   }
   
   fclose(file);
   
   return 0;

}
 
   
