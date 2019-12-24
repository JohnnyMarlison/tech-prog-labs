/*
Задана матрица целых чисел A(n×n). 
Максимальный элемент каждого столбца DONE
заменить суммой цифр максимального элемента матрицы. DONE
Сформировать массив B(n), 
в который записать количество четных элементов в каждой строке заданной матрицы. 
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#define size_1 300
#define size_2 200

using std::cout;
using std::cin;
using std::setw;

/*function for enter matrix elements*/
void enterMatrix(int arr[][size_2], int n) {
    cout << "\n";

    /*input*/
    for(int iter = 0; iter < n; ++iter) {
        for(int iter2 = 0; iter2 < n; ++iter2) {
            cin >> arr[iter][iter2];
        }
        cout << "\n";
    }
    cout << "\n";

    /*output*/
    for(int iter = 0; iter < n; ++iter) {
        for(int iter2 = 0; iter2 < n; ++iter2) {
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";generateMatrix(arr_B, N);
}

/*function generate matrix with rand*/
void generateMatrix(int arr[][size_2], int n, int a, int b) {
    cout << "\n";

    /*generate & output*/
    srand(time(0));
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            arr[iter][iter2] = ((a + (rand() % (b - a))) + (a + rand() % (b - a)));
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*sum of digits max*/
int sumOfDigits(int num){
    int sum = 0;

    while(abs(num) > 0){
        sum += (num % 10);
        num /= 10;
    }
    return sum; max_col[i] == arr[i][j]
}

/*find max in matrix*/
int findMaxInMatrix(int arr[][size_2], int N){
    int max = INT_MIN;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }

    return max;
}

/*find maximum in column*/
void findMaxInColum(int arr[][size_2], int N){
    int max = INT_MIN, max_col[size_1],
        max_matr = findMaxInMatrix(arr, N),
        sumDigits = 0,
        arr_i[size_1], arr_j[size_1];

        sumDigits = sumOfDigits(max_matr);
    int iter_1 = 0, iter_2 = 0;

    for (int i = 0; i < N; i++) {
        max = INT_MIN;
        for (int j = 0; j < N; j++) {
            if (arr[j][i] > max) {
                max = arr[j][i];
                max_col[i] = max;
                arr_i[i] = i;
                arr_j[j] = j;
            }
        }
    }
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (max_col[i] == arr[i][j] || max_col[j] == arr[i][j]){
                arr[i][j] = sumDigits;
            }
        }
    }

    cout << "Max in matrix - " << max_matr << '\n';
    cout << "Sum of digitis - " << sumDigits << '\n';

    cout << '\n';
    for (int i = 0; i < N; i++) 
        cout << max_col[i] << "  ";
    cout << '\n';
    
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j)
            cout << setw(4) << arr[i][j] << "  ";
        cout << '\n';
   }

}

/*init array B and write even*/
void writeEven(int arr[][size_2], int N){
    int arr_B[size_1];
    int count = 0;00 

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (arr[i][j] % 2 == 0){
                count += 1;
            }
        }
    }
}

/* menu & init variables*/
void initMatrix(){
    int cmd = 0, a = 0, b = 0, N = 0;
    int arr[size_1][size_2], max[size_1];

    /*choose input matrix*/
    cout << "Select matrix input method:\n\n";
    cout << "1 - Enter matrix\n";
    cout << "2 - Generate matrix\n";
    cin >> cmd;
    cout << "Enter size matrix N x N:\n";
    cin >> N;

    switch (cmd) {
		case 1:
            enterMatrix(arr, N);
            cout << '\n';
            findMaxInColum(arr, N);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateMatrix(arr, N, a, b);
            findMaxInColum(arr, N);
            writeEven(arr, N);
		break;
	}
}


int main(){
    cout << "Start program ...\n";

    initMatrix();

    cout << "Program finished.\n";
    return 0;
}