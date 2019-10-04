#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int x1, y1, x2, y2, r1, r2;
    float distanse;

    cout << "Enter coordinates of the first circle: " << endl;
    cin >> x1 >> y1;

    cout << "Enter radius: " << endl;
    cin >> r1;

    cout << "Enter coordinates of the second circle: " << endl;
    cin >> x2 >> y2;

    cout << "Enter radius: " << endl;
    cin >> r2;

    distanse = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if((r1 + r2) == distance){
        cout << "Circles intersect" << endl;
    }
    else{
        cout << "Circles unintersect" << endl;
    }
    return 0;
}

 /* circles */
