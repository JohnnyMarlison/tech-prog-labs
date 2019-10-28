#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion count prime & perfect num*/
bool countNum(unsigned long long int nums){
    int count = 0, count_prime = 0, count_perfect = 0;

    /*prime num*/
    bool prime = true;
    for (int iter = 2; iter <= (sqrt(nums)); ++iter){
        if (nums % iter == 0){
            prime = false;
            break;
        }
        // if(prime){
        //     //count_prime += 1;
        //     //cout << "Prime\n";
        //     return true;
        // }
        // else
        //     //cout << "Not Prime\n";
        //     return false;
    }
    if(prime){
        //count_prime += 1;
        //cout << "Prime\n";
        return true;
    }
    else
        //cout << "Not Prime\n";
        return false;

    // if(prime){
    //     count_prime += 1;
    //     cout << "Prime\n";
    // }
    // else
    //     cout << "Not Prime\n";

    /*perfect num*//*
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
                count_perfect += 1;
            }
            else{
                perfect = false;
                cout << "Not Perfect\n";
            }
    }
    else
        cout << "False\n";


    /*Count nums*//*
    if(prime == true && perfect == true)
        count += 1;
    cout << "Count = " << count << "\n";
    */

    //cout << "Count prime: " << count_prime << "\n";
    //return count_prime;
    //cout << "Count perfect: " << count_perfect << "\n\n";
}

int main(){
    cout << "Start Program ... \n";
    unsigned long long int N, nums, count_prime = 0;

    /*input*/
    cout << "Enter N: ";
    cin >> N;

    for (int iter = 0; iter < N; ++iter){
        cin >> nums;
        //countNum(nums);
        //cout << "Count = " << countNum(nums) << "\n";
        if (countNum(nums) == true)
            count_prime += 1;
    }
     cout << "Count = " << count_prime << "\n";


    cout << "Program finished. \n";
    return 0;
}
