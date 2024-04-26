#include <stdio.h>
#include <stdlib.h>

// 3x3 matrisin determinantını hesaplayan fonksiyon
double determinant3x3(double* matrix) {
    double det = matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7])
               - matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6])
               + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
    return det;
}

int main() {
    double *matrix = (double *)malloc(9 * sizeof(double));  // 9 elemanlı tek boyutlu dizi olarak bellek ayırma

    printf("Please enter 3x3 matrix: row by row\n");
    // 3x3 matrisin kullanıcıdan alınması (tek boyutlu dizide saklama)
    for (int i = 0; i < 9; i++) {
        scanf("%lf", &matrix[i]);
    }

    // Matrisi gösterme (isteğe bağlı)
    printf("Entered matrix:\n");
    for (int i = 0; i < 9; i++) {
        printf("%f ", matrix[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }

    // Determinant hesaplama
    double det = determinant3x3(matrix);
    printf("Determinant: %f\n", det);

    free(matrix);  // Belleği serbest bırakma

    return 0;
}
