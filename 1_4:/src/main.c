#include <stdio.h>
#include <stdlib.h>
#include <error.h>

typedef struct vector {
	int length;
	int *values;
}vector;

typedef struct matrix{
	int rows;
	int cols;
	int *values;
}matrix;

// init: inicializar vector
vector init_vec(int);
// mul: multiplicar vectores
int dot_vec(vector, vector);
// print_vec: escribir los valores
void print_vec(vector);
// sum_matrix: suma 2 matrices
matrix sum_matrix(matrix, matrix);

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

matrix sum_matrix(matrix a, matrix b){
	if(a.cols == b.cols && a.rows == b.rows){
		matrix ans = {
			.cols = a.cols,
			.rows = a.rows,
			.values = malloc(sizeof(int)*a.cols*b.cols)
		};
		for(int i=0; i< a.cols*a.rows; i++){
			ans.values[i] = a.values[i] + b.values[i];
		}
		//*(ans.values + a.cols*2 + 1) = 2; 
		return ans;
	} else{
		exit(1);
	}
}

matrix dot_matrix(matrix a, matrix b){
	if(a.cols == b.rows){
		matrix ans = {
			.rows = a.rows,
			.cols = b.cols,
			.values = malloc(sizeof(int)*a.rows*b.cols)
		};
		int rows = a.rows;
		int cols = b.cols;
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				int acc = 0;
				for(int pos=0; pos<cols; pos++){
					acc += a.values[0] * b.values[0];
				}
				ans.values[cols*i+j] = acc;
			}
		}
		return ans;
	} else{
		exit(1);
	}
}
