#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
    cout << "Start program ..." << endl;

    const int size = 100;
    float arr[size];
    float max = -10000, sum = 0, last_posit = 0, a, b;
    float N; 
    int iter1 = 0;
    
    cout << "Enter count nums: ";
    cin >> N;
    cout << "Enter nums: " << endl;

    for(int iter = 0; iter < N; ++iter){
    	cin >> arr[iter];
    }

    for(int iter = 0; iter < N; ++iter){
    	if (arr[iter] > arr[iter + 1] && max < arr[iter]){
    		max = arr[iter];
    	}

    }

    for(int iter = N; iter > 0 ; --iter){
    	if(arr[iter] > 0 && arr[iter + 1] < 0){
    		last_posit = arr[iter];
    		break;
    	}
    }

	for (int iter = 0; iter < last_posit; ++iter){
    	sum += arr[iter];
    }

    cout << "Entet interval [a,b]: " << endl;
    cin >> a >> b;
    cout << endl;
/*
    for(int iter2 = a; iter2 < b; ++iter2){
    	arr[iter2 - 1] = 0;
    	arr[iter2] = 0;
    } 
*/
  	while(iter1 < N)
  		if(arr[iter1] <= b && arr[iter1] >= a){
  			N -= 1;
  			for (int iter2 = iter1; iter2 < N; ++iter2){
  				arr[iter2] = arr[iter2 + 1];
  			}
  		}
  		else
  			iter1 += 1;
  		
	for (int iter = 0; iter < N; ++iter)
		arr[iter] = 0; 


    for(int iter = 0; iter < N; ++iter){
    	cout << arr[iter] << " ";
    } 
    
    cout << " " << endl;
    cout << "Last positive num = " << last_posit << endl;
    cout << "Max = " << max << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}