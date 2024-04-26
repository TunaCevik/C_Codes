#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define M_PI 3.14159265358979323846
#define M_d 0.5
#define M_L 1.4
#define M_LambdaG 3.6
#define M_a 2.28


double FMain(double xn, double K);
double FDER(double xn, double K);
double eRMain(double xn);
double KMain(void);

double degreeToRadian(double degree);
double *tolerance_value_generator(void);
double newton(double (*f)(double, double), double (*fprime)(double, double), double x0, int *iteration, double tolerance);

int main() {
    int iteration, error;
    double initial_guess_deg, initial_guess_rad;
    double K = KMain();
    double *tolerances = tolerance_value_generator();

    do {
        printf("Enter initial guess in degrees (between 90 and 270): ");
        scanf("%lf", &initial_guess_deg);
    } while (initial_guess_deg <= 90.0 || initial_guess_deg >= 270.0);

    initial_guess_rad = degreeToRadian(initial_guess_deg);

 
    for (int i = 0; i < 6; i++) {
        double root = newton(FMain, FDER, initial_guess_rad, &iteration, tolerances[i]);
        if (!error) {
            printf("Tolerance: %g\n", tolerances[i]);
            printf("Root of f(x) where x is in radians: %f\n", root);
            printf("Dielectric constant (e_r): %f\n", eRMain(root));
            printf("Number of iterations: %d\n\n", iteration);
        } else {
            printf("An error occurred or no convergence\n");
        }
    }

    free(tolerances); 
    return 0;
}

double degreeToRadian(double degree) {
    return degree * (M_PI / 180.0);
}

double *tolerance_value_generator() {
    double *tolerances = malloc(6 * sizeof(double));
    for (int i = 0; i < 6; i++) {
        tolerances[i] = pow(10, -(i + 1));
    }
    return tolerances;
}

double newton(double (*f)(double, double), double (*fprime)(double, double), double x0, int *iteration, double tolerance) {
    int iter = 0;
    double K = KMain();
    double x = x0, delta_x;

    do {
        delta_x = f(x, K) / fprime(x, K);
        x -= delta_x;
        iter++;
    } while (fabs(delta_x) > tolerance); // Sınırlı iterasyon için bir koşul ekledim

    *iteration = iter;
    return x;
}

double KMain(void) {
    double sonuc;

    sonuc = (tan(2*M_PI*(M_d+M_L))/M_LambdaG) / (2*M_PI*(M_d / M_LambdaG));

    return sonuc;
}
double eRMain(double xn) {
    double sonuc;
    

    sonuc = (pow((M_a / M_d), 2) * pow((xn / M_PI), 2) + 1) / (pow((2*M_a / M_LambdaG), 2) + 1);

    return sonuc;
}
double FMain(double xn, double K) {
    return tan(xn) - K*xn;
}
double FDER(double xn, double K) {
    return pow(1/cos(xn), 2)- K;
}
