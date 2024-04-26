#include <stdio.h>
#include <math.h>

// Prototipler
double CircleCircumference(int);
double CircleArea(int);
double SphereVolume(int);

int main(void)
{
    size_t decision;
    int radius;
    double (*calculation[3])(int) = {CircleCircumference, CircleArea, SphereVolume};
    
    printf("Please enter the radius: ");
    scanf("%zu", &radius);
    scanf("%zu", &decision);
    
    if (decision >= 1 && decision <= 3) {
        double result = calculation[decision - 1](radius);
        printf("Result: %lf\n", result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

// Daire Çevresi Hesaplama Fonksiyonu
double CircleCircumference(int radius) {
    return 2 * 3.14 * radius;
}

// Daire Alanı Hesaplama Fonksiyonu
double CircleArea(int radius) {
    return 3.14 * radius * radius;
}

// Küre Hacmi Hesaplama Fonksiyonu
double SphereVolume(int radius) {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}
