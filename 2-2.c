#include <stdio.h>

unsigned int extract(unsigned int x, int i)
{
	// shifting to return byte i of x sign extended to 32 bits
    signed int shiftI = (3 - i) << 3;
    signed int shiftX = x << shiftI;
    signed int shiftFinal = shiftX >> 24;

    return shiftFinal;
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function extract 
    signed int test1 = extract(0x12345678, 0);
    signed int test2 = extract(0xABCDEF00, 2);

    printf("0x%08X\n",test1);
    printf("0x%08X\n",test2);

    // not returning a value
    return 0;

}