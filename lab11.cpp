#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	printf("Program started ...\n");
	unsigned long long int nums, fact;

	for(int iter = 0; nums != 0; ++iter){
		printf("Enter n: ");
		scanf("%llu", &nums);
		fact = 1;
		for(unsigned long long int iter1 = 1; iter1 <= nums; fact *= (iter1++));
		printf("n! = %llu\n", fact);
	}
	printf("Program finished.\n");
	return 0;
}
