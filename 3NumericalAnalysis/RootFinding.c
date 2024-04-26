#include <stdio.h>
#include <stdbool.h>

// Example function to demonstrate the root finding.
// Replace this with your actual function.
double f(double x) {
    return x*x*x +x * x - 4; // Example function f(x) = x^2 - 4
}

// Function to find an interval containing a root
bool find_interval(double (*f)(double), double xstart, double xend, double stepsize, double *xleft, double *xright) {
    bool found_root = false; // Initialize indicator

    // Initialize interval
    *xleft = xstart;
    *xright = xstart + stepsize;

    // Search interval
    while (*xleft < xend && f(*xleft) * f(*xright) >= 0.0) {
        *xleft = *xright;
        *xright += stepsize;
        if (*xright > xend)
            *xright = xend;
    }

    // Check if root found
    if (f(*xleft) * f(*xright) < 0.0) {
        found_root = true;
    }

    return found_root;
}

int main() {
    double xstart = -10; // Start of search
    double xend = 10; // End of search
    double stepsize = 1; // Step size
    double xleft, xright; // Variables to hold the result

    bool found = find_interval(f, xstart, xend, stepsize, &xleft, &xright);
    if (found) {
        printf("A root was found in the interval: [%f, %f]\n", xleft, xright);
    } else {
        printf("No root found in the given interval.\n");
    }

    return 0;
}
