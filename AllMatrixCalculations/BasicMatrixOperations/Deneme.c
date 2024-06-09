#include <stdio.h>
#include "MatrixMultipilication.h"
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

// 3x3 matrisin kofaktörünü hesaplayan fonksiyon
int cofactor(int mat[3][3], int p, int q, int n) {
    int temp[2][2];
    int i = 0, j = 0;

    // Kofaktör matrisini oluşturma
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // p ve q satır ve sütunlarını hariç tut
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                // Yeni satıra geçiş yap
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    
    // 2x2 matrisin determinantını hesaplama
    return (temp[0][0] * temp[1][1]) - (temp[0][1] * temp[1][0]);
}

// Genel determinant hesaplayan fonksiyon
int determinant(int mat[3][3], int n) {
    int det = 0; // Sonucu saklayacak değişken

    // 1x1 matrisin determinantı matrisin kendisidir
    if (n == 1) {
        return mat[0][0];
    }

    int sign = 1;  // İşaret değiştirici

    // Her sütun için kofaktör hesapla
    for (int f = 0; f < n; f++) {
        // Kofaktörü hesapla ve onunla çarp
        det += sign * mat[0][f] * cofactor(mat, 0, f, n);
        // İşareti değiştir
        sign = -sign;
    }

    return det;
}

int main()
{
    
    return 0;
}
