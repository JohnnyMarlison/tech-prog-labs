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
		cin >> nums;
		if(nums > 9 && nums < 100 && nums % 10 != 0 && nums % 2 == 0)
			count += 1;
	}
	cout << "Count: " << count << "\n";

	cout << "Program finished. " << endl;
	return 0;
}
