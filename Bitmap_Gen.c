#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Bitmap_Gen.h"

#define WIDTH 255
#define HEIGHT 255
#define PI 3.14159

#define SIZE_B ((WIDTH * HEIGHT * 24)/8) - 54

enum color{
    RED = 0, GREEN, BLUE
};

void bitmap_header(char bitmap[]);

int main(void){

	char bitmap[2000000];
    char filenum[200];
    char filename[40];
	int i;
    srand(time(NULL));
    int s = rand() % 2000;  

    bitmap_header(bitmap);

    //Pixel Data //

    int c = 0;
     for (i = 54; i < (SIZE_B + (255*3)); i += 1){
        if (c == 510){
            c = 0;
        }
        bitmap[i] = (((255.0) * sin(c/2)) + (256/2)); 
        c++;
    }
/*    int c = 0;
     for (i = 54; i < (SIZE_B + (255*3)); i += 1){
        if (c == 256){
            c = 0;
        }
        int d = (255*sin(c) + 256/2); 
        c++;
        printf("%d--", d);
    }*/


    sprintf(filenum, "%d", s);
    strcpy(filename, "./bitmpdump/bitmap.bmp");
    strcat(filename,filenum);
    strcat(filename,".bmp");

    FILE *file;
    file = fopen(filename, "wb+");
    for(int i = 0; i < SIZE_B; i++)
    {
        fputc(bitmap[i], file);
    }
    fclose(file);
    printf("Outnum = %d\n\n", s);


	return 0;
}

void bitmap_header(char bitmap[])
{
    int i;
     // BITMAP HEADER //
    bitmap[0] = 'B';
    bitmap[1] = 'M';

    //size in bytes// 255 //0h7530
    bitmap[2] = 0;
    bitmap[3] = 0;
    bitmap[4] = 0;
    bitmap [5] = 0;

    // Reserved field //
    for (i = 6; i < 10; i++) bitmap[i] = 0;

    // Offset, starting btyle of pixel data //
    bitmap[10] = 54;
    bitmap[11] = 0;
    bitmap[12] = 0;
    bitmap[13] = 0;

    // Header size //
    bitmap[14] = 40;

    for (i = 15; i < 18; i++) bitmap[i] = 0;

    //Width in pixels, in hex format //
    bitmap[18] = 255;
    bitmap[19] = 0;
    bitmap[20] = 0;
    bitmap[21] = 0;

    //Height in pixels //
    bitmap[22] = 255;
    bitmap[23] = 0;
    bitmap[24] = 0;
    bitmap[25] = 0;

    // Color Planes, must be 1 //
    bitmap[26] = 1;
    bitmap[27] = 0;

    //Num of bits per pixel //
    bitmap[28] = 24; //3 bytes
    bitmap[29] = 0;

    //Compression being used, None /
    for (i = 30; i < 34; i++) bitmap[i] = 0;

    // Image size in bytes //
    bitmap[34] = 0; //4 pixels = 12 bytes 
    bitmap[35] = 0;
    bitmap[36] = 0;
    bitmap[37] = 0;


    // horizontal resolution of the image - pixels per meter (2835)
    bitmap[38] = 0;
    bitmap[39] = 0;
    bitmap[40] = 0b00110000;
    bitmap[41] = 0b10110001;

    // vertical resolution of the image - pixels per meter (2835)
    bitmap[42] = 0;
    bitmap[43] = 0;
    bitmap[44] = 0b00110000;
    bitmap[45] = 0b10110001;

    // color pallette information
    for(i = 46; i < 50; i++) bitmap[i] = 0;

    // number of important colors
    for(i = 50; i < 54; i++) bitmap[i] = 0;


}

