#include <stdio.h>
#include <stdlib.h>

// Bu fonksiyon iki double değer alır ve bir double pointer döndürür.
double *function(double x, double y) {
    double *result = malloc(2 * sizeof(double)); // İki double boyutunda bellek ayır
    result[0] = x + y; // İlk elemana toplamı ata
    result[1] = x * y; // İkinci elemana çarpımı ata
    return result; // Sonuç dizisinin adresini döndür
}

int main() {
    double *res = function(3.0, 4.0);
    printf("Toplam: %f, Çarpım: %f\n", res[0], res[1]);
    free(res); // malloc ile ayrılan belleği serbest bırak
    return 0;
}

