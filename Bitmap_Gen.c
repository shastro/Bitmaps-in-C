#include "Bitmap_Gen.h"

int main(void){

	char bitmap[SIZE_B + 1];
    char filenum[200];
    char filename[40];
	int i;
    srand(time(NULL));
    int s = rand() % 2000;  

    bitmap_header(bitmap);

    //Pixel Data //

    int id = sin_func1(bitmap);

    // File Naming //
    sprintf(filenum, "%d", id);
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
    printf("Outnum = %d\n\n", id);


	return 0;
}


