/*
Задан массив целых чисел X(n). Шесть наибольших чисел этого массива переписать в
массив Z. Удалить из массива Z все четные числа. Вывести на экран элементы массива
Z в восьмеричной системе счисления.
*/

#include <iostream>
#include <cmath>

#define size1 100
#define size2 200

using std::cout;
using std::cin;

/*function for enter array elements*/
void enterArray(int arr1[], int N){
    
    /*input*/
    for (int iter = 0; iter < N; ++iter){
        cin >> arr1[iter];
    }
    cout << '\n';

    /*output*/
    for (int iter = 0; iter < N; ++iter){
        cout << arr1[iter] << "  ";
    }
    
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(int arr1[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int iter = 0; iter < N; ++iter){
        arr1[iter] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr1[iter] << "  ";
    }

    cout << '\n';
}

/*menu & inin variables*/
void initArrays(){
    int arr1[size1], arr2[size2], arr_max[size1];
    int N, K, cmd,a, b;
    
    cout << "Select array input method: \n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> cmd;
    cout << "Enter count elements: \n";
    cin >> N;

    switch (cmd) {
		case 1:
            enterArray(arr1, N);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
			generateArray(arr1, N, a, b);
		break;
	}

}

int main(){
    cout << "Start program ...\n";

    initArrays();
    

    return 0;
    cout << "Progam finished.\n";
}