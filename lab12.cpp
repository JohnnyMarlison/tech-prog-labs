#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion count prime & perfect num*/
void countNum(unsigned long long int nums){
    /*prime num*/
    int count = 0;
    bool prime = true;
    for (int iter = 2; iter <= (sqrt(nums)); ++iter){
        if (nums % iter == 0){
            prime = false;
            break;
        }
    }
    if(prime)
        cout<<"Prime \n";
    else
        cout<<"Not Prime\n";

    /*perfect num*/
    bool perfect = false;
    int sum = 0;
    if (nums > 0){
        for (int iter = 1; iter < nums; iter++){
            if (nums % iter == 0)
                sum += iter;
            }
        if (nums == sum){
            perfect = true;
            cout << "Perfect\n";
        }
        else{
            perfect = false;
            cout << "Not Perfect\n";
        }
    }
    else
        cout << "False\n";
    /*Count nums*/
    if(prime == true && perfect == true)
        count += 1;
    cout << "Count = " << count << "\n\n";


}

/*Fucntion perfect num*//*
void perfectNum(unsigned int nums){
    int sum = 0;

    if (nums > 0){
        for (int iter = 1; iter < nums; iter++){
            if (nums % iter == 0)
                sum += iter;
            }
        if (nums == sum)
            //return  true;
            cout << "True\n";
        else
            //return  false;
            cout << "False\n";
    }
    else
        //return false;
        cout << "False\n";
}
*/
int main(){
    cout << "Start Program ... \n";
    unsigned long long int N, nums;

    /*input*/
    cout << "Enter N: ";
    cin >> N;

    for (int iter = 0; iter < N; ++iter){
        cin >> nums;
        countNum(nums);
        //perfectNum(nums);
        //cout << "Count: " << count(nums);
        //cout << "Prime: " << primeNum(nums) << "\n";

    }


    cout << "Program finished. \n";
    return 0;
}
