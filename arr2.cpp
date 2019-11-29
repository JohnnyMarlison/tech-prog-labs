/*Задан массив целых чисел X(n). Шесть наибольших чисел этого массива переписать в
массив Z. Удалить из массива Z все четные числа. Вывести на экран элементы массива
Z в восьмеричной системе счисления*/
#include<iostream>
#include<ctime>
#include <limits.h>

#define size1 100
#define size2 200

using std::cin;
using std::cout;

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
        arr1[iter] = first + (rand() % (last - first));
        cout << arr1[iter] << "  ";
    }

    cout << '\n';
}

/*fucntion find six max element*/
void sixMax(int arr1[], int N, int max[], int M){
    int max1 = -INT_MAX;
    int iter2 = 0;
    
    while(iter2 < M){
        for(int iter = 0; iter < N; ++iter){
            if(arr1[iter] > max1){
                max1 = arr1[iter];
            }
        }
    }

    for (int iter = 0; iter < M; ++iter){
        cout << max[iter] << " ";
    }

    cout << '\n';
}

int main(){
    cout << "Start program ...\n";

    /*variables*/
    int arr1[size1], arr2[size2], max[size2];

    /*interval, arrays sizes*/
    int a, b, N, M, K, 
        select = 0, select1 = 0;

    /*input*/
    cout << "Select array input method: \n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> select;
    cout << "Enter count elements: \n";
    cin >> N;


    /*functions*/
    if (select == 1)
        enterArray(arr1, N);
    if (select == 2){
        cout << "Enter generate interval:\n";
        cin >> a >> b;
        generateArray(arr1, N, a, b);
    }

    cout << "Enter count elements: \n";
    cin >> M;

    sixMax(arr1, N, max, M);

    cout << "Progam finished.\n";
    return 0;
}