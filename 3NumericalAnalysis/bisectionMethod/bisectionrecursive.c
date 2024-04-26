#include <stdio.h>
#include <math.h>

// Function prototype
double f(double x); // Replace this with your function

// Recursive bisection method
double recursive_bisection(double (*f)(double), double x1, double x2, double epsilon) {
    double xm = (x1 + x2) / 2.0;
    double y = f(xm), y1 = f(x1);
    
    if (fabs(x2 - x1) < epsilon) return xm; // Interval is small enough
    if (fabs(y) < epsilon) return xm; // Close enough to a root
    
    if (y * y1 < 0.0) {
        return recursive_bisection(f, x1, xm, epsilon); // Root lies in left subinterval
    } else {
        return recursive_bisection(f, xm, x2, epsilon); // Root lies in right subinterval
    }
}

// Example function f(x) = x^2 - 4
double f(double x) {
    return x * x - 4;
}

int main() {
    double root = recursive_bisection(f, 0, 3, 0.001); // Modify the interval [0, 3] and epsilon as needed
    printf("Root found: %f\n", root);
    return 0;
}
