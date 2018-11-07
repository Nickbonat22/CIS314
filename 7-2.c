#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define N 6
typedef float array_a[N];

// given function to compute the inner product of two arrays u and v
void inner(float *u, float *v, int length, float *dest) {
	int i;  
	float sum = 0.0f;
	for (i = 0; i < length; i++)
	{  
		sum += u[i] * v[i];
	} 
	*dest = sum;
	printf("%.6f", *dest);
    printf("\n");

}

// my function that uses four-way loop unrolling with four parallel accumlators
void inner2(float *u, float *v, int length, float *dest)
{	
	int i;
    float sum = 0.0f;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    float sum3 = 0.0f;

    for (i = 0; i < length; i += 4)
    {
    	// using four parallel accumulators
    	sum += u[i] * v[i];
        sum1 += u[i+1] * v[i+1];
        sum2 += u[i+2] * v[i+2];
        sum3 += u[i+3] * v[i+3];
    }
    // this loop is needed when there are left over items
    for (; i<length; i++)
    {
    	sum += u[i] * v[i];
    }
    *dest = sum + sum1 + sum2 + sum3;
    printf("%.6f", *dest);
    printf("\n");
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    // testing function inner and inner 2
	
	// array input from piazza
	array_a u = {1.5, 2.0, 3.5, 4.0};
	array_a v = {2.0, 2.0, 2.0, 2.0};
	float dest;

	//inner(u, v, N, &dest); // should be: 22.000000
	inner2(u, v, N, &dest); // should be: 22.000000

	// code to run the execution time for inner and inner2
	/*
	clock_t old_start = clock();
    inner(u, v, N, &dest);
    old_start = clock() - old_start;
    double old_time = ((double)old_start) / CLOCKS_PER_SEC;

    clock_t new_start = clock();
    inner2(u, v, N, &dest);
    new_start = clock() - new_start;
    double new_time = ((double)new_start) / CLOCKS_PER_SEC;
    

    printf("old function time: %f \n", old_time * 100);
    printf("new function time: %f \n", new_time * 100);
    */

    // not returning a value
    return 0;

}