/*Вводится последовательность целых чисел, найти первую и последнюю группы,
состоящих из возрастающей последовательности цифр.*/
#include<iostream>

using std::cout;
using std::cin;

void firstGroup(int nums){
    int tmp = nums, index = 0;
    if (nums < tmp){
        cout << "Last num: " << tmp << '\n';
    }
    else
        tmp = nums;
}
/*
int lastGroup(){

}
*/
int main(){
    cout << "Start program ...\n";
    int nums;

    for(int iter = 0; nums != 0; ++iter){
		cin >> nums;
        firstGroup(nums);
    }
    //cout << "Last num: " << firstGroup(nums) << '\n'
    firstGroup(nums);
    cout << "Progam finished.\n";
    return 0;
}
