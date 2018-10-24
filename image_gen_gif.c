#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

#define SIZE_B (WIDTH * HEIGHT * 24)/8 + 54


int main(void){

	int D = 0;
	char filename[40];
	char filenum[5];
	while (D < 1025){

		if (D == 1024){
			break;
		}
		char bitmap[100000];
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

		// Offset, starting byte of pixel data //
		bitmap[10] = 54;
		bitmap[11] = 0;
		bitmap[12] = 0;
		bitmap[13] = 0;

		// Header size //
		bitmap[14] = 40;

		for (i = 15; i < 18; i++) bitmap[i] = 0;

		//Width in pixels //
		bitmap[18] = WIDTH;
		for(int i = 19; i < 22; i++) bitmap[i] = 0;

		//Height in pixels //
		bitmap[22] = HEIGHT;
	    for(int i = 23; i < 26; i++) bitmap[i] = 0;

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

	    // color pallette information
	    for(int i = 46; i < 50; i++) bitmap[i] = 0;

	    // number of important colors
	    for(int i = 50; i < 54; i++) bitmap[i] = 0;

	    //Pixel Data //
	    int c = 0;
	    for (i = 54; i < SIZE_B; i += 4)
	    {
	    	if (c == D){
	    		
	    		c = 0;
	    	}
	    	bitmap[i] = c;
	    	c++;

	    }
	    //for (i = 54; i < SIZE_B; i++) bitmap[i] = 255;
	   // for (i = 60; i < 66; i++) bitmap[i] = 255;
	    //filename[] = {".","/","f","r","a","m","e","s","/","b","i","t","m","a","p","\0"};
	    //itoa(D,filenum,2);
	    sprintf(filenum, "%d", D);
	    strcpy(filename, "./frames/bitmap");
	    strcat(filename,filenum);
	    //filename[15] = D;
	    strcat(filename,".bmp");

	    FILE *file;
	    file = fopen(filename, "wb+");
	    for(int i = 0; i < SIZE_B; i++)
	    {
	        fputc(bitmap[i], file);
	    }
	    fclose(file);
	D += 1;
	}
	return 0;
}

