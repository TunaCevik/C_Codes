#include <stdio.h>
#include <stdlib.h>

double *dynamicDivision(double a, double b) { // double tipinde pointer döndüren fonksiyon
    double *result = malloc(sizeof(double)); // Sonucu tutacak yeri ayır
    if(b != 0.0) {
        *result = a / b;
    } else {
        *result = 0.0; // Bölme hatası durumu
    }
    return result; // Sonuç pointer'ını döndür
}

double staticDivision(double a, double b) { // Tek bir double döndüren fonksiyon
    if(b != 0.0) {
        return a / b; // Doğrudan sonucu döndür
    } else {
        return 0.0; // Bölme hatası durumu
    }
}

int main() {
    double *dynamicRes;
    dynamicRes = dynamicDivision(10.0, 2.0);
    printf("Dinamik Bölme: %f\n", *dynamicRes);
    free(dynamicRes); // malloc ile ayrılan belleği serbest bırak

    double staticRes = staticDivision(10.0, 2.0);
    printf("Statik Bölme: %f\n", staticRes);
    return 0;
}
