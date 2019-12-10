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
    cout << '\n'/;
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

/*find increas num in nums*/
bool increasNum(int arr[], int N){
    int prev = nums % 10;
    nums /= 10;

    while(nums){
        if(prev <= nums % 10)
            return false;
        
        prev = nums % 10;
        nums /= 10;
    }
    return true;
}

void lastGroup(int arr[], int N){
    int indb_1 = 0, inde_1 = 0,
        flag_group = 0;
    
    int iter = 1, nums, nums_last = 0, 
        count_gr = 0, count = 1;

    /*find last group*/
    cout << "Enter nums:\n";
    for(cin >> arr[iter]; nums != 0; iter++, cin >> arr[iter]){  
        /*last group*/
        if(!flag_group && increasNum(arr[iter])){
            indb_1 = iter ;
            flag_group = 1;
        }
        if(flag_group && !increasNum(arr[iter])){
            inde_1 = iter - 1;
            if (!(inde_1 - indb_1)) {
                indb_1 = 0;
                inde_1 = 0;
            }
            flag_group = 0;
        }
        
        nums_last = nums;    
    }    

    if (indb_1)
        cout << "Find last group index: " << indb_1 << " " << inde_1 << "\n";
    else{
        cout << "Group not found\n";   
    }
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
            enterArray(arr1, N);
            cout << '\n';
			
		break;

		case 2:
            cout << "Enter generate interval:\n";
            cin >> a >> b;
            cout << '\n';
            generateArray(arr1, N, a, b);
            
		break;
	}
}

int main(){
    cout << "Start program ...\n";

    initArrays();    

    cout << "Progam finished.\n";
    return 0;
}
