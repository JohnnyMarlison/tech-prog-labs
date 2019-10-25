#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion prime num*/
bool primeNum(unsigned long long int nums){
    if (nums >= 1){
        for (int i = 2; i < nums; i++)
            if (nums % i == 0)
                return false;
        return true;
    }
    else
        return false;
}

/*Fucntion perfect num*//*
unsigned long long int perfectNum(unsigned int nums){
    
}

/*count nums prime & perfect*/
unsigned int count(unsigned long long int nums){
    unsigned int count = 0;
    if (primeNum(nums) == true)
        count += 1;
    return count;
}

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
        cout << "Count: " << count(nums);
        //cout << "Prime: " << primeNum(nums) << "\n";

    }


    cout << "Program finished. \n";
    return 0;
}