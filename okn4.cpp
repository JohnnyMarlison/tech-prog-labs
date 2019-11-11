#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cmath>
 
using namespace std;

int getch() {
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}

 
class mn
{
	private:
		int n;
		double *x;
	
    public:
		mn();
		~mn();
		mn(int n,double *x);
		double cs();
 
		mn &operator=(const mn &Object); // Перегрузка =
		mn operator+(mn &);	// Сложение
		mn operator-(mn &);	// Вычитание
		mn operator*(mn &);	// Перемножение
 
		// Перегрузка оператора << для вывода
		friend ostream &operator<<(ostream &, mn &);
		// Перегрузка оператора >> для ввода матрицы
		friend istream &operator>>(istream &, mn &);
 
};
 
mn::mn(int nn,double *xx)
{
	unsigned char i;
	n=nn;
	x=new double[n+1];
	for(i=0;i<=n;x[i++]=xx[i]);
}
 
mn::mn()
{
	double x[1]={0};
	mn::mn(0,x);
}
 
mn::~mn()
{
	delete []x;
}
 
double mn::cs()
{
	return x[0];
}
 
 
// Перегрузка оператора =
mn& mn::operator=(const mn &Object)
{
	n = Object.n;
		  delete []x;
	x=new double[n+1];
	for(int i=0;i<=n;)x[i++]=Object.x[i];
	return *this;
}
 
// Перегрузка оператора +
mn mn::operator+(mn &fp1)
{
	mn ret;
	ret=(n>fp1.n)?*this:fp1;
	int minind=(n>fp1.n)?fp1.n:n;
 
	for(int i=0;i<=minind;ret.x[i++]+=x[i]);
 
	return ret;
}
 
// Перегрузка оператора -
mn mn::operator-(mn &fp1)
{
	mn ret;
	int i;
	ret=(n>fp1.n)?*this:fp1;
	if(fp1.n>n) for(i=n;i<=ret.n;ret.x[i++]=-ret.x[i]);
	int minind=(n>fp1.n)?fp1.n:n;
 
	for(i=0;i<=minind;ret.x[i++]=x[i]-fp1.x[i]);
	return ret;
 
}
 
// Перегрузка оператора *
mn mn::operator*(mn &fp1)
{
	int newindex=fp1.n+n;
	double *empty=new double[newindex+1];
	for(int i=0;i<=newindex;empty[i++]=0);
 
	mn ret(newindex,empty);
 
	for(int i=0;i<=fp1.n;i+=1)
		for(int j=0;j<=n;j+=1) ret.x[i+j]+=fp1.x[i]*x[j];
 
	return ret;
 
}
 
// Перегрузка оператора >>
istream &operator>>(istream &fi, mn &fp)
{
	cout<<"n=";
	fi >> fp.n;
 
	delete []fp.x;
	fp.x=new double[fp.n+1];
	for(int i=0;i<=fp.n;)
	{
		cout<<"x["<<i<<"]=";
		fi >> fp.x[i++];
 
	}
 
	return fi;
}
 
// Перегрузка оператора <<
ostream &operator<<(ostream &fo, mn &fp)
{
 
	for(int i=0;i<=fp.n;i+=1) fo <<"x["<<i<<"]="<<int(fp.x[i])<<endl;
	return fo;
}
 
void main()
{
	//clrscr();
	double x[]={6,3,8};
 
	mn m1(2,x);
	cout<<"Первый многочлен:"<<endl;
	cout<<m1<<endl;
	cout<<"Введите второй многочлен:"<<endl;
	mn m2;
	cin>>m2;
 
	cout<<endl<<"Сумма m1 и m2:"<< "\n" << m1+m2 << endl;
 
 
	getch();
	cout<<"Разность m1 и m2:"<<endl<<m1-m2<<endl;
	getch();
	mn m3;
	m3=m1*m2;
	cout<<"Произведение m1 и m2:"<<endl<<m3<<endl;
	getch();
	cout<<"Свободный коэффициент произведения m1 и m2: "<<m3.cs()<<endl;
	m1.~mn();
	m2.~mn();
	m3.~mn();        
}