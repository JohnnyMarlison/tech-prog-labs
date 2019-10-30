#include <stdio.h>

unsigned long long int DecNC(unsigned long long int N, unsigned int b){
    unsigned long long int S,P;
    
    for (S = 0, P = 1; N!= 0; S += N % 10 * P, P *= b, N /= 10);
        return S;
}

unsigned long long int NC(unsigned long long int N, unsigned int b){
    unsigned long long int S,P;
    
    for (S = 0, P = 1; N!= 0; S += N % b * P, P *= 10, N /= b);
        return S;
}

int main(){
    unsigned long long int X,Y; 
    unsigned int bX,bY;

    //Ввод числа Х.
    printf("X = "); scanf("%lld",&X);
    
    //Ввод основания системы счисления.
    printf("bX = "); scanf("%d",&bX);
    
    //Ввод числа Х.
    printf("Y = "), scanf("%lld",&Y);
    
    //Ввод основания с/с.
    printf("bY = "); scanf("%d",&bY);
    
    //Вывод заданных чисел в десятичной с/с.
    printf("%lld(%d) = %lld(10)\n", X, bX, DecNC(X, bX));
    printf("%lld(%d) = %lld(10)\n", Y, bY, DecNC(Y, bY));
    printf("%lld(%d) + %lld(%d) = ",X, bX, Y, bY);
    printf("%lld(10)\n",DecNC(X,bX) + DecNC(Y, bY));

    printf("%lld(10) = %lld(2)\n", X, NC(X, 2));
    printf("%lld(10) = %lld(5)\n", X, NC(X, 5));
    printf("%lld(10) = %lld(7)\n", X, NC(X, 7));

    return 0;
}