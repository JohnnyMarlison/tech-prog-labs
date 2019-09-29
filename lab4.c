#include "stdio.h"
#include <math.h>

int main(){
    float x, y;
    scanf("%f", &x);

    if (fabs(x) >= 2){
        y = 4;
    }
    else {
        y = x * x;
    }
    printf("%f\n", y);

    return 0;
}
