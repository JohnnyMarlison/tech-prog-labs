#include <iostream>

using std::cout;
using std::cin;
//using std::endl;

void groups(){
    int indb_1 = 0, inde_1 = 0,
        indb_2 = 0, inde_2 = 0,
        flag_group, flag_first_found;

    int iter = 1, nums, nums_last, 
        count_gr = 0, count = 1;

    cout << "Enter nums:\n";
    for(cin >> nums; nums != 0; iter++, cin >> nums){
        if(iter != 1){
            if(!flag_group) {
                indb_1 = iter - 1;
                flag_group = 1;
            }
            if(flag_group && nums_last > nums){
                inde_1 = iter - 1;
                flag_group = 0;
                if(inde_1 - indb_1 > 0){
                    flag_first_found = 1;
                }
            }
        }    
    }
    if (flag_first_found == 1)
        cout << "Find first group " << inde_1;
}


int main(){
    cout << "Start program ...\n";

    groups();

    cout << "Progam finished.\n";
    return 0;
}