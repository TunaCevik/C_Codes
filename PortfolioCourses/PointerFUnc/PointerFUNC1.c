#include <stdio.h>

// Bu fonksiyon iki double değer alır ve bunların toplamını döndürür.
double function(double x, double y) {
    return x + y; // İki argümanın toplamını döndür
}

int main() {
    double res = function(3.0, 4.0);
    printf("Toplam: %f\n", res);
    return 0;
}
