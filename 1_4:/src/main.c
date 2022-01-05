#include <stdio.h>
#include <stdlib.h>
#include <error.h>

typedef struct vector {
	int length;
	int *values;
}vector;

// init: inicializar vector
vector init_vec(int);
// mul: multiplicar vectores
int dot_vec(vector, vector);
// print_vec: escribir los valores
void print_vec(vector);

int main(int argc, char **argv) {
	printf("Hello %s!\n", argv[1]);
	vector vec_a = init_vec(3);
	vector vec_b = init_vec(3);
	print_vec(vec_a);
	print_vec(vec_b);
	int answer = dot_vec(vec_a, vec_b);
	printf("Dot product: %d\n", answer);
	return EXIT_SUCCESS;
}

vector init_vec(int n) {
	vector new_vec = { .values = malloc(sizeof(int)*n) };
	int val;
	for (int i=0; i<n; i++) {
		printf("Vec[%d]: ", i);
		scanf("%d", &val);
		new_vec.values[i] = val;
		new_vec.length += 1;
		printf("Length: %d\n", new_vec.length);
	}
	return new_vec;
}

void print_vec(vector vec) {
	for (int i=0; i<vec.length; i++) {
		printf("%d, ", vec.values[i]);
	}
	printf("\n");
}

int dot_vec(vector a, vector b) {
	int answer = 0;
	if (a.length == b.length) {
		for (int i=0; i<a.length; i++) {
			answer += a.values[i]*b.values[i];
		}
		return answer;
	} else {
		error(1, 1, "Vectors not equal");
		exit(1);
	}
}
