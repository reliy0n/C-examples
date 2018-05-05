#include <iostream>
#include <stdio.h>
#include <string.h>

typedef struct part{
	unsigned int  partNumber;
	char partName[25];
}Part;

int main(int argc, char** argv) {
	Part a; 
	Part b[10]; 
	Part *ptr;
	scanf("%d %24s",&a.partNumber,a.partName);
	b[3].partNumber = a.partNumber;
	strcpy(b[3].partName , a.partName);
	ptr = b;
	printf("%d %s", ptr[3].partNumber, ptr[3].partName);
	return 0;
}