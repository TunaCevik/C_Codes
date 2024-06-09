#include <stdio.h>
#include <stdlib.h>

// Bir dizi yaratır ve pointer'ını günceller
void createArray(int** array, int size) {
    *array = (int*)malloc(size * sizeof(int));
    if (*array == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        (*array)[i] = i + 1; // Diziye değerler atar
    }
}

int main() {
    int* myArray = NULL; // Başlangıçta NULL pointer

    // Diziyi oluştur ve pointer'ı güncelle
    createArray(&myArray, 5);

    // Diziyi yazdır
    printf("Dizi elemanlari:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(myArray);

    return 0;
}
