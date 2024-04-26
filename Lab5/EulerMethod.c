#include <stdio.h>

// Function to represent the derivative y' = f(t, y)
double dydt(double t, double y) {
    return y - t*t + 1;
}

// Function implementing the Euler method
double euler(double t, double y, double h, double (*f)(double, double)) {
    return y + h * f(t, y);
}

int main() {
    double t = 0, y = 0.5, h = 0.2;
    int steps = (2 - 0) / h;  // Number of steps from t = 0 to t = 2

    printf("Initial condition: t = %f, y = %f\n", t, y);
    for(int i = 0; i < steps; i++) {
        y = euler(t, y, h, dydt);
        t += h;
        printf("At t = %f, y = %f\n", t, y);
    }

    return 0;
}
