#include <stdio.h>

void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}
void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}
void printShort(short x) {
    printBytes((unsigned char *) &x, sizeof(short));
}
void printLong(long x) {
    printBytes((unsigned char *) &x, sizeof(long));
}
void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}

// not using int argc, char *argv[] 
int main(int argc, char *argv[])
{
    //The output is in Hex form

    printInt(314); // byte size of 4
    //output: 3a 01 00 00
    
    printFloat(3.14); // byte size of 4
    //c3 f5 48 40
    
    printShort(3); // byte size of 2
    //output: 03 00
    
    printLong(314); // byte size of 8
    //output: 03 00 00 00 00 00 00 00
    
    printDouble(3.1); // byte size of 8
    //output: 00 00 00 00 00 00 08 40

    // not returning a value
    return 0;

}

