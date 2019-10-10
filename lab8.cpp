#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int funcNum(int nums, int count){
	if(nums > 9 && nums < 100){
		if(nums / 10 != 0){
			count += 1;
			cout << "True " << endl;
			//cout << "Count" << endl;
		}	
	}
	else{
		cout <<	"Wrong numder. " << endl;
	}
}

int main(){
	cout << "Start program ... " << endl;

	int N, nums, count = 0;
	cout << "Enter sequence N: " << endl;
	cin >> N;

	for(int iter = 0; N >= iter; ++iter){
		cout << "Nums = " << endl;
		cin >> nums;
		cout << "Natural num : " << funcNum(nums, count) << endl;
		if (iter == N)
			cout << funcNum(num, count) << endl;
	}

	cout << "Program finished. " << endl;
	return 0;
}
