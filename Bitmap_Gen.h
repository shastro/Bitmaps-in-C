#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 255
#define HEIGHT 255
#define PI 3.14159

#define SIZE_B (WIDTH * HEIGHT * 3) + 53 //Total Bytes for whole file
#define SIZE_PB WIDTH * HEIGHT * 3 //Num of bytes for pixel data

enum color{
    RED = 0, GREEN, BLUE
};


/* Function Declarations */
void bitmap_header(char bitmap[]);
/* Pixel Funcs */
int sin_func1(char bitmap[]);
int rgb_func1(char bitmap[]);
int draw_line(char bitmap[]);