#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
//#define size 10000

using std::cout;
using std::cin;
using std::setw;

void generateMatrix(int n){
    cout << "\n";
    int arr[n][n];
    for(int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < n; ++iter2){
            arr[iter][iter2] = 10 - rand() % 20;
            cout << setw(4) << arr[iter][iter2] ;
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    cout << "Start program ...\n";
/*  
    int arr[size1][size2], m;
*/  int n;
    cout << "Enter size matrix N x N: ";
    cin >> n;

    generateMatrix(n);

    cout << "Program finished.\n";
    return 0;
}
