#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#define size 100

using std::cout;
using std::cin;
using std::setw;
/*
void enterMatrix(int arr[][size], int n){
    cout << "\n";
    int arr[n][n];
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            cin >> arr[iter][iter2];
            cout << setw(4) << arr[iter][iter2] ;
            cout << "  ";
            cout << iter << iter2;
        }
        cout << "\n";
    }
    cout << "\n";
}
*/
void generateMatrix(int arr[][size], int n){
    cout << "\n";
    srand(time(0));
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            arr[iter][iter2] = 10 - rand() % 20;
            cout << setw(4) << arr[iter][iter2] ;
            //cout << "  ";
            //cout << iter << iter2;
        }
        cout << "\n";
    }
    cout << "\n";
}

int uSumColumns(int arr[][size], int n){
    int sum = 0;
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            if(arr[iter2][iter] < 0 iter ){
                //sum = 0;
                ++iter2;
            }
            else if(arr[iter2][iter] >= 0 && arr[iter2 + 1][iter] >= 0)
                sum += arr[iter2][iter];
            else sum = 0;
        }
    }    

    return sum;
}

int main() {
    cout << "Start program ...\n";
    
    int arr[size][size];
    int n;
    cout << "Enter size matrix N x N: ";
    cin >> n;

    generateMatrix(arr, n);
    //enterMatrix(arr, n);
    cout << "Sum Columns = " << uSumColumns(arr, n) << "\n";

    cout << "Program finished.\n";
    return 0;
}
