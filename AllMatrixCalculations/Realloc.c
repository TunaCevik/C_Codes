#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data; // Tek boyutlu dizi olarak matris verileri
    int rows;
    int cols;
} MATRIX;

// Matris oluşturma
MATRIX createMatrix(int rows, int cols) {
    MATRIX m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double *)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++) {
        m.data[i] = 0.0; // Başlangıçta tüm değerleri sıfırla
    }
    return m;
}

// Matrisi yeniden boyutlandırma
void resizeMatrix(MATRIX *m, int new_rows, int new_cols) {
    double *new_data = (double *)realloc(m->data, new_rows * new_cols * sizeof(double));
    if (new_data == NULL) {
        // realloc başarısız oldu, eski veriler hala geçerli
        printf("Memory reallocation failed\n");
        return;
    }
    
    // realloc başarılı, yeni verileri ayarla
    m->data = new_data;
    // Yeni eklenen alanları sıfırla
    for (int i = m->rows * m->cols; i < new_rows * new_cols; i++) {
        m->data[i] = 0.0;
    }
    // Yeni satır ve sütun sayılarını güncelle
    m->rows = new_rows;
    m->cols = new_cols;
}

// Belleği serbest bırakma
void freeMatrix(MATRIX *m) {
    free(m->data);
    m->rows = 0;
    m->cols = 0;
}

int main() {
    // 2x2 matris oluştur
    MATRIX m = createMatrix(2, 2);
    m.data[0] = 1; m.data[1] = 2;
    m.data[2] = 3; m.data[3] = 4;

    // Matrisi 3x3'e yeniden boyutlandır
    resizeMatrix(&m, 3, 3);

    // Belleği serbest bırak
    freeMatrix(&m);
    
    return 0;
}
