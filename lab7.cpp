#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Start program ... " << endl;
	float x = -M_PI;
	//float iter2 = M_PI;
/*
	for(iter; iter <= 0; iter += (M_PI / 12)){
		cout << sin(iter) * sin(iter) << endl;
		cout << iter << endl;
	}
	for(iter2; iter2 <= M_PI ; iter2 += (M_PI / 12)){
		cout << sin(iter2) * sin(iter2) << endl;
		cout << iter2 << endl;
	}
*/
/*
	for(int iter = 0; iter < 25; iter++)
		cout << iter << "   " << (sin(x + iter * (M_PI) / 12) * sin(x + iter * (M_PI) / 12)) << "   " << (iter * (M_PI) / 12) << endl;
*/
	for(x = -M_PI; (x < M_PI); x += (M_PI / 12))
		cout << x << "		" << (sin(x) * sin(x)) << endl;

	cout << "Program finished. " << endl;
	return 0;
}
