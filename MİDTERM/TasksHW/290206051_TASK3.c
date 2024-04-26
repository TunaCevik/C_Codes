#include <stdio.h>
#include <math.h>

double trapezoidalIntegration(double (*f)(double), double a, double b, int n);
double rectangularIntegration(double (*f)(double), double a, double b, int n);
double f1(double x); // exp(-0.1*pow(x,2))
double f2(double x); // 2*exp(-.02*x)

int main() {
    printf("Number of panels\tRect. f1\tTrap. f1\tRect. f2\tTrap. f2\tRect. area\tTrap. area\n");

    for (int n = 50; n <= 1000; n += 50) {
        double rect_f1 = rectangularIntegration(f1, 0, 30, n);
        double trap_f1 = trapezoidalIntegration(f1, 0, 30, n);
        double rect_f2 = rectangularIntegration(f2, 0, 30, n);
        double trap_f2 = trapezoidalIntegration(f2, 0, 30, n);

        printf("%d\t\t\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", n, rect_f1, trap_f1, rect_f2, trap_f2, rect_f2-rect_f1, trap_f2-trap_f1);
    }

    return 0;
}

double trapezoidalIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * f(a) ;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    sum = sum - f(b)/2;
    return h * sum;
}

double rectangularIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

double f1(double x) {
    return exp(-0.1 * pow(x, 2));
}

double f2(double x) {
    return 2 * exp(-0.2 * x);
}
