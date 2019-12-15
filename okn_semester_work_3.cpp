#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//-----------------------Begin-class-description---------------------------//
/////////////////////////////////////////////////////////////////////////////

class VisitorInfo {
	string car_number;
	string car_name;
	string car_user_name;
	int* date_last_visit;
	int* date_end_fix;
	int count_fix;
public:
	VisitorInfo();
	VisitorInfo(string c_num, string c_name, string c_u_n, int d_l_v[], int d_e_f[], int count_fix);
	VisitorInfo(const VisitorInfo &v);
	~VisitorInfo();

	string get_car_user_name();
	int get_count_fix();
	void show_visitor();

	VisitorInfo operator=(const VisitorInfo &v);
};

VisitorInfo::VisitorInfo() {
	car_number    = "a000aa116";
	car_name      = "CarName";
	car_user_name = "SName FName";
	date_end_fix = new int[3];
	date_last_visit = new int[3];
	date_end_fix[0] = 0;
	date_end_fix[1] = 0;
	date_end_fix[2] = 0;
	date_last_visit[0] = 20;
	date_last_visit[1] = 10;
	date_last_visit[2] = 2001;
	count_fix = 1;
}

VisitorInfo::VisitorInfo(string c_num, string c_name, string c_u_n, int* d_l_v, int* d_e_f, int count_fix) {
	car_number = c_num;
	car_name = c_name;
	car_user_name = c_u_n;
	date_end_fix = new int[3];
	date_last_visit = new int[3];
	for (int i = 0; i < 3; ++i) {
		date_last_visit[i] = d_l_v[i];
		date_end_fix[i] = d_e_f[i];
	}
	this->count_fix = count_fix;
}

VisitorInfo::VisitorInfo(const VisitorInfo &v) {
	car_number = v.car_number;
	car_name = v.car_name;
	car_user_name = v.car_user_name;
	date_end_fix = new int[3];
	date_last_visit = new int[3];
	for (int i = 0; i < 3; ++i) {
		date_last_visit[i] = v.date_last_visit[i];
		date_end_fix[i] = v.date_end_fix[i];
	}
	count_fix = v.count_fix;
}

VisitorInfo::~VisitorInfo() {
	delete [] date_end_fix;
	delete [] date_last_visit;
}

VisitorInfo VisitorInfo::operator=(const VisitorInfo &v) {
	car_number = v.car_number;
	car_name = v.car_name;
	car_user_name = v.car_user_name;
	for (int i = 0; i < 3; ++i) {
		date_last_visit[i] = v.date_last_visit[i];
		date_end_fix[i] = v.date_end_fix[i];
	}
	count_fix = v.count_fix;
	return *this;
}

string VisitorInfo::get_car_user_name() {
	return car_user_name;
}

int VisitorInfo::get_count_fix() {
	return count_fix;
}

void VisitorInfo::show_visitor() {
	cout << "Name           : " << car_user_name << "\n";
	cout << "Car name       : " << car_name << "\n";
	cout << "Car number     : " << car_number << "\n";
	cout << "Date last visit: " << date_last_visit[0] << '.' 
								<< date_last_visit[1] << '.'
								<< date_last_visit[2] << '\n';
	cout << "Date end fix   : " << date_end_fix[0] << '.' 
								<< date_end_fix[1] << '.'
								<< date_end_fix[2] << '\n';
	cout << "Count of fix   : " << count_fix << '\n';

}

/////////////////////////////////////////////////////////////////////////////
//-----------------------End-class-description-----------------------------//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//-----------------------Begin-random-generator----------------------------//
/////////////////////////////////////////////////////////////////////////////

