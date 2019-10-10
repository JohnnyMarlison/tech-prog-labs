#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;
	
	for(int iter2 = (M_PI / 12); -M_PI < iter2; --iter2)
		cout << sin(iter2) * sin(iter2) << endl;
	for(int iter = (M_PI / 12); iter < M_PI; ++iter)	
		cout << sin(iter) * sin(iter) << endl;
	

	cout << "Program finished. " << endl;
	return 0;
}
