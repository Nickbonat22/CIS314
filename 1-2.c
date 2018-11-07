#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y)
{
    // creating masks for respective significant byte
    unsigned int maskX = 0xFF000000;
    unsigned int maskY = 0x00FFFFFF;

    // using bit masks to isolate significant bytes
    unsigned int newX = x & maskX;
    unsigned int newY = y & maskY;

    // using or operator to combine
    unsigned int rgba = newX | newY;

    return rgba;
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function combine
    unsigned int test1 = combine(0x12345678, 0xABCDEF00);
    unsigned int test2 = combine(0xABCDEF00, 0x12345678);
    
    printf("0x%X\n",test1);
    printf("0x%X\n",test2);

    // not returning a value
    return 0;

}
