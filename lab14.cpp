/*Вводится последовательность целых чисел, найти первую и последнюю группы,
состоящих из возрастающей последовательности цифр.*/
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

indb_1 = -1, inde_1 = -1   //индексы первой группы
indb_2 = -1, inde_2 = -1   //индексы последней группы
flag_group                 //флаг что сейчас группа
flag_first_found           //флаг что первая группа найдена

//----Обработчик группы-----------------
if (!flag_group && condition) { //группа найдена
    ind1 = iter;
    flag_group = 1;
}

if (flag_group && !condition) { //группа закончилась
    flag_group = 0;
    ind2 = iter;
    if (ind2 - ind1 > 0) {
        //то что группа является группой
    }
}

//----Общая структура программы---------
if (!flag_first_found) {
    //обработчик первой группы
    flag_first_found = 1; //первая группа найдена
} else {
    //обработчик последней группы, где каждую группу ты перезаписываешь, если она находится
}























int firstGroup(){
    int iter = 1, nums, nums_st, count_gr = 0, count = 1, max1, max2, konm1, konm2;
    for(cout << "x = ", cin >> nums; nums != 0; iter++, cin >> nums){
        if (iter != 1){
            if (nums > nums_st)
                count++;
            else
                if (count == 1){
                    count_gr++;
                    if (count_gr == 1){
                        max1 = count;
                        konm1 = iter - 1;
                    }
                    else
                        if(count_gr == 2)
                            if (count <= max1) {
                                max2 = count;
                                konm2 = iter - 1;
                            }
                            else{
                                max2 = max1;
                                konm2 = konm1;
                                max1 = count;
                                konm1 = iter - 1;
                            }
                        else
                            if (count > max1){
                                max2 = max1;
                                konm2 = konm1;
                                max1 = count;
                                konm1 = iter - 1;
                            }
                            else
                                if (count > max2) {
                                    max2 = count;
                                    konm2 = iter - 1;
                                }
                    count = 1;
                }
            }
        nums_st = nums;
    }
    //После цикла
    if (count > 1){
        count_gr++;
        if (count_gr == 1){
            max1 = count;
            konm1 = iter;
        }
        else
            if(count_gr == 2)
                if (count <= max1) {
                    max2 = count;
                    konm2 = iter;
                    }
                else {
                    max2 = max1;
                    konm2 = konm1;
                    max1 = count;
                    konm1 = iter;
                }
            else
                if (count > max1) {
                    max2 = max1;
                    konm2 = konm1;
                    max1 = count;
                    konm1 = iter;
                }
                else
                    if (count > max2) {
                        max2 = count;
                        konm2 = iter;
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