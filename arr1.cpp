/*
Задан массив вещественных чисел Х(n). Найти
• сумму элементов с нечетными номерами;
• произведение элементов массива, расположенных между первым и последним
отрицательными элементами.
Из данного массива и некоторого массива того же типа, но другой размерности Y(m),
сформировать общий массив Z(n+m). Удалить из полученного массива наименьший
элемент.
*/

#include<iostream>
#include<ctime>

#define size1 100
#define size2 200

using std::cin;
using std::cout;

/*function for enter array elements*/
void enterArray(float arr1[], int N){
    
    /*input*/
    for (int iter = 0; iter < N; ++iter){
        cin >> arr1[iter];
    }
    cout << '\n';

    /*output*/
    for (int iter = 0; iter < N; ++iter){
        cout << arr1[iter] << "  ";
    }
    
    cout << '\n';
}

/*function generate array with rand*/
void generateArray(float arr1[], int N, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int iter = 0; iter < N; ++iter){
        arr1[iter] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr1[iter] << "  ";
    }

    cout << '\n';
}

void newArray(){

}

/*sum elements odd index*/
double sumElem(float arr1[], int N){
    float sum = 0; 
    
    /*cycle sum*/
    for(int iter = 0; iter < N; ++iter){
        if(iter % 2 != 0){
            sum += arr1[iter];
        }
    }
    return sum;
}


void negativeElem(float arr1[], int N){
    float first_neg = 0, last_neg = 0; 
    int f_ind, l_ind;
    float sum = 0;


    for(int iter = 0; iter < N; ++iter){
        if(arr1[iter] < first_neg){
            first_neg = arr1[iter];
            f_ind = iter;
            break;
        }
    }

    for(int iter = N - 1; 0 < iter; --iter){
        if(arr1[iter] < last_neg){
            last_neg = arr1[iter];
            l_ind = iter;
            break;
        }
    }

    for(f_ind; f_ind < l_ind; ++f_ind){
        sum += arr1[f_ind];
    }

    cout << "Second sum " << sum << "\n";
}


int main(){
    cout << "Start program ...\n";
    
    float arr1[size1], select = 0;
    float arr2[size2];

    int a, b, N;

    /*input*/
    cout << "Select array input method: \n\n";
    cout << "1 - Enter array \n";
    cout << "2 - Generate array \n";
    cin >> select;
    cout << "Enter count elements: \n";
    cin >> N;

    /*functions*/
    if (select == 1)
        enterArray(arr1, N);
    if (select == 2){
        cout << "Enter generate interval:\n";
        cin >> a >> b;
        generateArray(arr1, N, a, b);
    }

    /*output*/
    cout << "Sum = " << sumElem(arr1, N) << '\n';
    negativeElem(arr1, N);

    cout << "Generate second array?\n"

    cout << "Progam finished.\n";
    return 0;
}