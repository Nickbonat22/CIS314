#include <stdio.h>

// function decode reverse engineers code
int decode(int x, int y, int z)
{
    // initialize values to 0 
    int subXY = 0;
    int intResult = 0;
    int tilt = 0;

    // subracting y and z
    subXY = y - z;
    intResult = subXY;

    // shifting and using operators to arrive to the return value
    intResult <<= 31;
    intResult >>= 31;
    tilt = x * subXY;
    intResult ^= tilt;
    
    return intResult;
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function decode    
    signed int test1 = decode(1,2,4);
    signed int test2 = decode(-4,-8,-12);

    printf("%d\n",test1);
    printf("%d\n",test2);

    // not returning a value
    return 0;

}