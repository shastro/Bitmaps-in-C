#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 255
#define HEIGHT 255

#define SIZE_B (WIDTH * HEIGHT * 24)/8 + 54

enum color{
    RED = 0, GREEN, BLUE
};


int main(void){

	char bitmap[2000000];
	int i;

    // ---- HEADER BEGIN---- //
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
   	for (int i = 30; i < 34; i++) bitmap[i] = 0;

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

    // color pallette information, leave default
    for(int i = 46; i < 50; i++) bitmap[i] = 0;

    // number of important colors, leave default
    for(int i = 50; i < 54; i++) bitmap[i] = 0;
    // ---- HEADER END---- //

    //Pixel Data //
    int c = 0;
     for (i = 54; i < (SIZE_B-54); i += 3) //Loops through bytes in sets of three
    {
            switch (c){
                case BLUE:
                    bitmap[i] = 255;
                    bitmap[i+1] = 0;
                    bitmap[i+2] = 0;
                    //printf("BLUE\n");
                    break;
                case GREEN:
                    bitmap[i] = 0;
                    bitmap[i+1] = 255;
                    bitmap[i+2] = 0;
                    //printf("GREEN!\n");
                    break;

                case RED:
                    bitmap[i] = 0;
                    bitmap[i+1] = 0;
                    bitmap[i+2] = 255;
                    //printf("RED!\n");
                    break;
            }
    	c++;
        if (c == 3){
            
            c = 0;
        }
        // Defunct Diagnostic Code
        // if (i < 500){
        //     printf("%d:%c:%d\n",c, bitmap[i],i);
        // }

    }
    // Default assignment of final bits as pixel data
    // defunct, replaced by loop above.
    //for (i = 54; i < SIZE_B; i++) bitmap[i] = 255;
    //for (i = 60; i < 66; i++) bitmap[i] = 255;




    //File Naming
    FILE *file;
    file = fopen("bitmap.bmp", "wb+");
    for(int i = 0; i < SIZE_B; i++)
    {
        fputc(bitmap[i], file);
    }
    fclose(file);


	return 0;
}

