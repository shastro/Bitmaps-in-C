/* Functions for generating pixel data 
	Must contain a loop that generates bytes from byte 
	54 to the total num of bytes in the image - 54

	Each function should return an int, this int represents a
	function "ID" which will be used to attatch the output bitmap
	to each function, for the purposes of inspection.

*/

int sin_func1(char bitmap[])
{
	 int c = 0;
     for (i = 54; i < (SIZE_B + (255*3)); i += 1){
        if (c == 510){
            c = 0;
        }
        bitmap[i] = (((255.0) * sin(c/2)) + (256/2)); 
        c++;
    }
    return 1; // Function ID
}