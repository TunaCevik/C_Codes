#include <stdio.h>

// 3x3 matrisin kofaktörünü hesaplayan fonksiyon
void getCofactor(int mat[3][3], int temp[3][3], int p, int q, int n) {
    int i = 0, j = 0;

    // Geçici matrisi doldurma
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // p ve q'yu hariç tutarak kofaktörü oluştur
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];

                // Satır tamamlandığında, sütun sıfırla ve bir sonraki satıra geç
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Genel determinant hesaplayan fonksiyon
int determinant(int mat[3][3], int n) {
    int det = 0;

    // 1x1 matrisin determinantı matrisin kendisidir
    if (n == 1)
        return mat[0][0];

    int temp[3][3]; // Geçici matris
    int sign = 1;  // İşaret değiştirici

    // Her sütun için kofaktör ve determinantı hesapla
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        det += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

// Fonksiyon matrisin tersini almak için
void inverse(int mat[3][3], float inverse[3][3]) {
    int det = determinant(mat, 3);
    if (det == 0) {
        printf("Singular matrix, can't find its inverse");
        return;
    }

    int temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Kofaktörleri bul ve transpoze et
            getCofactor(mat, temp, i, j, 3);
            // Döküm işareti: çiftler için + ve tekler için -
            int sign = ((i+j)%2==0)? 1: -1;

            // Kofaktörlerin ve determinantın bölünmesi
            inverse[j][i] = (sign)*(float)determinant(temp, 2)/det;
        }
    }
}

int main() {
    int mat[3][3] = {
        {4, 3, 2},
        {3, 2, 1},
        {2, 1, 3}
    };
    float inv[3][3]; // Ters matrisi saklamak için

    inverse(mat, inv);

    printf("Inverse of the matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
