/*
loop:
pushl %ebp                prologue
movl %esp, %ebp				
pushl %esi
pushl %ebx
movl 8(%ebp), %esi         variable x is initalized
movl 12(%ebp), %ecx        variable y is initalized
movl $2, %edx              variable mask is initalized
movl $-1, %eax             variable result is initalized 

.L2:
movl %esi, %ebx           esi(variable x) moved tp ebx
andl %edx, %ebx           x(now ebx) along with mask(edx) to ebx
xorl %ebx, %eax           ebx is now result(eax)
sall %cl, %edx            shift mask
cmpl $1, %edx			  comparing result ^= (x&mask)
jg .L2                    loop
popl %ebx                 epilogue
popl %esi
popl %ebp
ret
*/

#include <stdio.h>

int loop(int x,int y)
{
	int result =- 1;
	for(int mask = 2; mask > 1; mask = mask << y)
	{
		result ^= (x & mask);
	}
	return result;
}

// not using int argc, char *argv[]
int main(int argc, char *argv[])
{
	// testing function loop
    signed int test1 = loop(1,5);
    signed int test2 = loop(2,4);
    signed int test3 = loop(3,3);
    signed int test4 = loop(4,2);
    signed int test5 = loop(5,1);

    printf("%d\n", test1); 
    printf("%d\n", test2); 
    printf("%d\n", test3); 
    printf("%d\n", test4); 
	printf("%d\n", test5); 

	// not returning a value
	return 0;
}
