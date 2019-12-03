/*
Задан массив вещественных чисел Х(n). Найти
• сумму элементов с нечетными номерами; DONE
• произведение элементов массива, расположенных между первым и последним
отрицательными элементами. DONE
• Из данного массива и некоторого массива того же типа, но другой размерности Y(m),
сформировать общий массив Z(n+m). Удалить из полученного массива наименьший
элемент. DONE
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

/*function new array*/
void newArray(float arr2[], int M, int first, int last){
    
    /*generate & output*/
    srand(time(0));
    for (int iter = 0; iter < M; ++iter){
        arr2[iter] = ((first + (rand() % (last - first))) + (first + (rand() % (last - first))) / 1000.0);
        cout << arr2[iter] << "  ";
    }

    cout << '\n';

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

/*sum from first to last negative */
void negativeElem(float arr1[], int N){
    float first_neg = 0, last_neg = 0; 
    int first_ind, last_ind;
    float sum = 0;

    /*first negative*/
    for(int iter = 0; iter < N; ++iter){
        if(arr1[iter] < first_neg){
            first_neg = arr1[iter];
            first_ind = iter;
            break;
        }
    }

    /*last negative*/
    for(int iter = N - 1; 0 < iter; --iter){
        if(arr1[iter] < last_neg){
            last_neg = arr1[iter];
            last_ind = iter;
            break;
        }
    }

    /*sum*/
    for(first_ind; first_ind < last_ind; ++first_ind){
        sum += arr1[first_ind];
    }

    cout << "Second sum " << sum << "\n";
}


/*del min elem in arr3*/
void delElem(float arr3[], int K){

    float min = arr3[0];
    int min_iter = 0;

    /*find min elem*/
    for(int iter = 0; iter < K; ++iter){
        if (min > arr3[iter]){
            min = arr3[iter];
            min_iter = iter;
        }
    }

    cout << "Min - " << min << '\n';

    /*del & output*/
    for (int iter = 0; iter < K; ++iter){
        if (iter == min_iter){
            arr3[min_iter] = arr3[min_iter + 1];
            K -= 1;
        }
        cout << arr3[iter] << ' ';
    }
}

/*function sum arrays */
void sumArrays(float arr1[], float arr2[], int N, int M){
    int K; 
    K = N + M;
    float arr3[K];

    /*sum first array*/
    for(int iter = 0; iter < N; ++iter){
        arr3[iter] = arr1[iter];
        cout << arr3[iter] << " ";
    }
    
    /*sum second array*/
    for(int iter1 = N, iter2 = 0; iter1 < K; ++iter1, ++iter2){
        arr3[iter1] = arr2[iter2];
        cout << arr3[iter1] << " ";
    }

    cout << '\n';
    
    delElem(arr3, K);

    cout << '\n';
}
/*
void delElem(float arr3[], int K){

}
*/
/*main*/
int main(){
    cout << "Start program ...\n";
    
    /*variables*/
    float arr2[size2];
    float arr1[size1]; 

    /*interval, arrays sizes*/
    int a, b, N, M,
        select = 0, select1 = 0;

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
    a = b = 0; 
    /*output*/
    cout << "Sum = " << sumElem(arr1, N) << '\n';
    negativeElem(arr1, N);

    cout << "Generate second array?\n";
    cout << "1 - Yes\n";
    cout << "2 - No\n";
    cin >> select1;
    cout << "Enter count elements: \n";
    cin >> M;

    if (select1 == 1){
        cout << "Enter generate interval:\n";
        cin >> a >> b;
        newArray(arr2, M, a, b);
    }
    if (select1 == 2){
        cout << "Progam finished.\n";
    }

    sumArrays(arr1, arr2, N, M);
    //delElem(arr3, K)

    cout << "Progam finished.\n";
    return 0;
}   
