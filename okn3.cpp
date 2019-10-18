#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#define size 100

using std::cout;
using std::cin;
using std::setw;

/*function for enter matrix elements*/
void enterMatrix(int arr[][size], int n){
    cout << "\n";
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            cin >> arr[iter][iter2];
            cout << setw(4) << arr[iter][iter2] ;
            // cout << "  ";
            // cout << iter << iter2;
        }
        cout << "\n";
    }
    cout << "\n";
}

/*function generate matrix with rand*/
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

/*function sum for columns*/
int uSumColumns(int arr[][size], int n, int sum){
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            sum += arr[iter2][iter];
        }
    }    
    if(sum == abs(sum))
        return sum;
    else 
        return 0;

    //return sum;
}


int main(){
    cout << "Start program ...\n";
    
    int arr[size][size];
    int n, select, sum;

    cout << "Select matrix input method: \n\n";
    cout << "1 - Enter matrix \n";
    cout << "2 - Generate matrix \n";
    cin >> select;
    cout << "Enter size matrix N x N: ";
    cin >> n;

    if (select == 1)
        enterMatrix(arr, n);
    if (select == 2)
        generateMatrix(arr, n);

    cout << "Sum Columns = " << uSumColumns(arr, n, sum) << "\n";
    cout << "Program finished.\n";
    return 0;
}
