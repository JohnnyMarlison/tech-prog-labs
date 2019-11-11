#include <iostream>

using std::cout;
using std::cin;

/*function for translate nums from any nums system to decimal*/
unsigned long long int decimalNS(unsigned long long int num, unsigned int ns){
    unsigned long long int S, P;

    for (S = 0, P = 1; num!= 0; S += num % 10 * P, P *= ns, num /= 10);
        return S;
}

/*function for translate nums from decimal system to any nums system*/
unsigned long long int anyNS(unsigned long long int num, unsigned int ns){
    unsigned long long int S, P;

    for (S = 0, P = 1; num!= 0; S += num % ns * P, P *= 10, num /= ns);
        return S;
}

int main(){
    /*A = p, B = q, C = r, sum = A * A + A * B*/
    unsigned long long int A, B, C;
    unsigned int ns_A, ns_B, ns_C /*= 7*/;

    /*Input*/
    cout << "Enter A, num system A:\n"; cin >> A >> ns_A;
    cout << "Enter B, num system B:\n"; cin >> B >> ns_B;
    cout << "Enter num system C:\n"; cin >> ns_C;
/*
    cout << decimalNS(A, ns_A) << "\n";
    cout << decimalNS(B, ns_B) << "\n";
*/
    C = decimalNS(A, ns_A) * decimalNS(A, ns_A) + decimalNS(A, ns_A) * decimalNS(B, ns_B);

    cout << "decimal C = " << C << "\n";
    cout << "num system C = " << anyNS(C, ns_C) << "\n";

    return 0;
}
