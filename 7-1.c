#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define N 4
typedef int array_t[N][N];

int dim() {
    return N;
}
// given function 
void f(array_t a, int x, int y) {
	for (int i = 0; i < dim(); ++i) {
		for (int j = 0; j < dim(); ++j) {
			a[i][j] = i * x * y + j;
		} 
	}
}

// new function minimizing unnecessary function calls and multiplication
void f1(array_t a, int x, int y) {
	int i, j, num;
	int length = dim();
	int new = x * y;

	for (int i = 0; i < length; ++i) {
		num = i * new;
		for (int j = 0; j < length; ++j) {
			a[i][j] = num + j;
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
	//testing my new function f1
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	f1(a,1,2);
	print_array(a);

    // not returning a value
    return 0;

}