#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Help Credits: Lab (every lap session)

struct IntArray
{
    int length;
    int *dataPtr;
};

enum EXIT_CODES
{
    INVALID_POINTER = -1,
    BAD_DATA = -2
};

// function IntArray allocates, initializes, and returns an instance of the following struct
struct IntArray *mallocIntArray(int size)
{
    struct IntArray *num = NULL;

    // allocate 1 struct
    num = (struct IntArray *)malloc(sizeof(struct IntArray)); 
    num->length = size;
    num->dataPtr = (int *) malloc (sizeof(int) * size);
    for(int i=0; i < size; i++)
    {
        // placing the value 0 for every i
        num->dataPtr[i] = 0;             
    }
    // return pointer
    return num;                            
}

// function freeIntArray frees and nulls the instance’s dataPtr, zeroes out the length, frees and nulls the instance.

void freeIntArray(struct IntArray **arrayPtr)
{
    if ((arrayPtr != NULL) && ((*arrayPtr) != NULL) && ((*arrayPtr)->dataPtr != NULL))
    {
        for(int i=0; i < (*arrayPtr)->length; i++)
        {
            (*arrayPtr)->dataPtr[i] = 0;
        }
        free((*arrayPtr)->dataPtr);
        (*arrayPtr)->dataPtr = 0;
        (*arrayPtr)->length = 0;
        free((*arrayPtr));
        (*arrayPtr) = 0;
    }
    else
    {
        fprintf(stderr, "Invalid pointer found, Error.\n");
        exit(INVALID_POINTER);
    }
}

// function readIntArray collects ints from the user input 
void readIntArray(struct IntArray *array)    
{
    int count = 0;
    int length = array->length;
    for (; length > 0; length--)
    {
        printf("Enter int: ");
        int input;
        scanf("%d", &input);
        array->dataPtr[count] = input;
        count++;
    }
}

// function swap swaps the values of xp and yp
void swap(int *xp, int *yp) 
{
    int i0 = *xp;
    int i1 = *yp;
    *xp = i1;
    *yp = i0;
}

// function sortIntArray sorts array by calling function swap
void sortIntArray(struct IntArray *array)
{
    int length = array->length;
    int new = 1;
    int step = 0;
    while (new == 1)
    {
        new = 0;
        step++;
        for(int i = 0; i < length - step; i++)
        {
            if((array->dataPtr[i]) > (array->dataPtr[i+1]))
            {
                swap(&array->dataPtr[i], &array->dataPtr[i+1]);
                new = 1;
            }
        }
    }
}

// function printIntArray prints the array
void printIntArray(struct IntArray *array) 
{
    int length = array->length;
    for(int i = 0; i < length; i++)
    {
        printf("%d", array->dataPtr[i]);
        if(i < length - 1)
        {
            printf(", ");
        }
    }
}

// get int value from input, calls: mallocIntArray, readIntArray, sortArray, printArray, freeIntArray
// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    int length;
    printf("Enter length: ");
    scanf("%d", &length);
    struct IntArray  *inputArray = mallocIntArray(length);
    readIntArray(inputArray);
    sortIntArray(inputArray);
    printf("[");
    printIntArray(inputArray);
    printf("]\n");
    freeIntArray(&inputArray);
}