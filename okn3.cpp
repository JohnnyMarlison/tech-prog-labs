#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#define size 100

using std::cout;
using std::cin;
using std::setw;
using std::memset;

/*function for enter matrix elements*/
void enterMatrix(int arr[][size], int column[size], int n){
    cout << "\n";

    /*input*/
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            cin >> arr[iter][iter2];
        }
        cout << "\n";
    }
    cout << "\n";

    /*output*/
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*function generate matrix with rand*/
void generateMatrix(int arr[][size], int column[size], int n){
    cout << "\n";

    /*generate & output*/
    srand(time(0));
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            arr[iter][iter2] = 10 - rand() % 20;
            cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/*function sum for columns*/
void uSumColumns(int arr[][size], int column[size], int n){
    /*find*/
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            if(arr[iter2][iter] >= 0)
                column[iter] += arr[iter2][iter];
            else{
                column[iter] = 0;
                break;
            }
        }
    }
    /*output*/
    for (int iter = 0; iter < n; ++iter)
        if(column[iter] != 0)
            cout << setw(4) << column[iter] << " ";
        else
            cout << setw(5) << "-";
}

/*Minimal sum side diagonals*//*
void minSumDiagonal1(int arr[][size], int n){
    int diagonals = abs(arr[0][n - 1]);
    int t1, t2;
    for(int iter = 1; iter < n; ++iter){
        t1 = t2 = 0;
        for(int iter2 = 0; iter2 < n - iter; ++iter2){
            t1 += abs(arr[iter + iter2][iter2]);
            t2 += abs(arr[iter2][iter + iter2]);
        }
        if (t1 < diagonals)
            diagonals = t1;
        if (t1 < diagonals)
            diagonals = t2;
    }
    cout << "Minimal sum side diagonals: " << diagonals << "\n";
}
*/
/*Minimal sum side diagonals*/
void minSumDiagonal2(int arr[][size], int n){
    int count;
    int diagonals[n];
    memset(diagonals, 0, sizeof(diagonals));
    for(count = 0; count < n; ++count){
        for(int iter1 = 0; iter1 < n; ++iter1){
            for(int iter2 = 0; iter2 < n; ++iter2){
                if (count == iter1 + iter2)
                    diagonals[count] += abs(arr[iter1][iter2]);
            }
        }
    }
    int min = diagonals[0];
    for (count = 0; count < n; ++count){
        if ((count != n / 2 - 1) && min > diagonals[count])
            min = diagonals[count];
    }
    cout << "Minimal sum side diagonals: " << min << "\n";
}

/*
void minSumDiagonal1(int arr[][size], int n){
    int diagonals = abs(arr[n][0]);
    int t1, t2;
    for(int iter = 0; iter < n ; ++iter){
        t1 = t2 = 0;
        for(int iter2 = 1; iter2 < n - iter; ++iter2){
            t1 += abs(arr[iter - iter2][iter2]);
            t2 += abs(arr[iter2][iter + iter2]);
        }
        if (t1 < diagonals)
            diagonals = t1;
        if (t1 < diagonals)
            diagonals = t2;
    }
    cout << "Minimal sum side diagonals: " << diagonals << "\n";
}
*/

int main(){
    cout << "Start program ...\n";

    int arr[size][size], column[size];
    int n, select;

    /*choose input matrix*/
    cout << "Select matrix input method: \n\n";
    cout << "1 - Enter matrix \n";
    cout << "2 - Generate matrix \n";
    cin >> select;
    cout << "Enter size matrix N x N: ";
    cin >> n;

    /*functions*/
    if (select == 1)
        enterMatrix(arr, column, n);
    if (select == 2)
        generateMatrix(arr, column, n);

    cout << "Sum Columns: \n\n";
    uSumColumns(arr, column, n);
    cout << "\n\n";

    //minSumDiagonal1(arr, n);
    minSumDiagonal2(arr, n);
    cout << "Program finished.\n";
    return 0;
}
