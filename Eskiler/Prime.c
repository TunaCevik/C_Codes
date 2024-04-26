#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int *myarr;
    myarr = (int*)malloc(sizeof(int) * 120); // Dönüşüm yapılıyor
    if (myarr == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return 1; // Hata durumunu işle
    }

    for (int i = 0; i < 120; i++)
        myarr[i] = i; // Dizinin elemanlarına doğru değerleri atayın

    int prime[120] = {0};
    for (int i = 2; i < 120; i++) {
        if (myarr[i] != 0) {
            for (int j = 2 * i; j < 120; j += i) {
                myarr[j] = 0; // Asal olmayanları işaretleyin
            }
        }
    }

    for (size_t i = 2; i < 120; i++) {
        if (myarr[i] != 0)
            prime[i] = 1; // Asal olanları işaretleyin
    }

    for (size_t i = 2; i < 120; i++) {
        printf(" %d ", prime[i]);
        if (i % 10 == 0)
            printf("\n");
    }

    free(myarr); // Bellek sızıntısını önlemek için belleği serbest bırakın
    return 0;
}
