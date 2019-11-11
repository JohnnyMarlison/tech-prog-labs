/*Вводится последовательность целых чисел, найти первую и последнюю группы,
состоящих из возрастающей последовательности цифр.*/
#include<iostream>

using std::cout;
using std::cin;

int firstGroup(int nums, int count){
    // if(nums){
    //     count += 1;
    // }
    return (count += 1);
}
/*
int lastGroup(){

}
*/
int main(){
    cout << "Start program ...\n";
    int nums, count = 0;

    for(int iter = 0; nums != 0; ++iter){
		cin >> nums;
        firstGroup(nums, count);
    }

    cout << firstGroup(nums, count) << '\n';

    cout << "Progam finished.\n";
    return 0;
}
