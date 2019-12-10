/*
Упорядочить по возрастанию элементы целочисленного массива,
расположенные между первым числом палиндромом и последним
отрицательным значением
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
void enterArray(int arr[], int N){
    
    /*input*/
    for (int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    cout << '\n';

    /*output*/
    for (int i = 0; i < N; ++i){
        cout << arr[i] << setw(4);
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
        cout << arr[i] << setw(4);
    }

    cout << '\n';
}
 /*find last negative*/
int lastNegative(int arr[], int N){
    
    for (int i = N - 1; i > 0; --i){
        if (arr[i] < 0){
            return i;
        }
        else{
            return 0;
        }
        
    }
}

int kvo_razryad(int M){
    long int k;
    for(k = 1; M > 9; M /= 10, k++);
    return k;
}

/*find first palindrom*/
bool findPalid(int arr[], int N){
    int tmp = 0, rev_num = 0;
/*
    if (num % 10 == 0 && c >= 10)
        return false; //nums ended on 0 not palindrom?
    if (num < 10 && num >= 0)
        return true; //if nums of one number?
*/
    for (int i = 0; i < N; ++i){
        tmp = arr[i];

        while (tmp != 0){
            rev_num = rev_num * 10 + tmp % 10;   
            //rev_num += tmp % 10;
            tmp /= 10;
        }
    
  
        if (rev_num == arr[i]){
            //return true;
            break; 
        }
        else{
            return false;
        }
    }

    if (rev_num == tmp){
            return true;
        }
        else{
            return false;
        }
    //return (c == rev_c);
}


void delElems(int arr[], int N){
    cout << lastNegative(arr, N) << '\n';
    cout << findPalid(arr, N) << '\n';
}

/*menu & init variables*/
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
            enterArray(arr, N);
            cout << '\n';
			delElems(arr, N);
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateArray(arr, N, a, b);
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
