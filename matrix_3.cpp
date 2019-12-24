/*
Для матрицы H = E − (v v^T) / ∣v∣^2, 
где Е – единичная матрица, а v = [ 1
                                   0
                                   1
                                   1 ],
проверить свойство ортогональности: Н^Т = Н − 1.
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;

FILE* stream, * stream2;

int main(){
    FILE* d;
    int** arr_E;

    fopen(&d, "input1.dat", "rb");
    arr_E = new int* [4];
    for (int i = 0; i < 4; i++) {
        arr_E[i] = new int[4];
        fread(arr_E[i], sizeof(int), 4, d);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr_E[i][j] << "\t";
        cout << '\n';
    }
    fclose(&d);

    double* x, a, *s;
    x = new double [4];
    s = new double[4];
    int size = 4;
    ifstream f;
    fopen("input.txt");
    
    for(int i = 0; i < 4; i++)
//for (int j = 0; j < 4; j++)
        if (f){
            f >> a; x[i] = a;
        }
    fclose();
    cout << '\n';
    
    for (int i = 0; i < 4; i++) {
//for (int j = 0; j < 4; j++)
        cout << x[i] << '\n';
//cout « endl;
    }
    int z;

    double** arr, dl;
    arr = new double* [4];
    for (int i = 0; i < 4; i++)
        arr[i] = new double[4];
        
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = x[i] * x[j];
        }
    }
    cout << '\n';
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << "\t";
        cout << '\n';
    }
    dl = sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3]) * sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3]);


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = arr[i][j] * 1 / dl;
        }
    }
    cout << '\n';
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << "\t";
        cout << '\n';
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = arr_E[i][j] - arr[i][j];
        }
    }
    cout << '\n';
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << "\t";
        cout << '\n';
    }

    double** arr1;
    arr1 = new double* [4];
    
    for (int i = 0; i < 4; i++)
        arr1[i] = new double[4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr1[i][j] = arr[j][i];
        }
    }
/*cout « endl;
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 4; j++)
cout « arr1[i][j] « "\t";
cout « endl;
}*/
    double** arr_v;
    arr_v = new double* [4];
    for (int i = 0; i < 4; i++)
        arr_v[i] = new double[4];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            arr_v[i][j] = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++)
                arr_v[i][j] += arr[i][k] * arr1[k][j];
        }
    }
    cout << '\n';
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr_v[i][j] << "\t";
        arr_v[i][j] = 0;
    }
    cout << '\n';
    }

    getchar(); 
    getchar();
    return 0;
}