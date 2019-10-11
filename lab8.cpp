#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;

	int N, nums, count = 0;
	cout << "Enter sequence N: " << endl;
	cin >> N;

	for(int iter = 0; N >= iter; ++iter){
		cout << "Nums = ";
		cin >> nums;
		if(nums > 9 && nums < 100 && nums % 10 != 0 && nums % 2 == 0)
			cout << "Count: " << (count += 1) << endl;
		
	}

	cout << "Program finished. " << endl;
	return 0;
}
