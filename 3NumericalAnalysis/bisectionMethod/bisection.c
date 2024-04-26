#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define EPSILON 1e-6  // Kök bulma işleminin hassasiyeti

// Fonksiyonumuzu tanımlayalım, x'in kuvvetleriyle çalışacak şekilde:
double FUNC(const double co[], double x) {
    return (co[0] * pow(x, 4) + co[1] * pow(x, 3) + co[2] * pow(x, 2) + co[3] * x + co[4]);
}

// Bisection yöntemini uygulayacak fonksiyon:
double bisection_method(
    double (*f)(const double[], double), 
    double xleft, 
    double xright, 
    const double coeff[], 
    double tol
) {
    double mid, f_left, f_right, f_mid;

    f_left = f(coeff, xleft);
    f_right = f(coeff, xright);

    if (f_left * f_right >= 0) {
        printf("Belirtilen aralıkta kök yok veya tek bir kök yok.\n");
        return 0; // Gerçek bir kök değeri olmadığını göstermek için 0 döndürüyoruz.
    }

    while ((xright - xleft) / 2 > tol) {
        mid = (xleft + xright) / 2;
        f_mid = f(coeff, mid);

        if (f_mid == 0) { // Tam kök bulduk
            return mid;
        } else if (f_left * f_mid < 0) { 
            xright = mid;
            f_right = f_mid;
        } else { // Kök sağ tarafta
            xleft = mid;
            f_left = f_mid;
        }
    }

    return (xleft + xright) / 2; // Yaklaşık kök değeri
}

int main() {
    double coeff[5];
    double root, xleft, xright;

    printf("Enter coefficients for ax^4 + bx^3 + cx^2 + dx + e: ");
    scanf("%lf %lf %lf %lf %lf", &coeff[0], &coeff[1], &coeff[2], &coeff[3], &coeff[4]);

    // Kök aralığını belirleyin:
    // Not: Gerçek durumlarınız için bu değerleri ayarlamanız gerekebilir.
    xleft = -100;  // Aralığın başlangıç değeri
    xright = 100;  // Aralığın bitiş değeri

    root = bisection_method(FUNC, xleft, xright, coeff, EPSILON);
    printf("Yaklaşık kök değeri: %lf\n", root);

    return 0;
}
