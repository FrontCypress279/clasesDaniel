#include <stdio.h>
#include <stdlib.h>

int counter(void){
	static int i; // 
	i++;
	return i;
}

int main(void){
	for (int i=0; i < 5; i++){
		printf("Val: %d\n", counter());
	}
	return EXIT_SUCCESS;
}
