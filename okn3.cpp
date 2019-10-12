#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

void generateMatrix(int* arr[],int n, int m){
    for (int iter = 0; iter < n; ++iter){
        for(int iter2 = 0; iter2 < m; ++iter2){
            cout << arr[iter][iter2] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cout << "Start program ..." << "\n";
    const int size1 = 10000;
    const int size2 = 10000;
    int arr[size1][size2], n, m;

    cout << "Enter size matrix N x M: ";
    cin >> n >> m;

    generateMatrix(arr);

    return 0;
}
