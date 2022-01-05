#include<stdio.h>
#include<stdlib.h>

#define n 10

void init(void);
int sum(void);

int main(void){
	int *vec = malloc(sizeof(int)*n);
	printf("Char: %lu\n", sizeof(char));
	printf("Int: %lu\n", sizeof(int));
	printf("Float: %lu\n", sizeof(float));
	printf("Int pointer: %lu\n", sizeof(int *));
	return EXIT_SUCCESS;
}
