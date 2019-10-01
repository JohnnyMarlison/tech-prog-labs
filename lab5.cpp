#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float x, y, line_x1, line_x2, line_y1, line_y2;

	cout << "Enter x: " << endl;
	cin >> x;
	cout << "Enter y: " << endl;
	cin >> y;

	line_x1 = (2 * y - 4) / 5;
	line_x2 = (-2 * y + 4) / 5;

	line_y1 = -2.5 * x + 2;
	line_y2 = 2.5 * x + 2;


	/*
	y = -3
	y = 2x+2
	y = -2x+2
	*/



	return 0;
}
