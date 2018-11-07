#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

// set size
#define cacheSize 16           

// cache block
struct Block {
    unsigned char offset[4];
    unsigned char valid;
    unsigned int tag;
};
 
// get functions for offset,set, and tag
unsigned int getOffset(unsigned int address){
    unsigned int offset = (address << 30)>>30;
    return offset;
}
unsigned int getSet(unsigned int address){
    unsigned int set = (address << 26)>>28;
    return set;
}
unsigned int getTag(unsigned int address){
    unsigned int tag = address >> 6;
    return tag;
}

// functions from 1-1.c to output
void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}
// function to read the hex value, help recevied 
int parseH(FILE *input) {
    unsigned int inputVal;
    scanf("%x", &inputVal);  
    while(getchar() != '\n');   
    return inputVal;
}

// function to initialize the values, help recevied 
struct Block *malloc_cache(int size) {
    struct Block *cache = NULL;
    cache = (struct Block *) malloc(sizeof(struct Block) * size);
    for(int i = 0; i < size; i++) {
        cache[i].valid = '0';      
        cache[i].tag = 0;
        cache[i].offset[0] = 0xbb;
        cache[i].offset[1] = 0xaa;
        cache[i].offset[2] = 0x0;
        cache[i].offset[3] = 0x0;
    }
    return cache;
}

int main() {
    char input;
    char validInput;       
    struct Block *cache = malloc_cache(cacheSize);
    do {
        
        printf("\nEnter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        input = getchar();
        
        // accepts characters othe than the necessary inputs
        // just will reprint the above printf line
        if (input == '\n') {              
            continue;
        }
        validInput = getchar();
        if (validInput != '\n') {           
            while (getchar() != '\n');      
            continue;
        }

        // write
        if (input == 'w'){
            printf("Enter 32-bit unsigned hex address: ");
            unsigned int address = parseH(stdin);
            printf("Enter 32-bit unsigned hex value: ");
            unsigned int value = parseH(stdin);

            // getting the tag, set, and offset
            unsigned int tag = getTag(address);
            unsigned int set = getSet(address);
            unsigned int offset = getOffset(address);

            if (cache[set].valid == '1') { 

                printf("evicting block - set: %u - tag: %u - valid: %c - value:",set,cache[set].tag,cache[set].valid);
                printInt(value);
                
            }
            // setting valid to 1
            cache[set].valid = '1';
            cache[set].tag = tag;

            // neat integers thanks to a mask, help recevied
            unsigned int mask = 0xFF;          
            cache[set].offset[0] = value & mask;
            cache[set].offset[1] = (value >> 8) & mask;
            cache[set].offset[2] = (value >> 16) & mask;
            cache[set].offset[3] = (value >> 24) & mask;
            printf("wrote set: %u - tag: %u - valid: %c - value:", set, tag, cache[set].valid);
            printInt(value);
            
        // read
        }else if (input == 'r'){

            printf("Enter 32-bit unsigned hex address: ");
            unsigned int address = parseH(stdin);
            unsigned tag = getTag(address);
            unsigned set = getSet(address);
            unsigned offset = getOffset(address);
            printf("looking for set: %u - tag: %u", set, tag);

            // checking for a hit or miss in the cache
            if (cache[set].valid == '1') {
                printf("\nfound set: %u - tag: %u - offset: %u - valid: %c - value: %.2x\n", set, tag, offset, cache[set].valid, cache[set].offset[offset]);
                if (tag == cache[set].tag)
                    printf("hit!");
                else
                    printf("tags don't match - miss!");
            }
            else
                printf("\nno valid set found - miss!");

        // print    
        }else if (input == 'p'){
            // loop to print the contents of the cache
            for (int i = 0; i < cacheSize; i++) {
                if (cache[i].valid == '1') {
                    printf("set: %d - tag: %d ", i, cache[i].tag);
                    printf("- valid: %c", cache[i].valid);
                    printf("- value: %.2x %.2x %.2x %.2x\n", cache[i].offset[0], cache[i].offset[1], cache[i].offset[2], cache[i].offset[3]);
                }
            }// end for loop
            
        }
    } while(input != 'q');
    return 0;
}