/*
.L3:
movl (%edx), %esi            pointer from %edx to %esi : t0 = *rp
movl (%eax), %ecx            pointer from %eax to %edx 
addl $4, %eax                add 4 to %eax : cp += N
addl $40, %edx               add 40 tp %edx : p += 1
movl %esi, -4(%eax)          move #esi to -4 %eax : *rp = cp
movl %ecx, -40(%edx)         move %ecx to %eax : *cp = 0
cmpl %ebx, %eax              compare %ebx to %eax : loop
jne .L3                      jump not equal
*/

// set to 4 to test in main
#define N 4
typedef int array_t[N][N];
#include <stdio.h>

void transpose(array_t a)
{

	for (int i = 0; i < N; ++i) {
		int *rp = &a[i][0];
		int *cp = &a[0][i];

		for (int j = 0; j < i; ++j) {
			// swap
			int t0 = *rp;
			*rp = *cp;
			*cp = t0;
			// increment
			rp += 1;
			cp += N;
		}
	} 
}

// function to print the array
void print_array(array_t A) {
	int i, j;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%4d",A[i][j]);
		}
		printf("\n");
	} 
}

// not using int argc, char *argv[]
int main(int argc, char *argv[])
{

	// testing function transpose
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	transpose(a);
	print_array(a);

	// not returning a value
	return 0;
}