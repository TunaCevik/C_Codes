#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double determinant3x3(double *matrix);
double determinant2x2(double *matrix);
bool SymetricMatrixChecker(double *matrix, size_t n);

int main() 
{
    double D1, D2, D3;
    size_t sizeMatrix;
    printf("give the matrix size");
    scanf("%zu", &sizeMatrix);
    double *M = (double *)malloc( 3 * 3 * sizeof(double));
    printf("Please enter 3x3 matrix (row by row): \n");
    scanf("%lf %lf %lf", &M[0], &M[1], &M[2]);
    scanf("%lf %lf %lf", &M[3], &M[4], &M[5]);
    scanf("%lf %lf %lf", &M[6], &M[7], &M[8]);

    if(SymetricMatrixChecker(M, sizeMatrix)) {
        if(sizeMatrix == 3) {
            D1 = M[0];
            printf("\ndet = %f\n",D1);
            D2 = determinant2x2(M);
            printf("\ndet = %f\n",D2);
            D3 = determinant3x3(M);
            printf("\ndet = %f\n",D3);
            D1*D2*D3>0 ? printf("Positive definite") : printf("Negative definite");
        }
        else if(sizeMatrix == 2) {
            D1 = M[0];
            printf("\ndet = %f\n",D1);
            D2 = determinant2x2(M);
            printf("\ndet = %f\n",D2);
            D1*D2 >0 ? printf("Positive definite") : printf("Negative definite");
        }
    } else {
        printf("%s" "Given Matrix is not symetric or higher order");
    }
    free(M);
    return 0;
}

// 3x3 matrisin determinantını hesaplayan fonksiyon
double determinant3x3(double* matrix) {
    double det = matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7])
               - matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6])
               + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
    return det;
}
double determinant2x2(double *matrix) {
    double det;
    det = (matrix[0] * matrix[4])
        - (matrix[1] * matrix[3]);
        
    return det;
}
bool SymetricMatrixChecker(double *matrix, size_t n) {
    if(n == 3) { 
        if(matrix[1]==matrix[3] && matrix[2]==matrix[6] && matrix[5]==matrix[7]) return true;
        else return false;
    }
    else if (n == 2) {
        if(matrix[1] == matrix[2]) return true;
        else false;
    }
    else {
        printf("the matrix cant not be calculated");
        return false;
    }
}
