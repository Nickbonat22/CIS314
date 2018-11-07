#include <stdio.h>

int mask(int x)
{
	// using long long in order to compensate for shifting by 32
    unsigned int shiftX = ((long long) 1 << x);
    unsigned int result = shiftX - 1;

    return result;

}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function mask 
    int test1 = mask(1);
    int test2 = mask(2);
    int test3 = mask(3);
    int test4 = mask(5);
    int test5 = mask(8);
    int test6 = mask(16);
    int test7 = mask(32);

    printf("0x%X\n",test1);
    printf("0x%X\n",test2);
    printf("0x%X\n",test3);
    printf("0x%X\n",test4);
    printf("0x%X\n",test5);
    printf("0x%X\n",test6);
    printf("0x%X\n",test7);

    // not returning a value
    return 0;

}