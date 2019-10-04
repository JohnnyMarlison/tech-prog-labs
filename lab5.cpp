#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float x, y;

	cout << "Enter x: " << endl;
	cin >> x;
	cout << "Enter y: " << endl;
	cin >> y;

	if (((-2 <= 2.5 * x - y) && (2 >= 2.5 * x + y )) && (y >= -3) && (y <= 2)){
		cout << "This point in triangle." << endl;
	}
	else{
		cout << "This point out triangle." << endl;
	}

	return 0;
}
