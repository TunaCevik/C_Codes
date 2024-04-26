#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data; // Tek boyutlu dizi olarak matris verileri
    int rows;
    int cols;
} MATRIX;

// Tek boyutlu dizi ile matris oluşturma
MATRIX createMatrix(int rows, int cols) {
    MATRIX m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double *)malloc(rows * cols * sizeof(double)); // Tek boyutlu dizi için bellek ayırma
    for (int i = 0; i < rows * cols; i++) {
        m.data[i] = 0.0; // Başlangıçta tüm değerleri 0 yap
    }
    return m;
}

// Tek boyutlu dizi kullanarak matrisi ekrana yazdırma
void printMatrix(const MATRIX *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%5.2f ", m->data[i * m->cols + j]); // Tek boyutlu diziden değer okuma
        }
        printf("\n");
    }
}

// Matris için belleği serbest bırakma
void freeMatrix(MATRIX *m) {
    free(m->data); // Tek boyutlu dizi için ayrılan belleği serbest bırak
    m->rows = 0;
    m->cols = 0;
}

int main() {
    MATRIX m1 = createMatrix(3, 3); // 3x3'lük bir matris oluştur
    printMatrix(&m1);                // Matrisi yazdır
    freeMatrix(&m1);                // Belleği serbest bırak
    return 0;
}
