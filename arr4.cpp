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
/*menu & init variables*/
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
    
    for (int i = N; i > 0; --i){
        if (arr[i] < 0){
            //cout << "Find negative\n";
            return i;
        }
        else{
            return 0;
        }  
    }
}

/*find first palindrom*/
bool findPalid(int num){
    int tmp = num, rev_num = 0;

    while (tmp != 0 && num > 10){
        rev_num = (rev_num * 10) + (tmp % 10);
        tmp /= 10;
    }

    if (num == rev_num){
        //cout << "FIND pAlid\n";
        return 1;
    }
    else{
        return 0;
    }
}

/*sort in interval(iter first palindrom, iter last negative)*/
void sortElems(int arr[], int N){
    int begin_i = 0, tmp = 0, 
        end_i = lastNegative(arr, N);
    
    for (int i = 0; i < N; ++i){
        if (findPalid(arr[i]) == 1){
            begin_i = i;
            for (begin_i; begin_i < end_i; begin_i++){
                if (arr[begin_i < arr[begin_i + 1]]){
                    tmp = arr[begin_i];
                    arr[begin_i] = arr[begin_i + 1];
                    arr[begin_i + 1] = tmp;
                }
            }
        }
        cout << arr[i] << "  ";
    }
    /*
    for (int i = 0; i < N; ++i){
        cout << arr[i] << "  ";
    }
    */
    cout << '\n';
    //cout << lastNegative(arr, N) << '\n';
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
