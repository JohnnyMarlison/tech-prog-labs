/*
Составить описание класса многочленов от одной переменной, задаваемых степенью 
многочлена и массивом коэффицентов. Предусмотреть методы для вычисления значения 
многочлена для заданного аргумента. операции сложения, вычитания и умножения многочленов
с получением нового объекта-многочлена, вывод на экран описания многочлена.

Написать программу, демонстрирующую работу с этим классом. Программа должна
содержать меню, позволяющее осуществить проверку всех методов класса.
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

////////////////Class descriprion////////////////////////////

class Polynomial {
	int pow;
	int* koef;
	long long int __pow(int v, int p);

public:
	Polynomial();
	Polynomial(int pow, int* koef);
	Polynomial(const Polynomial &p);
	~Polynomial();
	void show();
	void read();
	long long int calculate(int x);

	Polynomial operator=(const Polynomial &p);
	Polynomial operator+(const Polynomial &p);
	Polynomial operator-(const Polynomial &p);
	Polynomial operator*(const Polynomial &p);
    
};

long long int Polynomial::__pow(int v, int p) {
	if (!p) return 1;
	long long int val = 1;
	for (int i = 0; i < p; ++i, val *= v);
	return val;
}

Polynomial::Polynomial() {
	this->pow = 0;
	this->koef = new int[pow + 1];
	this->koef[0] = 0;
}

Polynomial::Polynomial(int pow, int* koef) {
	this->pow = pow;
	this->koef = new int[pow + 1];
	memcpy(this->koef, koef, sizeof(int) * (pow + 1));
}

Polynomial::Polynomial(const Polynomial &p) {
	this->pow = p.pow;
	this->koef = new int[p.pow + 1];
	memcpy(this->koef, p.koef, sizeof(int) * (p.pow + 1));
}

Polynomial::~Polynomial() {
	delete [] koef;
}

/*output func*/
void Polynomial::show() {
	bool output_flag = false;
	if (koef[pow]) {
		cout << (abs(koef[pow]) == 1 ? ( koef[pow] > 0 ? "" : "-" ) : 
									   to_string(koef[pow])) << "x^" << pow << ' ';
		output_flag = true;
	}
	for (int i = pow - 1; i > 0; --i) {
		if (koef[i] == 0) continue;
		output_flag = true;
		if (koef[i] > 0)
			cout << "+ " << (koef[i] == 1 ? "" : to_string(koef[i])) << "x^" << i << ' ';
		else
			cout << "- " << (abs(koef[i]) == 1 ? "" : to_string(abs(koef[i]))) << "x^" << i << ' ';
	}
	if (output_flag) {
		if (koef[0] > 0)
			cout << "+ " << koef[0];
		else
			cout << "- " << abs(koef[0]);
	} else {
		cout << koef[0];
	}
}

/*input func*/
void Polynomial::read() {
	cout << "Enter power of Polynomial: ";
	cin >> this->pow;
	delete [] this->koef;
	this->koef = new int[this->pow + 1];
	cout << "Enter koef of Polynomial:\n";
	for (int i = this->pow; i >= 0; --i) {
		cout << "x^" << i << " : ";
		cin >> this->koef[i];
	}
}

long long int Polynomial::calculate(int x) {
	long long int val = 0;
	for (int i = 0; i <= this->pow; ++i) {
		val += (this->koef[i] * this->__pow(x, i));
	}
	return val;
}

Polynomial Polynomial::operator=(const Polynomial &p) {
	this->pow = p.pow;
	delete [] this->koef;
	this->koef = new int[p.pow + 1];
	for (int i = 0; i <= p.pow; this->koef[i++] = 0);
	for (int i = 0; i <= p.pow; ++i)
		this->koef[i] = p.koef[i];
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial &p) {
	int m_p = (this->pow > p.pow) ? this->pow : p.pow;
	int* f = new int[m_p + 1];
	for (int i = 0; i <= m_p; f[i++] = 0);
	for (int i = 0; i <= (this->pow < p.pow ? this->pow : p.pow); ++i)
		f[i] = this->koef[i] + p.koef[i];
	if (this->pow > p.pow)
		for (int i = p.pow + 1; i <= m_p; ++i)
			f[i] = this->koef[i];
	else 
		for (int i = this->pow + 1; i <= m_p; ++i)
			f[i] = p.koef[i];
	return Polynomial(m_p, f);
}

Polynomial Polynomial::operator-(const Polynomial &p) {
	int m_p = (this->pow > p.pow) ? this->pow : p.pow;
	int* f = new int[m_p + 1];
	for (int i = 0; i <= m_p; f[i++] = 0);
	for (int i = 0; i <= (this->pow < p.pow ? this->pow : p.pow); ++i)
		f[i] = this->koef[i] - p.koef[i];
	if (this->pow > p.pow)
		for (int i = p.pow + 1; i <= m_p; ++i)
			f[i] = this->koef[i];
	else 
		for (int i = this->pow + 1; i <= m_p; ++i)
			f[i] = -p.koef[i];
	return Polynomial(m_p, f);
}

