#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

unsigned int perfectNum(unsigned int N){

}


int main(){
	cout << "Start program ... " << endl;

	unsigned int N, nums, iter;
	//cout << "Enter sequence N: " << endl;
	//cin >> N;

	for (cout << "Enter sequence N: ",cin >> N, iter = 1; N <= iter; ++iter){
		cout << "Nums = " << endl;
		cin >> nums;
		cout << "Perfect num : " << perfectNum(nums) << endl;
	}

	cout << "Program finished. " << endl;
	return 0;
}
