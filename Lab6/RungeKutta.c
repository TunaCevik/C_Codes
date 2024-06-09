#include <stdio.h>

// Function to represent the derivative y' = f(t, y)
double dydt(double t, double y) {
    return y - t*t + 1;
}

// Function implementing the RK4 method
double rk4(double t, double y, double h, double (*f)(double, double)) {
    double k1, k2, k3, k4;

    // Calculate k1
    k1 = h * f(t, y);

    // Calculate k2
    k2 = h * f(t + 0.5 * h, y + 0.5 * k1);

    // Calculate k3
    k3 = h * f(t + 0.5 * h, y + 0.5 * k2);

    // Calculate k4
    k4 = h * f(t + h, y + k3);

    // Combine them to estimate the new value of y
    return y + (k1 + 2*k2 + 2*k3 + k4) / 6;
}

int main() {
    double t = 0, y = 0.5, h = 0.2;
    int steps = 10; // (2 - 0) / 0.2

    printf("Initial condition: t = %f, y = %f\n", t, y);
    for(int i = 0; i < steps; i++) {
        y = rk4(t, y, h, dydt);
        t += h;
        printf("At t = %f, y = %f\n", t, y);
    }

    return 0;
}
