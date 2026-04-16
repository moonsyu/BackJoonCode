#include<stdio.h>

int main(){
    
    double a, b;
    double result;
    scanf("%lf %lf", &a, &b);
    result = a/b;
    printf("%0.9lf", result);
}