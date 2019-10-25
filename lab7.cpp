#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main(){
	cout << "Start program ... \n";

	/*sin * sin on (-Pi, Pi, Pi / 12)*/
	for(float x = -M_PI; x <= M_PI; x += (M_PI / 12))
		printf("%9f %9f\n", x, sin(x) * sin(x));

	cout << "Program finished.\n ";
	return 0;
}
