/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resize a BMP to n times larger image.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    
    if (n < 1 || n > 100)
    {
        printf("n should be a positive integer less than 100\n");
        return 2;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER infilebf, outfilebf;
    fread(&infilebf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER infilebi, outfilebi;
    fread(&infilebi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (infilebf.bfType != 0x4d42 || infilebf.bfOffBits != 54 || infilebi.biSize != 40 || 
        infilebi.biBitCount != 24 || infilebi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    outfilebf = infilebf;
    outfilebi = infilebi;
    
    int paddingInfile =  (4 - (infilebi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    outfilebi.biWidth = n * infilebi.biWidth;
    outfilebi.biHeight = n * infilebi.biHeight;
    
    // determine padding for scanlines
    int paddingOutfile =  (4 - (outfilebi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    outfilebi.biSizeImage = ((sizeof(RGBTRIPLE) * outfilebi.biWidth) + paddingOutfile) * abs(outfilebi.biHeight);
    outfilebf.bfSize = outfilebi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&outfilebf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&outfilebi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // temporary storage
    RGBTRIPLE infiletriple;
    
    // iterate over infile's scanlines
    for (int i = 1, biHeight = abs(infilebi.biHeight); i <= biHeight; i++)
    {
        for (int vtimes = 1; vtimes <= n; vtimes++)
        {
            // iterate over pixels in scanline
            for (int j = 1; j <= infilebi.biWidth; j++)
            {
                // read RGB triple from infile
                fread(&infiletriple, sizeof(RGBTRIPLE), 1, inptr);
    
                // write RGB triple to outfile n times
                for (int htimes = 1; htimes <= n; htimes++)
                {
                    fwrite(&infiletriple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
                if (outfilebi.biWidth % 4 != 0 && j == infilebi.biWidth)
                {
                    // then add it back (to demonstrate how)
                    for (int k = 0; k < paddingOutfile; k++)
                    {
                        fputc(0x00, outptr);
                    }
                }    
            }
            
            //to backtrace infile's cursor
            fseek(inptr, -(long int)(infilebi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }
        
        fseek (inptr, (long int)(infilebi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        if (infilebi.biWidth % 4 != 0)
        {   
            // skip over padding, if any
            fseek(inptr, paddingInfile, SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
