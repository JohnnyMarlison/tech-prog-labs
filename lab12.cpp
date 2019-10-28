#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion count prime & perfect num*/
void countNum(unsigned long long int nums, int count, int count_prime, int count_perfect){
    /*prime num*/
    bool prime = true;
    for (int iter = 2; iter <= (sqrt(nums)); ++iter){
        if (nums % iter == 0){
            prime = false;
            break;
        }
        if (prime == true)
            count_prime += 1;
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
    /*count prime*//*
    if (prime == true)
        count_prime += 1;
    /*cout << "Count prime: " << count_prime << "\n";*/

    /*count perfect*//*
    if (perfect == true)
        count_perfect += 1;*/
    
    cout << "Count prime: " << count_prime << "\n";
    cout << "Count prime: " << count_perfect << "\n\n";
}

int main(){
    cout << "Start Program ... \n";
    int count = 0;
    int count_prime = 0;
    int count_perfect = 0;
    unsigned long long int N, nums;

    /*input*/
    cout << "Enter N: ";
    cin >> N;

    for (int iter = 0; iter < N; ++iter){
        cin >> nums;
        countNum(nums, count, count_prime, count_perfect);
    }


    cout << "Program finished. \n";
    return 0;
}
