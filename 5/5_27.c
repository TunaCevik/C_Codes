#include <stdio.h>
#include <math.h>

// Function to calculate the roots of a quadratic equation
void calculateQuadraticRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (discriminant > 0) {
        // Real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Real roots:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        // Equal real roots
        root1 = -b / (2 * a);
        printf("Equal real roots:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } else {
        // Imaginary roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Imaginary roots:\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }
}

int main() {
    double a, b, c;

    // Input coefficients from the user
    printf("Enter coefficients of the quadratic equation (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Call the function to calculate and display the roots
    calculateQuadraticRoots(a, b, c);

    return 0;
}
