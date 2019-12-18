/*
В двумерном массиве B, состоящем из n×m вещественных чисел вычислить:
• произведение элементов;
• сумму положительных элементов;
• два наименьших значения среди расположенных выше побочной диагонали.
Для заданной матрицы B(n×m) и матрицы того же типа, но другой размерности
С(m×k) найти значение выражения A=3⋅B⋅C
*/
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#define size_1 300
#define size_2 200

using std::cout;
using std::cin;
using std::setw;

/*function for enter matrix elements*/
void enterMatrix(float arr[][size_2], int n, int m){
    cout << "\n";

    /*input*/
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < m; ++iter2){
            cin >> arr[iter][iter2];
        }
        cout << "\n";
    }
    cout << "\n";

    /*output*/
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < m; ++iter2){
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*function generate matrix with rand*/
void generateMatrix(float arr[][size_2], int n, int m, int a, int b){
    cout << "\n";

    /*generate & output*/
    srand(time(0));
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < m; ++iter2){
            arr[iter][iter2] = ((a + (rand() % (b - a))) + (a + rand() % (b - a)));
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*composition elements in matrix*/
void composElem(float arr[][size_2], int n, int m){
    float composition = 1;

    for (int iter = 0; iter < n; ++iter)
        for (int iter2 = 0; iter2 < m; ++iter2) 
            composition *= arr[iter][iter2];

    cout << "Composition:\n" << composition << '\n';
}

/* sum positive elements in matrix*/
void unsigSumElem(float arr[][size_2], int n, int m){
    float sum = 0;

    for (int iter = 0; iter < n; ++iter)
        for (int iter2 = 0; iter2 < m; ++iter2) 
            if (arr[iter][iter2] > 0)
                sum += arr[iter][iter2];

    cout << "Sum:\n" << sum << '\n';
}

/*menu & init variables*/
void initMatrix(){
    float arr1[size_1][size_2], arr2[size_1][size_2];
    int N, M, cmd, a, b;
    
    /*choose input matrix*/
    cout << "Select matrix input method:\n\n";
    cout << "1 - Enter matrix\n";
    cout << "2 - Generate matrix\n";
    cin >> cmd;
    cout << "Enter size matrix N x M:\n";
    cin >> N >> M;

    switch (cmd) {
		case 1:
            enterMatrix(arr1, N, M);
            cout << '\n';
            composElem(arr1, N, M);
            unsigSumElem(arr1, N, M);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateMatrix(arr1, N, M, a, b);
            composElem(arr1, N, M);
            unsigSumElem(arr1, N, M);
		break;
	}
}


int main(){
    cout << "Start program ...\n";

    initMatrix();

    cout << "Program finished.\n";
    return 0;
}