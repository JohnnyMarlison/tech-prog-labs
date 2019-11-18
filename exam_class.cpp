#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*init class*/
class Address {
	string country;
	string city;
	string street;
	int house;
	int place;

public:
	Address() { remove_country(); }

	void set_country(string country) { this->country = country; }
	void set_city(string city);
	void set_street(string street);
	void set_house(int house);
	void set_place(int place);

	string get_country() { return country; }
	string get_city() { return city; }
	string get_street() { return street; }
	int    get_house() { return house; }
	int    get_place() { return place; }

	void remove_place() { place = -1; }
	void remove_house() { house = -1; remove_place(); }
	void remove_street() { street = ""; remove_house(); }
	void remove_city() { city = ""; remove_street(); }
	void remove_country() { country = ""; remove_city(); }

	void print_address();
};

void Address::set_city(string city) {
	if (country == "") {
		string coun;
		cout << "Enter country: ";
		cin >> coun;
		set_country(coun);
	}
	this->city = city;
}

void Address::set_street(string street) {
	if (city == "") {
		string c;
		cout << "Enter city: ";
		cin >> c;
		set_city(c);
	}
	this->street = street;
}

void Address::set_house(int house) {
	if (street == "") {
		string str;
		cout << "Enter street: ";
		cin >> str;
		set_street(str);
	}
	this->house = house;
}

void Address::set_place(int place) {
	if (house == -1) {
		int h;
		cout << "Enter house: ";
		cin >> h;
		set_house(h);
	}
	this->place = place;
}

void Address::print_address() {
	if (country == "") {
		cout << "Not found address\n";
		return;
	}
	cout << country << ", " << city << ", st. " << street << ", h. " << house << ", p." << place << '\n';
}

void set_state(Address *addr) {
	system("clear");
	cout << "Choose value: \n  1 - country\n  2 - city\n  3 - street\n  4 - house\n  5 - place\nValue: ";
	int st;
	cin >> st;
	string s;
	int a;
	cout << "New value: ";
	if (1 <= st && st <= 3)
		cin >> s;
	else
		cin >> a;

	switch (st) {
		case 1:
			addr->set_country(s);
		break;

		case 2:
			addr->set_city(s);
		break;

		case 3:
			addr->set_street(s);
		break;

		case 4:
			addr->set_house(a);
		break;

		case 5:
			addr->set_place(a);
		break;
	}
}

void get_state(Address addr) {
	system("clear");
	cout << "Choose value: \n  1 - country\n  2 - city\n  3 - street\n  4 - house\n  5 - place\nValue: ";
	int st;
	cin >> st;
	switch (st) {
		case 1:
			cout << addr.get_country() << '\n';
		break;

		case 2:
			cout << addr.get_city() << '\n';
		break;

		case 3:
			cout << addr.get_street() << '\n';
		break;

		case 4:
			cout << addr.get_house() << '\n';
		break;

		case 5:
			cout << addr.get_place() << '\n';
		break;
	}
}

bool state_mashine(Address *addr) {
	bool exit = false;
	int st;
	system("clear");
	while (1) {
		cout << "Menu:\n";
		cout << "  1 - Set value\n  2 - Get value\n  3 - Print address\n  4 - Exit\n State: ";
		cin >> st;
		if (st < 1 || st > 4) {
			system("clear");
			cout << "Incorrect format!\n";
		}
		else break;
	}

	switch (st) {
		case 1:
			set_state(addr);
		break;

		case 2:
			get_state(*addr);
		break;

		case 3:
			addr->print_address();
		break;

		case 4:
			exit = true;
		break;
	}
	cout << "Press enter to continue...";
	cin.get();
	cin.get();
	return exit;
}

int main() {
	Address addr;
	while (1) {
		if (state_mashine(&addr))
			break;
	}
	return 0;
}