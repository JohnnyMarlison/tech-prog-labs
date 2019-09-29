#include "stdio.h"
#include "math.h"

int main(){
    float y,x;
    scanf("%f",&x);

    y = cbrt(sqrt(fabs(x))) + fabs(pow(1 / tan(x), 2) + (exp(x) / (2 * M_PI)) - x * x * x);

    printf("Value: \n");
    printf("%f \n",y);
   return 0;
}
