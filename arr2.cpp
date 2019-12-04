/*
Задан массив целых чисел X(n). Шесть наибольших чисел этого массива переписать в
массив Z. Удалить из массива Z все четные числа. Вывести на экран элементы массива
Z в восьмеричной системе счисления.
*/

#include <iostream>
#include <cmath>
#include <climits>

#define size1 100
#define size2 200

using std::cout;
using std::cin;

/*function for enter array elements*/
void enterArray(int arr1[], int N){
    
    /*input*/
    for (int i = 0; i < N; ++i){
        cin >> arr1[i];
    }
    cout << '\n';

    /*output*/
    for (int i = 0; i < N; ++i){
        cout << arr1[i] << "  ";
    }
    
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(int arr1[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int i = 0; i < N; ++i){
        arr1[i] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr1[i] << "  ";
    }

    cout << '\n';
}

void findSixMax(int arr1[], int N, int arr_max[], int K){
    int max = INT_MAX;

    for (int i = 0; i < N; ++i){
        if (max > arr1[i]){
            max = arr1[i];
            arr_max[i] = max;
        }
        cout << arr_max[i] << ' ';       
    }
    cout << '\n';
}

/*menu & init variables*/
void initArrays(){
    int arr1[size1], arr2[size2], arr_max[size1];
    int N, K, cmd, a, b;
    
    cout << "Select array input method: \n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> cmd;
    cout << "Enter count elements: \n";
    cin >> N;

    switch (cmd) {
		case 1:
            enterArray(arr1, N);
            cout << '\n';
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
			generateArray(arr1, N, a, b);
            findSixMax(arr1, N, arr_max, K);
		break;
	}

}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    return 0;
    cout << "Progam finished.\n";
}