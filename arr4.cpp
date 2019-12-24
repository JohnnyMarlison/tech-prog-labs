/*
Упорядочить по возрастанию элементы целочисленного массива,
расположенные между первым числом палиндромом и последним
отрицательным значением
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
        cout << arr[i] << "  ";
    }
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(int arr[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int i = 0; i < N; ++i){
        arr[i] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr[i] << "  ";
    }

    cout << '\n';
}

 /*find last negative*/
int lastNegative(int arr[], int N){
    int result = -1;
    for (int i = N; i > 0; --i){
        if (arr[i] < 0){
            result = i;
            break;
        }
    }

    if (result >= 0)
        return result;
    else
        cout << "No negative elements!!\n";
}

/*find first palindrom*/
int findPalid(int arr[], int N){
    int tmp = 0, rev_num = 0, result = -1;

    for (int i = 0; i < N;){
        tmp = arr[i];

        while (tmp != 0 && arr[i] > 10){
            rev_num = (rev_num * 10) + (tmp % 10);
            tmp /= 10;
        }

        if (arr[i] == rev_num){
            result = i;
            break;
        }
        else{
            i++;
        }
    }

    if (result >= 0){
        return result;
    }
    else{
        cout << "No palindrom num\n";
    }
}

/*sort in interval(iter first palindrom, iter last negative)*/
void sortElems(int arr[], int N){
    int begin_i = findPalid(arr, N), tmp = 0, 
        end_i = lastNegative(arr, N);
    
    bool flag = false;

    //cout << end_i << '\n';
    while(!flag){
        flag = true;
        for (int i = begin_i; i < end_i; i++){
            if (arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                flag = false;
            }
        }
    }
    for (int i = 0; i < N; ++i){
        cout << arr[i] << "  ";
    }
    cout << '\n';
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
            enterArray(arr, N);
            cout << '\n';
			sortElems(arr, N);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateArray(arr, N, a, b);
            sortElems(arr, N);
		break;
	}
}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    cout << "Progam finished.\n";
    return 0;
}
