#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
double f(double x) {
    return exp(x)-3;
}
double f_der(double x) {
    return exp(x);
}
double NewthonMethod(

    double dmin,
    double x0,
    double epsilon,
    int *error
) {
    double deltax;
    deltax = 2* epsilon;
    *error = FALSE;

    while (!(*error) && fabs(deltax) > epsilon)
    {
        if(fabs(f_der(x0)) > dmin)  {
            deltax = f(x0) / f_der(x0);
            x0 = x0 -deltax;
        }
        else
            *error = TRUE;
    }
    
    return (x0);
}

int main() 
{ 
    double dmin = pow(10, -9);
    double initial, tolarance;
    int *error;
    printf("Enter the initial guess: ");
    scanf("%lf",&initial);
    printf("Enter the convergence tolarance");
    scanf("%lf", &tolarance);

    printf("Value of root is : %f", NewthonMethod(dmin, initial, tolarance, error));
    return 0;
}
