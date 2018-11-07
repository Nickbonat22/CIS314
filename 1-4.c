#include <stdio.h>

unsigned int even(unsigned int x)
{
	// isolating even bits
	unsigned int mask = x & 0x55555555;

	// returns 1 or 0 depending on at least one bit containing 1
    return mask != 0;

}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function even 
    unsigned int test1 = even(0x0);
    unsigned int test2 = even(0x1);
    unsigned int test3 = even(0x2);
    unsigned int test4 = even(0x3);
    unsigned int test5 = even(0xFFFFFFFF);
    unsigned int test6 = even(0xAAAAAAAA);
   
    printf("%d\n",test1);
    printf("%d\n",test2);
    printf("%d\n",test3);
    printf("%d\n",test4);
    printf("%d\n",test5);
    printf("%d\n",test6);

    // not returning a value
    return 0;

}