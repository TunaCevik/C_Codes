#include <stdio.h>
#include <stdlib.h>

void tekrarlariBul(int dizi[], int boyut, int **tekrarEdenler, int **tekrarSayilari, int *tekrarEdenlerIndex) {
    *tekrarEdenler = malloc(boyut * sizeof(int));
    *tekrarSayilari = malloc(boyut * sizeof(int));
    *tekrarEdenlerIndex = 0;

    for (int i = 0; i < boyut; i++) {
        int tekrarVar = 0;
        for (int j = 0; j < *tekrarEdenlerIndex; j++) {
            if (dizi[i] == (*tekrarEdenler)[j]) {
                tekrarVar = 1;
                break;
            }
        }
        if (tekrarVar) continue;

        int tekrarSayisi = 0;
        for (int k = i; k < boyut; k++) {
            if (dizi[i] == dizi[k]) {
                tekrarSayisi++;
            }
        }

        (*tekrarEdenler)[*tekrarEdenlerIndex] = dizi[i];
        (*tekrarSayilari)[*tekrarEdenlerIndex] = tekrarSayisi;
        (*tekrarEdenlerIndex)++;
    }
}

int main() {
    int dizi4[] = {1, 3, 5, 7, 9, 5, 9};
    int boyut4 = sizeof(dizi4) / sizeof(dizi4[0]);

    int *tekrarEdenlerDizi4;
    int *tekrarSayilariDizi4;
    int tekrarEdenlerIndex4;

    tekrarlariBul(dizi4, boyut4, &tekrarEdenlerDizi4, &tekrarSayilariDizi4, &tekrarEdenlerIndex4);

    printf("Dizi 4 icin tekrar eden sayilar ve tekrar sayilari:\n");
    for (int i = 0; i < tekrarEdenlerIndex4; i++) {
        printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi4[i], tekrarSayilariDizi4[i]);
    }

    // Belleği serbest bırak
    free(tekrarEdenlerDizi4);
    free(tekrarSayilariDizi4);

    return 0;
}
