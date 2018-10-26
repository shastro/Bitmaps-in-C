#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 255
#define HEIGHT 255
#define PI 3.14159

#define SIZE_B ((WIDTH * HEIGHT * 24)/8) - 54

enum color{
    RED = 0, GREEN, BLUE
};


/* Function Declarations */

int sin_func1(char bitmap[]);
int rgb_func1(char bitmap[]);