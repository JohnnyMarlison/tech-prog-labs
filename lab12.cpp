#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion prime num*/
void primeNum(unsigned long long int nums){
    bool isPrime = true;
    for (int iter = 2; iter <= (sqrt(abs(nums))); ++iter){
        if (nums % iter == 0){
        isPrime = false;
        break;
        }
    }
    if(isPrime)
        cout<<"This is a prime number\n";
    else
        cout<<"This is not a prime number\n";
}

/*Fucntion perfect num*//*
unsigned long long int perfectNum(unsigned int nums){
    
}

/*count nums prime & perfect*//*
unsigned int count(unsigned long long int nums){
    unsigned int count = 0;
    if (primeNum(nums) == true)
        count += 1;
    return count;
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
        primeNum(nums);
        //perfectNum(nums);
        //cout << "Count: " << count(nums);
        //cout << "Prime: " << primeNum(nums) << "\n";

    }


    cout << "Program finished. \n";
    return 0;
}