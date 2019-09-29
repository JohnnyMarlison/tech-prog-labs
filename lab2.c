#include "stdio.h"
#include <math.h>

int main(){
    int num, num1, num2, sum;

    printf("Add Num:");
    scanf("%d",&num);

    num1 = num / 10;
    num2 = num % 10;

    sum = num1 + num2;

    printf("RESULT:");
    printf("%d\n", sum);
    return 0;
}
