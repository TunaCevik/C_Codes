#ifndef MATRİX

#include <stdio.h>
#include <math.h>

void mat_vec_multiplication(
    double *matrixA, // İlk matris (3x3)
    int rowA,
    int colA,
    double *matrixB, // İkinci matris (3x2)
    int rowB,
    int colB,
    double *result // Sonuç matrisi (3x2)
) {
    // Matris çarpımının boyut kontrolü
    if (colA != rowB) {
        printf("Matris boyutlari uyumsuz.\n");
        return; // Hatalı durumda fonksiyondan çık
    }

    // Matris çarpımını gerçekleştir
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i * colB + j] = 0; // Sonuç matrisinin ilgili elemanını sıfırla
            for (int k = 0; k < colA; k++) {
                result[i * colB + j] += matrixA[i * colA + k] * matrixB[k * colB + j];
            }
        }
    }
}
int mat_vec_addition(
    double *matrix0, // İlk matris
    int row0,
    int col0,
    double *matrix1, // İkinci matris (bu örnekte vektör)
    int row1,
    int col1,
    double *result // Sonuç vektörü
) {
    // Boyut kontrolü: İlk matrisin sütun sayısı ile ikinci matrisin eleman sayısı eşit olmalı
    if ((row0 != row1) || (col0 != col1)) {
        printf("Matris ve vektör boyutları uyumsuz!\n");
        return -1; // Hata kodu
    }
    for(int i = 0; i< row0; i++){
        for(int j = 0; j< col0; j++){
            result[i * col0 + j] = 0;
            result[i * col0 + j] += matrix0[i * col0 + j] + matrix1[i * col0 + j];
        }
    }


    return 0; // Başarılı tamamlama kodu
}
int mat_vec_subtraction(
    double *matrix0, // İlk matris
    int row0,
    int col0,
    double *matrix1, // İkinci matris (bu örnekte vektör)
    int row1,
    int col1,
    double *result // Sonuç vektörü
) {
    // Boyut kontrolü: İlk matrisin sütun sayısı ile ikinci matrisin eleman sayısı eşit olmalı
    if ((row0 != row1) || (col0 != col1)) {
        printf("Matris ve vektör boyutları uyumsuz!\n");
        return -1; // Hata kodu
    }
    for(int i = 0; i< row0; i++){
        for(int j = 0; j< col0; j++){
            result[i * col0 + j] = 0;
            result[i * col0 + j] += matrix0[i * col0 + j] - matrix1[i * col0 + j];
        }
    }


    return 0; // Başarılı tamamlama kodu
}
void matrix_transpose(
    double *matrix, 
    int rows, 
    int cols, 
    double *result
) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j * rows + i] = matrix[i * cols + j];
        }
    }
}


#endif // MATRİX
