#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#define size 100

using std::cout;
using std::cin;
using std::setw;

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
void generateMatrix(int arr[][size], int column[size], int n, int a, int b){
    cout << "\n";

    /*generate & output*/
    srand(time(0));
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            arr[iter][iter2] = a + rand() % (b - a);
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

void minSumDiagonal(int arr[][size], int n){
    int sum = 0, sum1 = 0, sum2 = 0, min1 = abs(arr[0][0]), min2 = abs(arr[n - 1][n - 1]);

    /*output 1 triangle*//*
    cout << "1 loop\n";
    for (int iter1 = 0; iter1 < n; ++iter1){
        for (int iter2 = 0; iter2 < n - iter1 - 1; ++iter2){
            cout << setw(4) << arr[iter1][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
*/
    /*outpu 2 triangle*//*
    cout << "2 loop\n";
    for (int iter = 1; iter < n; ++iter){
        for (int iter2 = n - iter; iter2 < n; ++iter2){
      	    cout << setw(4) << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
*/
    /* min sum 1 trian*/
    for (int iter1 = 0; iter1 < n - 1; ++iter1){
        sum = 0;
        for(int iter2 = 0, iter3 = iter1; iter2 <= iter1; ++iter2, --iter3){
            // cout << "Element " << arr[iter2][iter3] << '\n';
            sum += abs(arr[iter2][iter3]);
        }
        //cout << sum << "\n";
        if (sum < min1)
            min1 = sum;
    }
    //cout << min1 << '\n';

    /*min sum 2 trian*/
    for (int iter1 = n - 1; iter1 > 0; --iter1){
        sum = 0;
        for(int iter2 = n - 1, iter3 = iter1; iter2 >= iter1; --iter2, ++iter3){
            //cout << "Element " << arr[iter2][iter3] << '\n';
            sum += abs(arr[iter2][iter3]);
        }
        //cout << sum << "\n";
        if (sum < min2)
            min2 = sum;
    }
    //cout << min2 << '\n';

    if(min1 < min2)
        cout << "Minimal sum side diagonals: " << min1 << "\n";
    else
        cout << "Minimal sum side diagonals: " << min2 << "\n";

}

int main(){
    cout << "Start program ...\n";

    int arr[size][size], column[size];
    int n, select, a, b;

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
        cout << "Enter generate interval:\n";
        cin >> a >> b;
        generateMatrix(arr, column, n, a, b);

    cout << "Sum Columns: \n\n";
    uSumColumns(arr, column, n);
    cout << "\n\n";

    minSumDiagonal(arr, n);
    cout << "Program finished.\n";
    return 0;
}
