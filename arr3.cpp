/*
Из массива целых чисел удалить предпоследнюю группу, состоящую из возрастающей
последовательности цифр.
*/
#include <iostream>
#include <cmath>
#include <climits>

#define size 100

using std::cout;
using std::cin;

/*function for enter array elements*/
void enterArray(int arr[], int N){
    
    /*input*/
    for (int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    cout << '\n';

    /*output*/
    for (int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(int arr[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int i = 0; i < N; ++i){
        arr[i] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr[i] << " ";
    }
    cout << '\n';
   
    /*
    for(int i = 0; i < N; ++i)
        cout << i << " ";
    cout << '\n';
    */
}

/*find increas num in nums*/
bool increasNum(int nums){
    int prev = nums % 10;
    nums /= 10;

    while (nums) {
        if (prev <= nums % 10)
            return false;
        
        prev = nums % 10;
        nums /= 10;
    }
    return true;
}

/*find increas num in nums*/
void lastGroup(int arr[], int N) {
    int flag_group = 0, first_group = 0, second_group = 0;

    for (int i = N; i > 0; --i) {
        if(flag_group == 0){

        }
    }
}

/*menu & init variables*/
void initArrays(){
    int arr[size];
    int N, K, cmd, a, b;
    
    cout << "Select array input method:\n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> cmd;
    cout << "Enter count elements: \n";
    cin >> N;

    switch (cmd) {
		case 1:
            enterArray(arr, N); cout << '\n';
			lastGroup(arr, N);
		break;

		case 2:/*menu & init variables*/
            cout << "Enter generate interval:\n";
            cin >> a >> b; cout << '\n';
            generateArray(arr, N, a, b);
            lastGroup(arr, N);
		break;
	}
}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    cout << "Progam finished.\n";
    return 0;
}