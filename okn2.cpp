#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;

int main(int argc, char* argv[]){
    cout << "Start program ...\n";

    /*create variable*/
    srand(time(0));
    const int size = 1000;
    float arr[size];
    float max = -10000, sum = 0, last_pos = 0, a, b;
    int N;
    int iter1 = 0, value = 0, first, last;

    /*input*/
    cout << "Enter count elements: \n";
    cin >> N;

    cout << "Enter count interval: \n";
    cin >> first >> last;
    cout << "\n";

    /*max element*/
    for (int iter = 0; iter < N; ++iter){
        arr[iter] = (first + rand() % (last - first)) - (first + rand() % (last - first)) / 100.0;
        if(arr[iter] > max)
            max = arr[iter];
    }

    /*last positive element*/
    for(int iter = N; iter > 0; --iter){
        if (arr[iter] > 0){
            last_pos = arr[iter];
            break;
        }
    }

    /*sum to last positive*/
    for(int iter = 0; iter < last_pos; ++iter){
        sum += arr[iter];
    }

    for (int iter = 0; iter < N; ++iter){
        cout << arr[iter] << "  ";
    }
    cout << "\n";

    cout << "Enter interval for delete array elements: \n";
    cin >> a >> b;

    /*delete elements*/
    while(iter1 < N){
        if(abs(arr[iter1]) <= b && abs(arr[iter1]) >= a){
            N -= 1;
            value += 1;
            for (int iter2 = iter1; iter2 < N; ++iter2){
                arr[iter2] = arr[iter2 + 1];
            }
        }
        else
            iter1 += 1;
    }
    
    for (N; N < N + value; ++N){
        value -= 1;
        arr[N] = 0; 
    }

    /*output*/
    for (int iter = 0; iter < N; ++iter){
        cout << arr[iter] << "  ";
    }

    cout << "\n";
    cout << "Last positive num = " << last_pos << "\n";
    cout << "Max = " << max << "\n";
    cout << "Sum = " << sum << "\n";

    cout << "Program finished.\n";
    return 0;
}
