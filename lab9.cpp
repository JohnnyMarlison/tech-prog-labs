#include <iostream>
#include <cmath>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;

 	int N, nums, max = -INT_MAX;

	/*max num while != 0*/
	cout << "Enter Nums: " << endl;
	for(int iter = 0; nums != 0; ++iter){
		cin >> nums;
		if(max < nums){
			max = nums;
			cout << "Max = " << max << endl;
		}
		else
			cout << "Max = " << max << endl;
	}

	cout << "Program finished. " << endl;
	return 0;
}
