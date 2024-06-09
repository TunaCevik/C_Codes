#include <stdio.h>
#include <math.h>
#include<stdlib.h>

double f(double x, double y);
double f_exact(double x, double y);
void euler_method(double x, double y, double h, double *result);
double euler1(double x, double y, double h, double (*f)(double, double));

void runge_kutta_method(double x, double y, double h, double *result); 
double rungekutta1(double t, double y, double h, double (*f)(double, double));



int main() 
{
    double x =0.0, h = 0.1, y = 1.0;
    double *rk = (double *)malloc(sizeof(double));
    double *euler = (double *)malloc(sizeof(double));
    euler_method(x, y, h, euler);
    runge_kutta_method(x, y, h, rk);
    double Y_euler, Y_kutta, Y_exact, Perr_err_EU, Perr_err_RK;
    Y_exact = f_exact(1.0, y);
    Y_euler = *euler;
    Y_kutta = *rk;
    Perr_err_EU = fabs((Y_exact - Y_euler)/Y_exact);
    Perr_err_RK = fabs((Y_exact - Y_kutta) / Y_exact);

  
    
    printf("h\t\tY_euler\t\tY_rungekutta_\tY_exact\t\tPer_err_Euler\tPer_err_RK\n");
    printf("%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf",h,Y_euler, Y_kutta, Y_exact, Perr_err_EU, Perr_err_RK);



    return 0;
}

double f(double x, double y) { //dydt
    return -6 * exp(-2*x) + y + 10;
}
double f_exact(double x, double y) {
    return 2*exp(-2*x) + 9*exp(x) - 10;
}
double euler1(double x, double y, double h, double (*f)(double, double)) {
    return y + h* f(x,y);
}
double rungekutta1(double x, double y, double h, double (*f)(double, double)) {
    double k1, k2;
    k1 = h* f(x, y);
    k2 = k2 + h*f(x + h/2, k2 + k1/2);
    return k2;
}

void euler_method(double x, double y, double h, double *result) {
    double f(double x, double y);
    double euler1(double x, double y, double h, double (*f)(double, double));
    int steps = (1 - x) / h;
    for(int i = 0; i< steps; i++) {
        y = euler1(x, y, h, f);
        x += h;
    }
    *result = y;

}
void runge_kutta_method(double x, double y, double h, double *result) {
    double f(double x, double y);
    double rungekutta1(double t, double y, double h, double (*f)(double, double));
    int steps = (1 - x) / h;
    for(int i = 0; i< steps ; i++) {
        y = rungekutta1(x, y, h, f);
        x += h;
    }
    *result = y;

}
