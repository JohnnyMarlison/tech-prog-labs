#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float x,y;

	cout << "Enter x:" << endl;
	cin >> x;

	//y = x*x;

	if (x <= -2 || x >= 2){
		y = 4;

	}
	else {
		y = x * x;

	}

	cout << "Value y: " << y << endl;

	return 0;
}
/*complete*/