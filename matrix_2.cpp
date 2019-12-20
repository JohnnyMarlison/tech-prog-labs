/*
Задана матрица целых чисел A(n×n). 
Максимальный элемент каждого столбца
заменить суммой цифр максимального элемента матрицы.
Сформировать массив B(n), 
в который записать количество четных элементов в каждой строке заданной матрицы. 
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
void enterMatrix(int arr[][size_2], int n, int m) {
    cout << "\n";

    /*input*/
    for(int iter = 0; iter < n; ++iter) {
        for(int iter2 = 0; iter2 < m; ++iter2) {
            cin >> arr[iter][iter2];
        }
        cout << "\n";
    }
    cout << "\n";

    /*output*/
    for(int iter = 0; iter < n; ++iter) {
        for(int iter2 = 0; iter2 < m; ++iter2) {
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*function generate matrix with rand*/
void generateMatrix(int arr[][size_2], int n, int m, int a, int b) {
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

void findMaxInColum(int arr[][size_2], int N){
    int max 

}

/* menu & init variables*/
void initMatrix(){
    int K = 0, cmd = 0, a = 0, b = 0;
    int arr[size_1][size_2], int arr[size_1];

    /*choose input matrix*/
    cout << "Select matrix input method:\n\n";
    cout << "1 - Enter matrix\n";
    cout << "2 - Generate matrix\n";
    cin >> cmd;
    cout << "Enter size matrix N x M:\n";
    cin >> N;

    switch (cmd) {
		case 1:
            enterMatrix(arr1, N, M);
            cout << '\n';
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateMatrix(arr1, N, M, a, b);
		break;
	}
}


int main(){
    cout << "Start program ...\n";

    initMatrix();

    cout << "Program finished.\n";
    return 0;
}