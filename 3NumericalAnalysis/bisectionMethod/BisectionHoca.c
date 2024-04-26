#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

double FUNC(const double co[], double x) {
    return (co[0] * (x * x * x * x) + co[1] * (x * x * x) + co[2] * (x * x) + co[3] * x + co[4]);
}

int find_interval(
    double (*f)(const double[], double),
    double xstart,
    double xend,
    double stepsize,
    double *xleft,
    double *xright,
    const double coff[]
) {
    int found_root = FALSE; // Assume no root is found initially
    *xleft = xstart;
    *xright = *xleft + stepsize;

    while (*xleft < xend && f(coff, *xleft) * f(coff, *xright) > 0.0) {
        *xleft = *xright;
        *xright += stepsize;
        if (*xright > xend) *xright = xend;
    }
    
    if (f(coff, *xleft) * f(coff, *xright) <= 0.0) {
        found_root = TRUE; // A root might exist in the interval
    }
    return found_root; // Returning whether a root was found or not
}

int main() {
    double coeff[5], xleft, xright;

    // Kullanıcıdan katsayıları alalım.
    printf("Enter coefficients for ax^4 + bx^3 + cx^2 + dx + e: ");
    scanf("%lf %lf %lf %lf %lf", &coeff[0], &coeff[1], &coeff[2], &coeff[3], &coeff[4]);

    // Kök arama işlemi için başlangıç ve bitiş değerlerini ve adım büyüklüğünü ayarlayalım.
    double xstart = -10.0, xend = 10.0, stepsize = 0.5;

    // Kökün bulunduğu aralığı bulalım.
    if (find_interval(FUNC, xstart, xend, stepsize, &xleft, &xright, coeff)) {
        printf("Kok muhtemelen [%lf, %lf] araliginda.\n", xleft, xright);
    } else {
        printf("Bu aralikta kok bulunamadi.\n");
    }

    return 0;
}
