#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using std::cout;
using std::cin;

int main(){
    cout << "Start program ..." << endl;

    srand(time(0));
    const int size = 100;
    float arr[size];
    float max = -10000, sum = 0, last_posit = 0, a, b;
    int N;
    int iter1 = 0, value = 0, first, last;

    cout << "Enter count elements: \n";
    cin >> N;

    cout << " Enter count interval: " << "\n";
    cin >> first >> last;



    for (int iter = 0; ){

    }

    cout << "\n";
    cout << "Last positive num = " << last_posit << endl;
    cout << "Max = " << max << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}
