#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

class Complex {
	double a;
	double b;
public:
	Complex(double a = 0, double b = 0);

	void read();
    void show(bool flag_end = 0);

    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    bool operator==(const Complex &c);
    bool operator!=(const Complex &c);
};

Complex::Complex(double a, double b) {
	this->a = a;
	this->b = b;
}

void Complex::read() {
	char i;
	cin >> this->a >> this->b >> i;
}

void Complex::show(bool flag_end) {
	cout << "(";
	if (a && b)
		cout << a << ((b > 0) ? " + " : " - ") << fabs(b) << "i";
	else if (!a && b)
		cout << b << "i";
	else if (a && !b)
		cout << a;
	else
		cout << 0;
	cout << ")";
	if (flag_end)
		cout << '\n';
}

Complex Complex::operator+(const Complex &c) {
	return Complex(this->a + c.a, this->b + c.b);
}

Complex Complex::operator-(const Complex &c) {
	return Complex(this->a - c.a, this->b - c.b);	
}

Complex Complex::operator*(const Complex &c) {
	return Complex(this->a * c.a - this->b * c.b, this->a * c.b + this->b * c.a);
}

Complex Complex::operator/(const Complex &c) {
	return Complex( (this->a * c.a + this->b * c.b) / (c.a * c.a + c.b * c.b), 
					(c.a * this->b - this->a * c.b) / (c.a * c.a + c.b * c.b) );
}

bool Complex::operator==(const Complex &c) {
	return (this->a == c.a && this->b == c.b);
}

bool Complex::operator!=(const Complex &c) {
	return (this->a != c.a || this->b != c.b);
}

int main() {
	Complex a, b;
	cout << "Enter first number: ";
	a.read();
	cout << "Enter second number: ";
	b.read();

	a.show(); cout << " + "; b.show(); cout << " = ";
	(a + b).show(1);

	a.show(); cout << " - "; b.show(); cout << " = ";
	(a - b).show(1);

	a.show(); cout << " * "; b.show(); cout << " = ";
	(a * b).show(1);

	a.show(); cout << " / "; b.show(); cout << " = ";
	(a / b).show(1);

	a.show(); cout << " == "; b.show(); cout << ": ";
	cout << ((a == b) ? "True" : "False") << '\n';

	a.show(); cout << " != "; b.show(); cout << ": ";
	cout << ((a != b) ? "True" : "False") << '\n';
	return 0;
}