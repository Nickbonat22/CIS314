#include <stdio.h>

int ge(float x, float y)
{
	// convert x/y raw bits
	unsigned ux = *((unsigned *) &x); 
	unsigned uy = *((unsigned *) &y); 

	// extract sign bit of ux/uy
	unsigned sx = ux >> 31; 
	unsigned sy = uy >> 31; 

	// drop sign bit of ux/uy
	ux <<= 1; 
	uy <<= 1;

	// combining ux,uy with sx,sy in the respective manner
	return (ux >= uy && sx == sy) || (ux <= uy && sx != sy);

}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function ge 
    int test1 = ge(0.0f, 0.0f);
	int test2 = ge(-0.0f, 0.0f);
	int test3 = ge(-1.0f, 0.0f);
	int test4 = ge(0.0f, 1.0f);
	int test5 = ge(1.0f, 0.0f);
	int test6 = ge(0.0f, -1.0f);

    printf("%d\n",test1);
    printf("%d\n",test2);
    printf("%d\n",test3);
    printf("%d\n",test4);
    printf("%d\n",test5);
    printf("%d\n",test6);

    // not returning a value
    return 0;

}