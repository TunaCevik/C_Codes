#include <stdio.h>

#define Cube(x) ((x)*(x)*(x))

double CUBE(double x)
{
    return x*x*x;
}
int main()
{

    double a= 5.0;
    double a1 = 5.0;
    a1 = CUBE(a++);
    a=Cube(a++);
    printf("a: %lf a1: %lf",a,a1);
    return 0;
}
