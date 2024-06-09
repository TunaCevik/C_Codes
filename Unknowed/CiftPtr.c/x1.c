#include <stdio.h>
#include <stdlib.h>

// Pointer'ın tuttuğu adresi günceller
void updatePointer(int** ptr) {
    *ptr = (int*)malloc(sizeof(int)); // Orijinal pointer'ı yeni bir bellek adresine yönlendirir
    if (*ptr != NULL) {
        **ptr = 42; // Yeni adresin işaret ettiği değeri ayarlar
    }
}

int main() {
    int* myPtr = NULL; // Başlangıçta NULL pointer

    // Pointer'ın adresini geçir
    updatePointer(&myPtr);

    // Güncellenmiş pointer'ı kullanarak değeri yazdır
    if (myPtr != NULL) {
        printf("Pointer'in tuttugu deger: %d\n", *myPtr);
    } else {
        printf("Pointer guncellenemedi.\n");
    }

    // Belleği serbest bırak
    free(myPtr);

    return 0;
}
