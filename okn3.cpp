#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#define size 100

using std::cout;
using std::cin;
using std::setw;

/*function for enter matrix elements*/
void enterMatrix(int arr[][size], int column[size], int n){
    cout << "\n";
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            cin >> arr[iter][iter2];
        }
        cout << "\n";
    }
    cout << "\n";

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
void uSumColumns(int arr[][size], int column[size], int n, int sum){
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
    
    for (int iter = 0; iter < n; ++iter)
        if(column[iter] != 0)
            cout << setw(4) << column[iter] << " ";
        else
            cout << setw(5) << " ";
}

int main(){
    cout << "Start program ...\n";
    
    int arr[size][size], column[size];
    int n, select, sum = 0, step = 1;

    /*choose input matrix*/
    cout << "Select matrix input method: \n\n";
    cout << "1 - Enter matrix \n";
    cout << "2 - Generate matrix \n";
    cin >> select;
    cout << "Enter size matrix N x N: ";
    cin >> n;

    if (select == 1)
        enterMatrix(arr, column, n);
    if (select == 2)
        generateMatrix(arr, column, n);

    //cout << "Sum Columns = " << uSumColumns(arr, column, n, sum) << "\n";
    uSumColumns(arr, column, n, sum);
    cout << "\n";

    cout << "Program finished.\n";
    return 0;
}
