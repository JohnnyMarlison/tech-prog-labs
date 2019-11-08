#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int i = 1, x, x_st, kgr = 0, k = 1, max1, max2, konm1, konm2;
    for(cout << "x = ", cin >> x; x != 0; i++, cin >> x){
        if (i != 1){
            if (x > x_st)
                k++;
            else
                if (k > 1){
                    kgr++;
                    if (kgr == 1){
                        max1 = k;konm1 = i - 1;
                    }
                    else
                        if(kgr == 2)
                            if (k <= max1) {
                                max2 = k;konm2 = i - 1;
                            }
                            else{
                                max2 = max1; konm2 = konm1; max1 = k; konm1 = i - 1;
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
        x_st = x;
    }
//После цикла
    if (k > 1){
        kgr++;
        if (kgr == 1){
            max1 = k;
            konm1 = i;
        }
        else
        if(kgr == 2)
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
            else
            if (k > max2) {
                max2 = k;
                konm2 = i;
            }
    }
// Вывод результатов
    if (kgr == 0)
        cout<<"Нет групп возрастающих элементов\n";
    else
        if(kgr == 1)
            cout << "Есть одна группа, количество элементов в ней " << max1 << ". Последний элемент - "<< konm1 << endl;
        else{
            cout << "Количество элементов в группе 1 - " << max1 << ". Последний элемент - " << konm1 << "." << endl;
            cout << "Количество элементов в группе 2 - " << max2 << ". Последний элемент - " << konm2 << ". "<< endl;
        }
        return 0;
}
