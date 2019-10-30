#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*Fucntion count prime num*/
bool primeNum(unsigned long long int nums){
    int count = 0, count_prime = 0, count_perfect = 0;

    bool prime = true;
    for (int iter = 2; iter <= (sqrt(nums)); ++iter){
        if (nums % iter == 0){
            prime = false;
            break;
        }
    }
    if(prime){
            return true;
        }
        else
            return false;
}

/*Fucntion count perfect num*/
bool perfectNum(unsigned long long int nums){
    bool perfect = false;
    int sum = 0;
    
    if (nums > 0){
        for (int iter = 1; iter < nums; iter++){
            if (nums % iter == 0)
                sum += iter;
            }
            if (nums == sum){
                perfect = true;
                return true;
            }
            else{
                perfect = false;
                return false;
            }
    }
    else
        return false;
}

int main(){
    cout << "Start Program ... \n";
    unsigned long long int N, nums, count = 0, count_prime = 0, count_perfect = 0;

    /*input*/
    cout << "Enter N: ";
    cin >> N;

    for (int iter = 0; iter < N; ++iter){
        cin >> nums;
        
        if (primeNum(nums) == true)
            count_prime += 1;
        if (perfectNum(nums) == true)
            count_perfect += 1;
        if (perfectNum(nums) == true && primeNum(nums) == true)
            count += 1;

    }
    
    /*output*/
    cout << "Count prime num = " << count_prime << "\n";
    cout << "Count perfect num = " << count_perfect << "\n";
    cout << "Count prime & perfect num = " << count << "\n";

    cout << "Program finished. \n";
    return 0;
}
