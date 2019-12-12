#include <iostream>
#include <inttypes.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;

class Fraction {
    int64_t x;
    uint64_t y;

public:
    Fraction(int64_t x = 0, uint64_t y = 1);

    void read();
    void show(bool flag_end = 0);

    Fraction operator+(const Fraction &fr); //
    Fraction operator+(const int64_t num);  // 
    Fraction operator-(const Fraction &fr); //
    Fraction operator-(const int64_t num);  //
    Fraction operator-();                   //
    Fraction operator*(const Fraction &fr); //
    Fraction operator/(const Fraction &fr); // 
    bool operator==(const Fraction &fr);    //
    bool operator!=(const Fraction &fr);    //
    bool operator<(const Fraction &fr);     //
    bool operator>(const Fraction &fr);     //
};

Fraction::Fraction(int64_t x, uint64_t y) {
    this->x = x;
    this->y = y;
}

void Fraction::read() {
    char c;
    cin >> x >> c >> y;
}

void Fraction::show(bool flag_end) {
	std::vector <int> vecx, vecy;

	for (int i = 1; i <= abs(x / 2); ++i)
		if (!(x % i)) vecx.push_back(i);

	for (int i = 1; i <= y / 2; ++i)
		if (!(y % i)) vecy.push_back(i);

	vecx.push_back(abs(x));
	vecy.push_back(y);

	std::vector <int> vec_int;

	std::set_intersection(vecx.begin(), vecx.end(),
						  vecy.begin(), vecy.end(),
						  std::back_inserter(vec_int));

	x /= vec_int.at(vec_int.size() - 1);
	y /= vec_int.at(vec_int.size() - 1);

    if (flag_end)
    	cout << x << '/' << y << '\n';
    else 
    	cout << x << '/' << y;
}

Fraction Fraction::operator+(const Fraction &fr) {
    return Fraction(this->x * fr.y + fr.x * this->y, this->y * fr.y);
}

Fraction Fraction::operator-(const Fraction &fr) {
    return Fraction(this->x * fr.y - fr.x * this->y, this->y * fr.y);
}

Fraction Fraction::operator+(const int64_t num) {
    return Fraction(this->y * num + this->x, this->y);
}

Fraction Fraction::operator-(const int64_t num) {
	return Fraction(this->x, this->y) + (-num);
}

Fraction Fraction::operator*(const Fraction &fr) {
    return Fraction(this->x * fr.x, this->y * fr.y);
}

Fraction Fraction::operator/(const Fraction &fr) {
    return Fraction(this->x * fr.y, this->y * fr.x);
}

Fraction Fraction::operator-() {
    return Fraction(-1 * this->x, this->y);
}

bool Fraction::operator==(const Fraction &fr) {
    return (fr.x * this->y == this->x * fr.y);
}

bool Fraction::operator!=(const Fraction &fr) {
	return !(Fraction(this->x, this->y) == fr);
}

bool Fraction::operator<(const Fraction &fr) {
	return (this->x * fr.y < fr.x * this->y);
}

bool Fraction::operator>(const Fraction &fr) {
	return (this->x * fr.y > fr.x * this->y);	
}

void print_2fract(Fraction fr1, Fraction fr2, std::string str) {
	fr1.show(); cout << str; fr2.show(); cout << " = ";
}

int main() {
	Fraction f1(1, 2), f2(3, 4), f3;

	print_2fract(f1, f2, " + ");
	f3 = f1 + f2;
	f3.show(1);

	print_2fract(f1, f2, " - ");
	f3 = f1 - f2;
	f3.show(1);

	print_2fract(f1, f2, " * ");
	f3 = f1 * f2;
	f3.show(1);

	print_2fract(f1, f2, " / ");
	f3 = f1 / f2;
	f3.show(1);	

	print_2fract(f1, f2, " == ");
	cout << (f1 == f2 ? "True" : "False") << '\n';

	print_2fract(f1, f2, " != ");
	cout << (f1 != f2 ? "True" : "False") << '\n';

	print_2fract(f1, f2, " > ");
	cout << (f1 > f2 ? "True" : "False") << '\n';

	print_2fract(f1, f2, " < ");
	cout << (f1 < f2 ? "True" : "False") << '\n';
    return 0;
}