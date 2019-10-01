#include <iostream>
#include <cmath>

using namespace std;

int funcInt(float a, float b, float c, int x){
    if ((x < 0) && (b != 0))
        return (a - (x / (10 + b)));
    if ((x > 0) && (b == 0))
        return ((x - a) / (x - c));
    else
        return (3 * x + (2 / c));

}

double funcFloat(float a, float b, float c, float x){
    if ((x < 0) && (b != 0))
        return (a - (x / (10 + b)));
    if ((x > 0) && (b == 0))
        return ((x - a) / (x - c));
    else
        return (3 * x + (2 / c));
}

int main(){
    float a, b, c, x, x1, x2, x_step, result;

    cout << "Enter a, b, c: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << "Enter interval: " << endl;
    cin >> x1;
    cin >> x2;

    cout << "Enter step: " << endl;
    cin >> x_step;

    for(x_step; x1 > x2; x1 += x_step){
        if ((((static_cast<int>(a)) == true) || ((static_cast<int>(b)) == true)) && ((static_cast<int>(c)) == true)){
            cout << "Result: " << funcInt(a, b, c, x) << endl;
        }
        else{
            cout << "Resutl: " << funcFloat(a, b, c, x) << endl;
        }
    }

    return 0;
}
