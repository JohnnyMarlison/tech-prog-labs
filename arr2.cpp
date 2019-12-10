/*
Задан массив целых чисел X(n). Шесть наибольших чисел этого массива переписать в
массив Z. DONE
Удалить из массива Z все четные числа. DONE
Вывести на экран элементы массива Z в восьмеричной системе счисления.
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

#define size1 100
#define size2 200

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

/*find six(and more) max in array through bubble sort*/
void sortDesc(int arr1[], int N, int arr_max[], int K){
    int tmp = 0, max = INT_MAX;
    bool flag = false;
    
    /*find six+- max in array*/
    while(!flag){
        flag = true;
        for (int j = 0; j < N - 1; j++){
            if(arr1[j] < arr1[j + 1]){
                tmp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = tmp;
                flag = false;
            }
        }
    }

    /*output*/
    for (int i = 0; i < K; ++i){
        arr_max[i] = arr1[i];
        cout << arr_max[i] << setw(4);;
    }
    cout << '\n';
}

/**/
int checkEven(int arr_max[], int K){
    int count_even = 0;

    for (int i = 0; i < K; i++){
        if (arr_max[i] % 2 == 0){
            count_even += 1;
        }
    }

    if (count_even == 0){
        return 0;
    }
    else{
        return 1;
    }
}

/*function for translate nums from decimal system to any nums system*/
unsigned long long int anyNS(unsigned long long int num, unsigned int ns){
    unsigned long long int S, P;

    for (S = 0, P = 1; num!= 0; S += num % ns * P, P *= 10, num /= ns);
        return S;
}

/*delete even elements*/
void delEven(int arr_max[], int K){

    if((checkEven(arr_max, K)) > 0){
        for (int i = 0; i < K;){
            if (arr_max[i] % 2 == 0){
                for (int j = i; j < K - 1; j++){
                    arr_max[j] = arr_max[j + 1];
                }
                K--;
            }
            else{
                i++;
            }
        }

        for (int i = 0; i < K; ++i)
            cout << arr_max[i] << setw(4);
        cout << '\n';
    }
    else{
        cout << "No even elements\n";
    }

    cout << "Octal system:\n"; 
    for (int i = 0; i < K; ++i){
        cout << anyNS(arr_max[i], 8) << " ";
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
            cout << '\n';
            cout << "Enter size max_array:\n";
            cin >> K;
			
            sortDesc(arr1, N, arr_max, K);
            delEven(arr_max, K);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            cout << "Enter size max_array:\n";
            cin >> K;
			
            generateArray(arr1, N, a, b);
            sortDesc(arr1, N, arr_max, K);
            delEven(arr_max, K);
           // outputOctal(arr_max, K);
		break;
	}

}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    cout << "Progam finished.\n";
    return 0;
}
