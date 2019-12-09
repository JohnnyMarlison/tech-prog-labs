/*
Из массива целых чисел удалить предпоследнюю группу, состоящую из возрастающей
последовательности цифр.
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

#define size 100

using std::cout;
using std::cin;
using std::setw;

/*function for enter array elements*/
void enterArray(int arr1[], int N){
    
    /*input*/
    for (int i = 0; i < N; ++i){
        cin >> arr1[i];
    }
    cout << '\n';

    /*output*/
    for (int i = 0; i < N; ++i){
        cout << arr1[i] << setw(4);
/*menu & init variables*/
    }
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(int arr1[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int i = 0; i < N; ++i){
        arr1[i] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr1[i] << setw(4);
    }

    cout << '\n';
}
 /*find last negative*/
int lastNegative(int arr[], int N){
    
    for (int i = N; i > 0; --i){
        if (arr[i] < 0){
            return i;
            //break;
        }
    }
}

bool findPalid(int arr[], int N){
    int tmp = 0, rev_num;
/*
    if (num % 10 == 0 && c >= 10)
        return false; //nums ended on 0 not palindrom?
    if (num < 10 && num >= 0)
        return true; //if nums of one number?
*/
    for (int i = 0; i < N; ++i){
        while (tmp != 0){
            rev_num = rev_num * 10 + tmp % 10;
            tmp /= 10;
        }
    }
    if (num == tmp){
        return true; 
    }
    else{
        return false;
    }
}

/*find first palindrom*//*
bool findPalid(int num){
    int tmp = num, rev_num;

    if (num % 10 == 0 && c >= 10)
        return false; //nums ended on 0 not palindrom?
    if (num < 10 && num >= 0)
        return true; //if nums of one number?

    while (tmp != 0){
        rev_num *= 10;   
        rev_num += tmp%10;
        tmp = tmp/10;
    }
    return (c == rev_c);
}
*/
/*menu & init variables*/

void delElems(int arr[], int N){
    cout << lastNegative(arr, N) << '\n';
    cout << lastNegative(arr, N) << '\n';
}

void initArrays(){
    int arr[size];
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
            delElems(arr, N);
		break;
	}
}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    cout << "Progam finished.\n";
    return 0;
}
