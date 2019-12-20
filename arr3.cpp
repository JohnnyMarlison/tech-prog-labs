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
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cout << '\n';

    /*output*/
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
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
    int indb_1 = 0, inde_1 = 0,
        indb_2 = 0, inde_2 = 0,
        flag_group = 0, first_group = 0, second_group = 0,
        flag_first_found = 0;

    for (int iter = N - 1; iter >= 0; --iter) {
        if (!first_group) {
            if (!flag_group && increasNum(arr[iter])) {
                indb_1 = iter;
                flag_group = 1;
            }
            if (flag_group && !increasNum(arr[iter])) {
                inde_1 = iter + 1;
                if (inde_1 - indb_1) {
                    first_group = 1;
                } 
                else {
                    indb_1 = 0;
                    inde_1 = 0;
                }
                flag_group = 0;
            }
        }
        if (first_group && !second_group) {
            if (first_group && !flag_group && increasNum(arr[iter])) {
                indb_2 = iter;
                flag_group = 1;
            }
            if (flag_group && !increasNum(arr[iter])) {
                inde_2 = iter + 1;
                if (inde_2 - indb_2){
                    second_group = 1;
                }
                else{
                    indb_2 = 0;
                    inde_2 = 0;
                } 
                flag_group = 0;
            }
        }
    }

    if (indb_1)
        cout << "Find first group index: " << inde_1 << " " << indb_1 << "\n";
    if (indb_2)
        cout << "Find second group index: " << inde_2 << " " << indb_2 << "\n";
    else
        cout << "Group not found\n"; 
    
    cout << "\n\n";
    int diff = indb_2 - inde_2;
    int iter = 0;

        if (indb_2 - inde_2) {
            N--;
            for (inde_2;inde_2 < indb_2; inde_2++)
                arr[inde_2] = arr[inde_2 + 1];
        }

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";

    cout << "\n\n";
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