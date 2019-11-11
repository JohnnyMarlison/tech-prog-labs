/*Вводится последовательность целых чисел, найти первую и последнюю группы,
состоящих из возрастающей последовательности цифр.*/
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int firstGroup(){
    int i = 1, nums, x_st, count_gr = 0, k = 1, max1, max2, konm1, konm2;
    for(cout << "x = ", cin >> nums; nums != 0; i++, cin >> nums){
        if (i != 1){
            if (nums > x_st)
                k++;
            else
                if (k == 1){
                    count_gr++;
                    if (count_gr == 1){
                        max1 = k;
                        konm1 = i - 1;
                    }
                    else
                        if(count_gr == 2)
                            if (k <= max1) {
                                max2 = k;
                                konm2 = i - 1;
                            }
                            else{
                                max2 = max1;
                                konm2 = konm1;
                                max1 = k;
                                konm1 = i - 1;
                            }
                        else
                            if (k > max1){
                                max2 = max1;
                                konm2 = konm1;
                                max1 = k;
                                konm1 = i - 1;
                            }
                            else
                                if (k > max2) {
                                    max2 = k;
                                    konm2 = i - 1;
                                }
                    k = 1;
                }
            }
        x_st = nums;
    }
    //После цикла
    if (k > 1){
        count_gr++;
        if (count_gr == 1){
            max1 = k;
            konm1 = i;
        }
        else
            if(count_gr == 2)
                if (k <= max1) {
                    max2 = k;konm2 = i;}
                else {
                    max2 = max1;
                    konm2 = konm1;
                    max1 = k;konm1 = i;
                }
            else
                if (k > max1) {
                    max2 = max1;
                    konm2 = konm1;
                    max1 = k;
                    konm1 = i;
                }
                    if (k > max2) {
                else
                        max2 = k;
                        konm2 = i;
                    }
    }
    /*output*/
    if (count_gr == 0)
        cout << "No groups of ascending elements\n";
    else
        if(count_gr == 1)
            cout << "There is one group, the number of elements in it " << max1 << ". Last element - "<< konm1 << endl;
        else{
            cout << "The number of elements in the first group - " << max1 << ". Last element - " << konm1 << "." << endl;
            cout << "The number of elements in the last group - " << max2 << ". Last element - " << konm2 << ". "<< endl;
        }
}


int main(){
    cout << "Start program ...\n";

    firstGroup();

    cout << "Progam finished.\n";
    return 0;
}