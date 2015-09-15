/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize scale infile outfile\n");
        return 1;
    }
   
    int scale = atoi(argv[1]);   
    
    if (scale < 1)
    {
        printf("Scale requires a non-negative integer > 0\n");
        return 5;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int o_width = bi.biWidth;
    int o_height = bi.biHeight;
    int o_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) %4;
    bi.biWidth = bi.biWidth * scale;
    bi.biHeight = bi.biHeight * scale;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) %4;
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight); 
    bf.bfSize = bf.bfSize + sizeof(bf);  
    o_height = abs(o_height);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADERS
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    for (int i = 0; i < o_height; i++)
    {
        fpos_t position;
        fgetpos (inptr, &position);
        
        for (int j = 0; j < scale; j++)
        {
        
            if (j < scale)
            {
                fsetpos (inptr, &position);
            }
            
            for (int k = 0; k < o_width; k++)
            {
                
                RGBTRIPLE triple;
                
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                for (int l = 0; l < scale; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }
            
            fseek(inptr, o_padding, SEEK_CUR);
            
            for (int m = 0; m < padding; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }

                
    
        
    
                
            

    
      

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

                             
