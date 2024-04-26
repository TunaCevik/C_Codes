#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double determinant3x3(double *matrix);
double determinant2x2(double *matrix);
bool symmetricMatrixChecker(double *matrix, size_t n);

int main() 
{
    double D1, D2, D3;
    printf("Please enter a 3x3 matrix (row by row):\n");
    double *M = (double *)malloc(3 * 3 * sizeof(double));
    for (int i = 0; i < 9; i++) {
        scanf("%lf", &M[i]);
    }

    if(symmetricMatrixChecker(M, 3)) {
        D1 = M[0];
        printf("\ndet = %f\n",D1);
        D2 = determinant2x2(M);
        printf("\ndet = %f\n",D2);
        D3 = determinant3x3(M);
        printf("\ndet = %f\n",D3);
        (D1 * D2 * D3 > 0) ? printf("Positive definite") : printf("Negative definite");
    } else {
        printf("Given Matrix is not symmetric");
    }
    free(M);
    return 0;
}


double determinant3x3(double* matrix) {
    return matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7])
         - matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6])
         + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
}


double determinant2x2(double *matrix) {
    return (matrix[0] * matrix[4]) - (matrix[1] * matrix[3]);
}


bool symmetricMatrixChecker(double *matrix, size_t n) {
    if (n == 3) {
        return (matrix[1] == matrix[3] && matrix[2] == matrix[6] && matrix[5] == matrix[7]);
    } else {
        printf("The matrix cannot be calculated for size other than 3.\n");
        return false;
    }
}
