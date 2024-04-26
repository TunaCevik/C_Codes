#include <stdio.h>
#include <stdlib.h>

// 3x3 matrisin determinantını hesaplayan fonksiyon
double determinant3x3(double** matrix) {
    double det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
               - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
               + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

int main() {
    double** matrix = (double**)malloc(3 * sizeof(double*));  // Her satır için bellek ayırma
    for (int i = 0; i < 3; i++) {
        matrix[i] = (double*)malloc(3 * sizeof(double));  // Her sütun için bellek ayırma
    }

    printf("Please enter 3x3 matrix: row by row\n");
    // 3x3 matrisin kullanıcıdan alınması
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Matrisi gösterme (isteğe bağlı)
    printf("Entered matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Determinant hesaplama
    double det = determinant3x3(matrix);
    printf("Determinant: %f\n", det);

    // Belleği serbest bırakma
    for (int i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
