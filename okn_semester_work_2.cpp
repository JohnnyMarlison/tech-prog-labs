#include <iostream>
#include <stdio.h>
#include <cstring>

using std::cin;
using std::cout;

const int count_algorithms = 2;

#define REG_INT

#ifndef REG_INT
	#define fori(n) for (int i = 0; i < (n); ++i)
	#define forj(n) for (int j = 0; j < (n); ++j)
	#define fork(n) for (int k = 0; k < (n); ++k)
#else
	#define fori(n) for (register int i = 0; i < (n); ++i)
	#define forj(n) for (register int j = 0; j < (n); ++j)
	#define fork(n) for (register int k = 0; k < (n); ++k)
#endif

typedef enum Case {
	NICE_CASE =   0U,
	BAD_CASE =    1U,
	RANDOM_CASE = 2U,
	NOTHING =     3U
} case_t;

int len_number(int i) {
	int len = 0;
	while (i) {
		i /= 10;
		++len;
	}
	return len;
}

void print_table_line(int max_size, int max_len_f) {
	printf("+");
	fori(len_number(max_size)) printf("-");
	printf("+");
	fori(count_algorithms) {
		forj(max_len_f + 1) 
			printf("-");
		printf("+");
	}
	printf("\n");
}

void print_table_head(int max_size, int max_len_f) {
	print_table_line(max_size, max_len_f);
	printf("|");
	fori(len_number(max_size)) printf("/"); printf("|");
	int count_it_f_b = (max_len_f - 1) / 2;
	int count_it_f_e = count_it_f_b + !((max_len_f - 2) % 2);

	forj(count_it_f_b) 
		printf(" ");
	printf("bs");
	forj(count_it_f_e) 
		printf(" ");
	printf("|");

	forj(count_it_f_b) 
		printf(" ");
	printf("is");
	forj(count_it_f_e) 
		printf(" ");
	printf("|\n");

	print_table_line(max_size, max_len_f);
}

void print_time_matrix(long int** mat, int count, int begin_size) {
	printf("\n");
	int max_len_f = 0;
	int max_size = begin_size;
	fori(count) {
		max_size *= 2;
		forj(count_algorithms) {
			char data[100];
			snprintf(data, 100, "%f", mat[i][j] / 1000000.0);
			if (max_len_f < strlen(data))
				max_len_f = strlen(data);
		}
	}
	max_size /= 2;
	char format_str_f[20];
	char format_iter_str[10];
	snprintf(format_str_f, 20, "%%%df", max_len_f + 1);
	snprintf(format_iter_str, 10, "%%%dd|", len_number(max_size));

	print_table_head(max_size, max_len_f);

	fori(count) {
		printf("|");
		printf(format_iter_str, begin_size);
		begin_size *= 2;
		forj(count_algorithms) {
			printf(format_str_f, mat[i][j] / 1000000.0);
			printf("|");
		}
		printf("\n");
		print_table_line(max_size, max_len_f);
	}
	printf("\n");
}

int* generate_array(int size, case_t ch) {
	int* res = (int*)calloc(size, sizeof(int));
	switch (ch) {
		case NICE_CASE:
			fori(size) 
				res[i] = i;
		break;

		case BAD_CASE:
			fori(size) 
				res[i] = size - i;
		break;

		case RANDOM_CASE:
			fori(size) 
				res[i] = rand() % 100;
		break;

		case NOTHING:

		break;
	}		
	return res;
}

void remove_array(int* mat, int size) {
	free(mat);
}

void remove_matrix(long int** mat, int size) {
	fori(size) 
		free(mat[i]);
	free(mat);
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubble_sort(int* arr, int n) { 
   	int i, j; 
   	bool swapped; 
   	for (i = 0; i < n - 1; i++) { 
	    swapped = false; 
	    for (j = 0; j < n - i - 1; j++) { 
	        if (arr[j] > arr[j + 1]) { 
	           swap(&arr[j], &arr[j + 1]); 
	           swapped = true; 
	        } 
	    } 
	    if (swapped == false) 
	        break; 
   } 
} 

void insertion_sort(int* arr, int n) {  
	for(int i = 1; i < n; i++)
		for(int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
				swap(&arr[j - 1], &arr[j]);
}  

long int* sort(int size, case_t ch) {
	long int cb = clock();
	int* m1 = generate_array(size, ch);
	printf("Generate time for size = %d: %f\n", size, (clock() - cb) / 1000000.0);
	int* m2 = generate_array(size, NOTHING);
	memcpy(m2, m1, size * sizeof(int));

	long int* time_array = (long int*)calloc(count_algorithms, sizeof(long int));
	int it = 0;

	cb = clock();
	bubble_sort(m1, size);
	time_array[it++] = clock() - cb;

	cb = clock();
	insertion_sort(m2, size);
	time_array[it++] = clock() - cb;

	remove_array(m1, size);
	remove_array(m2, size);

	return time_array;
}

int main() {
	long int program_time = clock();
	srand(time(NULL));
	int count_test, size;
	long int** time_mat;
	printf("Enter begin size: ");
	scanf("%d", &size);
	printf("Enter count of tests: ");
	scanf("%d", &count_test);
	int begin_size = size;

	time_mat = (long int**)calloc(count_test, sizeof(long int**));
	printf("\nFor nice case\n");
	fori(count_test) {
		time_mat[i] = sort(size, NICE_CASE);
		printf("Calculated for size = %d\n", size);
		size *= 2;
	}
	print_time_matrix(time_mat, count_test, begin_size);
	remove_matrix(time_mat, count_algorithms);

	time_mat = (long int**)calloc(count_test, sizeof(long int**));
	printf("\nFor bad case\n");
	size = begin_size;
	fori(count_test) {
		time_mat[i] = sort(size, BAD_CASE);
		printf("Calculated for size = %d\n", size);
		size *= 2;
	}
	print_time_matrix(time_mat, count_test, begin_size);
	remove_matrix(time_mat, count_algorithms);

	time_mat = (long int**)calloc(count_test, sizeof(long int**));
	printf("\nFor random case\n");
	size = begin_size;
	fori(count_test) {
		time_mat[i] = sort(size, RANDOM_CASE);
		printf("Calculated for size = %d\n", size);
		size *= 2;
	}
	print_time_matrix(time_mat, count_test, begin_size);
	remove_matrix(time_mat, count_algorithms);

	long int output_time = clock();
	printf("Output time: %f sec\n", (clock() - output_time) / 1000000.0);
	printf("Summary time: %f sec\n\n", (clock() - program_time) / 1000000.0);
	return 0;
}