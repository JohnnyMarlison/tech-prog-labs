/*Вводится последовательность целых чисел, найти первую и последнюю группы,
состоящих из возрастающей последовательности цифр.*/
#include <iostream>

using std::cout;
using std::cin;

/*find increas num in nums*/
bool increasNum(int nums){
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

void groups(){
    int indb_1 = 0, inde_1 = 0,
        indb_2 = 0, inde_2 = 0,
        flag_group = 0, flag_first_found = 0;

    int iter = 1, nums, nums_last = 0, 
        count_gr = 0, count = 1;

    /*find first & last group*/
    cout << "Enter nums:\n";
    for(cin >> nums; nums != 0; iter++, cin >> nums){
            if(!flag_first_found){  
                /*first group*/
                if(!flag_group && increasNum(nums)) {
                    indb_1 = iter ;
                    flag_group = 1;
                }
                if(flag_group && !increasNum(nums)){
                    inde_1 = iter - 1;
                    if (inde_1 - indb_1) {
                        flag_first_found = true;
                    } else {
                        indb_1 = 0;
                        inde_1 = 0;
                    }
                    flag_group = 0;
                }
            } 
            else {
                /*last group*/
                if(!flag_group && increasNum(nums)){
                    indb_2 = iter ;
                    flag_group = 1;
                }
                if(flag_group && !increasNum(nums)){
                    inde_2 = iter - 1;
                    if (!(inde_2 - indb_2)) {
                        indb_2 = 0;
                        inde_2 = 0;
                    }
                    flag_group = 0;

                }
            }    
        nums_last = nums;    
    }

    /*find first*/
    if(!flag_first_found) {
        if (flag_group) {
            inde_1 = iter - 1;
            if (inde_1 - indb_1) {
                flag_first_found = true;
            } else {
                indb_1 = 0;
                inde_1 = 0;
            }
        }
    }
    else{
        if(flag_group) {
            inde_2 = iter - 1;
            if (!(inde_2 - indb_2)) {
                indb_2 = 0;
                inde_2 = 0;
            }
        }
    }

    // if(flag_group && flag_first_found){
    //     inde_2 = iter - 1;
    // }
    // if(flag_group && !flag_first_found){
    //     inde_1 = iter - 1;
    // }

    if (indb_1)
        cout << "Find first group index: " << indb_1 << " " << inde_1 << "\n";
    if (indb_2)
        cout << "Find last group index: " << indb_2 << " " << inde_2 << "\n";
    else{
        cout << "Group not found\n";   
    }
    
}


int main(){
    cout << "Start program ...\n";

    groups();

    cout << "Progam finished.\n";
    return 0;
}