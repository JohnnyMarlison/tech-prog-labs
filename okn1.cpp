#include <iostream>
#include <cmath>

using namespace std;

double funcInt(float a, float b, float c, int x){
    if ((x < 0) && (b != 0)){
        cout << "I1" << endl;
        return (a - (x / (10 + b)));
    }
    if ((x > 0) && (b == 0)){
        cout << "I2" << endl;
        return ((x - a) / (x - c));
    }
    else{
        cout << "I3" << endl;
        return (3 * x + (2 / c));
    }

}

double funcFloat(float a, float b, float c, float x){
    if ((x < 0) && (b != 0)){
        cout << "F1" << endl;
        return (a - (x / (10 + b)));
    }
    if ((x > 0) && (b == 0)){
        cout << "F2" << endl;
        return ((x - a) / (x - c));
    }
    else{
        cout << "F3" << endl;
        return (3 * x + (2 / c));
    }
}

int main(){
    double a, b, c, x, x1, x2, x_step, result;

    cout << "Enter a, b, c: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;


    cout << "Enter interval: " << endl;
    cin >> x1;
    cin >> x2;

    cout << "Enter step: " << endl;
    cin >> x_step;

    for(x_step; x1 < x2; x1 += x_step){
        if (((a - static_cast<int>(a) == 0) || (b - static_cast<int>(b) == 0)) && (c - static_cast<int>(c) == 0) && (c != 0)){
            cout << "Result: " << funcInt(a, b, c, x + x_step) << endl;
        }
        else{
            cout << "Resutl: " << funcFloat(a, b, c, x + x_step) << endl;
        }
    }

    return 0;
}
