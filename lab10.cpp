#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;

	unsigned int N, nums, sum_cub = 0;

	cout << "Enter Nums: " << endl;
	for(int iter = 0; nums != 0; ++iter){
		cin >> nums;
		while(nums > 0){
			sum_cub += ((nums % 10) * (nums % 10) * (nums % 10));
			nums /= 10;
		}
		cout << "Sum = " << sum_cub << endl;	
	}

	cout << "Program finished. " << endl;
	return 0;
}