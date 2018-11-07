#include <stdio.h>
#include <stdlib.h>

struct Block
{
	unsigned char value[4];
	unsigned int tag;
	unsigned char valid;
};

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

void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}

int main(int argc, char const *argv[])
{
	struct Block *cache = (struct Block*) malloc(16*sizeof(struct Block));

	char buffer[256];
	char input;
	do {
		printf("\nEnter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
		fgets(buffer, 256, stdin);
		input = buffer[0];

		if (input == 'w'){

			//char buff[256];
			unsigned int address;
        	unsigned int value;

            printf("Enter 32 - bit unsigned hex address: ");
            scanf(" %x", &address);
            //fgets(buffer, 256, stdin);
            //unsigned int address = stroul(buffer, NULL, 16);

            printf("Enter 32 - bit unsigned hex value: ");
            scanf(" %x", &value);
           //fgets(buffer, 256, stdin);
            //unsigned int value = stroul(buffer, NULL, 16);

            unsigned int offset = getOffset(address);
            unsigned int set = getSet(address);
            unsigned int tag = getTag(address);

            struct Block *block = &cache[set];

            
            printf("wrote set: %d ", set);
            printf("- tag: %d ", tag);
            printf("- valid: 1 - value:");
            printInt(value);
		} else if (input == 'p'){
			for (int i = 0; i <= 16; i++){
				printf("value: %s\n", cache[i].value);
			}
			
		}
	} while (input != 'q');
	printf("done");
	return 0;
}