#include<iostream>
#include<ctime>

#define size 100

using std::cin;
using std::cout;

/*function for enter array elements*/
void enterArray(float arr[], int N){
    /*input*/
    for (int iter = 0; iter < N; ++iter){
        cin >> arr[iter];
    }
    cout << '\n';

    /*output*/
    for (int iter = 0; iter < N; ++iter){
        cout << arr[iter] << "  ";
    }
    
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(float arr[], int N, int first, int last){
    /*generate & output*/
    srand(time(0));
    for (int iter = 0; iter < N; ++iter){
        arr[iter] = (first + (rand() % (last - first))) ;
        //arr[iter] = (first + (rand() % (last - first + 1))) * 0.001;
        cout << arr[iter] << "  ";
    }

    cout << '\n';
}

/*sum elements odd index*/
double sumElem(float arr[], int N){
    int sum = 0; 
    
    /*cycle sum*/
    for(int iter = 0; iter < N; ++iter){
        if (iter % 2 == 1){
            sum += arr[iter];
        }
    }
    return sum;
}



int main(){
    cout << "Start program ...\n";
    
    float arr[size], select = 0; //sum_negative = 0;
    int a, b, N;

    /*input*/
    cout << "Select array input method: \n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> select;
    cout << "Enter count elements: \n";
    cin >> N;

    /*functions*/
    if (select == 1)
        enterArray(arr, N);
    if (select == 2){
        cout << "Enter generate interval:\n";
        cin >> a >> b;
        generateArray(arr, N, a, b);
    }

    cout << "Sum = " << sumElem(arr, N) << '\n';

    cout << "Progam finished.\n";
    return 0;
}