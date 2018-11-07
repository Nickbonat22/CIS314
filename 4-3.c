#include <stdio.h>

int sum(int from, int to) {
     int result = 0;

	// Ensure that argument *from* is in %ecx,
	// argument *to* is in %edx, *result* is in %eax - do not modify.
    __asm__ ("movl %0, %%ecx # from in ecx;" :: "r" ( from ));
    __asm__ ("movl %0, %%edx # to in edx;" :: "r" ( to ));
	__asm__ ("movl %0, %%eax # result in eax;" :: "r" ( result ));

	__asm__(
           ".LOOP:" 
           "addl %ecx, %eax;" // adding from to result
           "addl $1, %ecx;" // incrementing from
           "cmpl %edx, %ecx;" // comparing from <= to
           "jle .LOOP;" // less than jump
     );
	// Ensure that *result* is in %eax for return - do not modify.
	__asm__ ("movl %%eax, %0 #result in eax;" : "=r" ( result ));
	return result;
}

// not using int argc, char *argv[]
int main(int argc, char *argv[])
{
	// testing function sum
    signed int test1 = sum(1,6);
    signed int test2 = sum(3,5);

    printf("%d\n", test1); 
    printf("%d\n", test2); 

	// not returning a value
	return 0;
}