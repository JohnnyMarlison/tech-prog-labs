#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

int** generate_matrix(int size) {
	int** res = new int*[size];
	for (int i = 0; i < size; ++i) {
		res[i] = new int[size];
		for (int j = 0; j < size; ++j) {
			res[i][j] = rand() % 100;
		}
	}
	return res;
}

void remove_matrix(int** mat, int size) {
	for (int i = 0; i < size; ++i)
		delete [] mat[i];
	delete [] mat;
}

void multiple(int size) {
	int** m1 = generate_matrix(size);
	int** m2 = generate_matrix(size);
	int** res = generate_matrix(size);
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	long int cb;

	cb = clock();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			for (int k = 0; k < size; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << "  ";
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	
    cb = clock();
	
    for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size; ++i) {
			for (int k = 0; k < size; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << "  ";
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	
    cb = clock();
	
    for (int k = 0; k < size; ++k) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << "  ";
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	
    cb = clock();
	
    for (int i = 0; i < size; ++i) {
		for (int k = 0; k < size; ++k) {
			for (int j = 0; j < size; ++j) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << "  ";
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	
    cb = clock();
	
    for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size; ++i) {
			for (int k = 0; k < size; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << "  ";
	
    for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = 0;

	
    cb = clock();
	
    for (int k = 0; k < size; ++k) {
		for (int j = 0; j < size; ++j) {
			for (int i = 0; i < size; ++i) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
    cout << (clock() - cb) / 1000000.0 << endl;

	remove_matrix(res, size);
	remove_matrix(m1, size);
	remove_matrix(m2, size);
}

int main() {
	srand(time(NULL));
	int size = 500;
	cout << "  ijk       jik       kij       ikj       jik       kji" << endl;
	
    for (int i = 0; i < 3; ++i) {
		multiple(size);
		size *= 2;
	}
	return 0;
}