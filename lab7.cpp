#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main(){
	cout << "Start program ... \n";

	for(float x = -M_PI; x <= M_PI; x += (M_PI / 12))
		printf("%9f %9f\n", x, sin(x) * sin(x));

	cout << "Program finished.\n "; 
	return 0;
}
