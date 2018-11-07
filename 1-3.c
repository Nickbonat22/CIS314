#include <stdio.h>

// CREDITS for function replace: Author: uknown, page source: http://www.cs.unm.edu/~villalon/cs341/lab3/lab3_instructions.pdf
unsigned int replace(unsigned int x, int i, unsigned char b)
{
    // shift current value
    unsigned int a = i << 3;

    //mask out current byte value
    unsigned int mask = 0xFF << a;
    unsigned int shift = b << a;

    // using or operator to combine
    unsigned int final = (x & ~mask) | shift;

    return final;
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function replace 
    unsigned int test1 = replace(0x12345678, 2, 0xAB);
    unsigned int test2 = replace(0x12345678, 0, 0xAB);
    
    printf("0x%X\n",test1);
    printf("0x%X\n",test2);

    // not returning a value
    return 0;

}