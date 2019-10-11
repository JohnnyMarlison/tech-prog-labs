#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;

	unsigned int nums;

	cout << "Enter Nums: " << endl;
	for(int iter = 0; nums != 0; ++iter){
		cin >> nums;
		int fact = 1;
		for(int iter1 = 1; iter1 <= nums; ++iter1){
			fact *= iter1;
			cout << "Factorial: " << fact << endl;
		}
	}
	cout << "Program finished. " << endl;
	return 0;
}
