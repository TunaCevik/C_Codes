#include <stdio.h>
#include <math.h>

// Define the function to integrate
double f(double x) {
    return sin(x);  // Example: Integrate sin(x)
}

// Simpson's Rule Function
double simpsonsRule(double a, double b, int n) {
    double h = (b - a) / n;
    double s = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        s += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return s * (h / 3);
}

int main() {
    double lower = 0;        // Lower bound of integration
    double upper = M_PI;     // Upper bound of integration
    int n = 10;              // Number of segments (must be even)

    if (n % 2 != 0) {
        printf("n must be even\n");
        return 1;
    }

    double result = simpsonsRule(lower, upper, n);
    printf("Approximate result of the integral: %lf\n", result);

    return 0;
}
