#include <stdio.h>
#include <math.h>

double trapezoidalIntegration(double (*f)(double), double a, double b, int n);
double LrectangularIntegration(double (*f)(double), double a, double b, int n);
double RrectangularIntegration(double (*f)(double), double a, double b, int n);
double simpsonIntegration(double (*f)(double), double a, double b, int n);
double f1(double x); // exp(-0.1*pow(x,2))


int main() {
    double a,b;
    printf("Enter a: ");
    scanf("%lf",&a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Number of panels\tRect. f1\tTrap. f1\tSimpson. f1\n");

    for (int n = 10; n <= 100; n += 10) {
        double rect_f1 = LrectangularIntegration(f1, a, b, n);
        double trap_f1 = (LrectangularIntegration(f1, a, b, n) + RrectangularIntegration(f1, a, b, n)) / 2;
        double simp_f1 = simpsonIntegration(f1, a, b, n);

        printf("%d\t\t\t%.10lf\t%.10lf\t%.10lf\n", n, rect_f1, trap_f1, simp_f1);
    }

    return 0;
}
/*
double trapezoidalIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * f(a) ;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    sum = sum - f(b)/2;
    return h * sum *pow(10, -3);
}*/

double LrectangularIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum*pow(10, -3);
}
double RrectangularIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for(int i = 1; i<=n; i++) {
        sum += f(a + i * h);
    }
    return h*sum*pow(10, -3);
}
double simpsonIntegration(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        s += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return s * (h / 3)* pow(10, -3);
}

double f1(double x) {
    return 50*exp(-25*x);
}