const vector<string> base_fname = {"Emily","Hannah","Kaitlyn","Sarah","Madison","Brianna","Kaylee","Hailey","Alexis","Elizabeth","Michael","James","Matthew","Nicholas","Christopher","Joseph","Zachary","Joshua","Andrew","Willia","Adam", "Alex", "Aaron", "Ben", "Carl", "Dan", "David", "Edward", "Fred", "Frank", "George", "Hal", "Hank", "Ike", "John", "Jack", "Joe", "Larry", "Monte", "Matthew", "Mark", "Nathan", "Otto", "Paul", "Peter", "Roger", "Roger", "Steve", "Thomas", "Tim", "Ty", "Victor", "Walter"};
const vector<string> base_sname = {"Anderson", "Ashwoon", "Aikin", "Bateman", "Bongard", "Bowers", "Boyd", "Cannon", "Cast", "Deitz", "Dewalt", "Ebner", "Frick", "Hancock", "Haworth", "Hesch", "Hoffman", "Kassing", "Knutson", "Lawless", "Lawicki", "Mccord", "McCormack", "Miller", "Myers", "Nugent", "Ortiz", "Orwig", "Ory", "Paiser", "Pak", "Pettigrew", "Quinn", "Quizoz", "Ramachandran", "Resnick", "Sagar", "Schickowski", "Schiebel", "Sellon", "Severson", "Shaffer", "Solberg", "Soloman", "Sonderling", "Soukup", "Soulis", "Stahl", "Sweeney", "Tandy", "Trebil", "Trusela", "Trussel", "Turco", "Uddin", "Uflan", "Ulrich", "Upson", "Vader", "Vail", "Valente", "Van Zandt", "Vanderpoel", "Ventotla", "Vogal", "Wagle", "Wagner", "Wakefield", "Weinstein", "Weiss", "Woo", "Yang", "Yates", "Yocum", "Zeaser", "Zeller", "Ziegler", "Bauer", "Baxster", "Casal", "Cataldi", "Caswell", "Celedon", "Chambers", "Chapman", "Christensen", "Darnell", "Davidson", "Davis", "DeLorenzo", "Dinkins", "Doran", "Dugelman", "Dugan", "Duffman", "Eastman", "Ferro", "Ferry", "Fletcher", "Fietzer", "Hylan", "Hydinger", "Illingsworth", "Ingram", "Irwin", "Jagtap", "Jenson", "Johnson", "Johnsen", "Jones", "Jurgenson", "Kalleg", "Kaskel", "Keller", "Leisinger", "LePage", "Lewis", "Linde", "Lulloff", "Maki", "Martin", "McGinnis", "Mills", "Moody", "Moore", "Napier", "Nelson", "Norquist", "Nuttle", "Olson", "Ostrander", "Reamer", "Reardon", "Reyes", "Rice", "Ripka", "Roberts", "Rogers", "Root", "Sandstrom", "Sawyer", "Schlicht", "Schmitt", "Schwager", "Schutz", "Schuster", "Tapia", "Thompson", "Tiernan", "Tisler"};
const vector<string> base_cname = {"Acura","Alfa Romeo","Aston Martin","Audi","Bentley","BMW","Bugatti","Buick"};

VisitorInfo create_random_visitor() {
	string name = base_sname.at(rand() % base_sname.size()) + ' ' +
				  base_fname.at(rand() % base_fname.size());
	string car_n = base_cname.at(rand() % base_cname.size());
	char tmp_car_number[] = {char(rand() % 25 + 97),
						     char(rand() % 10 + 48),
							 char(rand() % 10 + 48),
							 char(rand() % 10 + 48),
							 char(rand() % 25 + 97),
							 char(rand() % 25 + 97),
							 char(rand() % 10 + 48),
							 char(rand() % 10 + 48),
							 char(rand() % 10 + 48)};
	string car_num(tmp_car_number);
	int datelastvisit[] = {rand() % 25 + 1, rand() % 12 + 1, rand() % 10 + 2000};
	int dateendfix[] = {rand() % 25 + 1, rand() % 12 + 1, rand() % 5 + 2019};
	int countfix = rand() % 7 + 1;
	return VisitorInfo(car_num, car_n, name, datelastvisit, dateendfix, countfix);
}

/////////////////////////////////////////////////////////////////////////////
//-----------------------End-random-generator------------------------------//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//-----------------------Begin-sort-description----------------------------//
/////////////////////////////////////////////////////////////////////////////

bool sort_func(string s1, string s2) {
	return (s1 < s2);
}

void swap(VisitorInfo &v1, VisitorInfo &v2) {
	VisitorInfo tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void shell_sort(VisitorInfo* array, int size, bool (*f)(string, string)) {
	int step, i, j;
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++) 
			for (j = i - step; j >= 0 && f(array[j].get_car_user_name(), array[j + step].get_car_user_name()); j -= step)
				swap(array[j], array[j + step]);
}

/////////////////////////////////////////////////////////////////////////////
//-----------------------End-sort-description------------------------------//
/////////////////////////////////////////////////////////////////////////////

vector<VisitorInfo> create_new_database(VisitorInfo* arr, int size) {
	vector<VisitorInfo> v;
	for (int i = 0; i < size; ++i)
		if (arr[i].get_count_fix() > 3)
			v.push_back(arr[i]);
	return v;
}

int main() {
	srand(time(NULL));
	int count;
	cout << "Enter count of vivstors: ";
	cin >> count;
	VisitorInfo* vis_arr = new VisitorInfo[count];
	cout << "\n            Input base\n";
	cout << "----------------------------------------\n";
	for (int i = 0; i < count; ++i) {
		vis_arr[i] = create_random_visitor();
		vis_arr[i].show_visitor();
		cout << "----------------------------------------\n";
	}
	vector<VisitorInfo> v = create_new_database(vis_arr, count);
	VisitorInfo* new_vis_arr = v.data();
	shell_sort(new_vis_arr, v.size(), sort_func);
	cout << "            Sorted base\n";
	cout << "----------------------------------------\n";
	for (int i = 0; i < v.size(); ++i) {
		new_vis_arr[i].show_visitor();
		cout << "----------------------------------------\n";
	}
	delete [] vis_arr;
}