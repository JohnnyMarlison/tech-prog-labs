#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
 
int main()
{
 
    srand(time(0)); // генерация случайных чисел
    cout << "Enter the number of rows: "; // введите количество строк
    int rows_number = 0;
    cin >> rows_number;
    cout << "Enter the number of columns: "; // введите количество столбцов
    int columns_number = 0;
    cin >> columns_number;
 
    // динамическое создание двумерного массива вещественных чисел на десять элементов
    int **ptrarray_a = new int* [rows_number]; // строки в массиве
    for (int count = 0; count < rows_number; count++)
        ptrarray_a[count] = new int [columns_number]; // столбцы
    // заполнение массива
    for (int count_row = 0; count_row < rows_number; count_row++)
        for (int count_column = 0; count_column < columns_number; count_column++)
            ptrarray_a[count_row][count_column] = rand() % 10 - 2; //заполнение массива случайными числами
 
    for (int count_row = 0; count_row < rows_number; count_row++){
        for (int count_column = 0; count_column < columns_number; count_column++)
            cout << setw(2) << ptrarray_a[count_row][count_column] << " "; //вывод массива
     cout << endl;
    }
 
    int *ptrarray = new int [columns_number]; // создание динамического массива
    for (int count = 0; count < columns_number; count++)
        ptrarray[count] = 0;
 
    for (int count_column = 0; count_column < columns_number; count_column++){
        for (int count_row = 0; count_row < rows_number; count_row++)
          if (ptrarray_a[count_row][count_column] >= 0)
              ptrarray[count_column] += ptrarray_a[count_row][count_column];
          else{
              ptrarray[count_column] = 0;
              break;
          }
    }
 
    cout << endl;
    for (int count = 0; count < columns_number; count++)
        if (ptrarray[count] != 0)
            cout << setw(2) << ptrarray[count] << " "; // печать первоначального массива
        else
            cout << setw(3) << " ";
    cout << endl;
    // удаление двумерного динамического массива
    for (int count = 0; count < 2; count++)
        delete []ptrarray_a[count];
 
    delete [] ptrarray; // высвобождение памяти
    return 0;
}