Polynomial Polynomial::operator*(const Polynomial &p) {
	int m_p = this->pow + p.pow;
	int* f = new int[m_p + 1];
	for (int i = 0; i <= m_p; f[i++] = 0);
	for (int i = 0; i <= this->pow; ++i)
		for (int j = 0; j <= p.pow; ++j)
			f[i + j] += (this->koef[i] * p.koef[j]);
	return Polynomial(m_p, f);
}

////////////////Menu functions////////////////////////////

/*main menu for polynomial*/
int print_main_menu() {
	int cmd;
	system("clear");
	cout << "    Menu:\n";
	cout << "1: Print variables\n";
	cout << "2: Create new variable\n";
	cout << "3: Remove variable\n";
	cout << "4: Math\n";
	cout << "5: Exit\n";
	cout << ">>> "; cin >> cmd;
	return cmd;
}

void print_variables(map <string, Polynomial> pol_list) {
	system("clear");
	if (pol_list.empty()) {
		cout << "You have no variables\n";
	} else {
		for (auto i = pol_list.begin(); i != pol_list.end(); ++i) {
			cout << i->first << " = "; 
			i->second.show();
			cout << endl;
		}
	}
	cout << "Press enter to continue...";
	cin.get();
	cin.get();
}

pair<string, Polynomial> create_new_variable(map <string, Polynomial> pol_list) {
	system("clear");

	string name;
	cout << "Enter name: ";
	while (1) {
		cin >> name;
		if (pol_list.find(name) == pol_list.end() || pol_list.empty()) break;
		cout << "Please, enter unique name. \nEnter name: ";
	}

	Polynomial p;
	p.read();

	cout << "Press enter to continue...";
	cin.get();
	cin.get();
	return pair<string, Polynomial>(name, p);
}

string remove_variable(map <string, Polynomial> pol_list) {
	system("clear");
	string rm_index;
	if (pol_list.empty()) {
		cout << "You can't remove nothing\n";
		rm_index = "";
	} else {
		cout << "Select removing element: \n";
		for (auto i = pol_list.begin(); i != pol_list.end(); ++i) {
			cout << i->first << " = "; 
			i->second.show();
			cout << endl;
		}
		cout << "Enter name: ";
		while (1) {
			cin >> rm_index;
			if (pol_list.find(rm_index) != pol_list.end()) break;
			cout << "Please, enter real name. \nEnter name: ";
		}
	}

	cout << "Press enter to continue...";
	cin.get();
	cin.get();
	return rm_index;
}

void math_block_1(map <string, Polynomial> pol_list) {
	system("clear");

	cout << "   List variables\n";
	for (auto i = pol_list.begin(); i != pol_list.end(); ++i) {
		cout << i->first << " = "; 
		i->second.show();
		cout << endl;
	}
	cout << "Example: val1 + val2\n";
	string input[3];
	cout << ">>> ";
	for (int i = 0; i < 3; ++i)
		cin >> input[i];

	Polynomial p;
	if (input[1] == "+")
		p = pol_list.at(input[0]) + pol_list.at(input[2]);
	else if (input[1] == "-")
		p = pol_list.at(input[0]) - pol_list.at(input[2]);
	else if (input[1] == "*")
		p = pol_list.at(input[0]) * pol_list.at(input[2]);

	cout << "Answer: " << input[0] << ' ' << input[1] << ' ' << input[2] << " = ";
	p.show();
	cout << endl;

	cout << "Press enter to continue...";
	cin.get();
	cin.get();
}

void math_block_2(map <string, Polynomial> pol_list) {
	system("clear");

	cout << "   List variables\n";
	for (auto i = pol_list.begin(); i != pol_list.end(); ++i) {
		cout << i->first << " = "; 
		i->second.show();
		cout << endl;
	}
	cout << "Name polynomial: ";
	string name;
	cin >> name;*
	int x;
	cout << "x = ";
	cin >> x;
	cout << "Answer: " << name << "(" << x << ") = " << pol_list.at(name).calculate(x) << endl;

	cout << "Press enter to continue...";
	cin.get();
	cin.get();
}

void math_block(map <string, Polynomial> pol_list) {
	int cmd;
	system("clear");
	cout << "    Math menu:\n";
	cout << "1: +, -, *\n";
	cout << "2: Calculate with x = n\n";
	cout << "3: Exit\n";
	cout << ">>> ";
	cin >> cmd;

	switch (cmd) {
		case 1:
			math_block_1(pol_list);
		break;

		case 2:
			math_block_2(pol_list);
		break;
	}

}

bool menu() {
	bool no_exit = true;
	map <string, Polynomial> pol_list;
	while (no_exit) {
		switch (print_main_menu()){
			case 1:
				print_variables(pol_list);
			break;

			case 2:
				pol_list.insert(create_new_variable(pol_list));
			break;

			case 3:
				pol_list.erase(remove_variable(pol_list));
			break;

			case 4:
				math_block(pol_list);
			break;

			case 5:
				no_exit = false;
			break;
		}
	}
}

int main() {
	menu();
	return 0;
}