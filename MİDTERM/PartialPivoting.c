#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double *data; // Tek boyutlu dizi olarak matris verileri
    int rows;
    int cols;
} MATRIX;
MATRIX createMatrix(int rows, int cols);

bool PivotingGaussJordan(
    MATRIX *m,
    double x[]
); 



int main() 
{
    MATRIX work;
    int n;
    double temp;
    double x[3];
    printf("Please enter row & col ");
    scanf("%d", &n);
    work = createMatrix(n, n +1);
    for(size_t i =0; i<n; i++) {
        for(size_t j = 0; j<=n; j++) {
        if(j<n){
            printf("Please enter %d row %d col: ",i,j);
            scanf("%lf",&temp);
            work.data[i*n + j] = temp;
         }
        else if(j == n) {
            printf("Please enter %d equation answer: ",i);
            scanf("%lf", &temp);
            work.data[i*n +j] = temp;
         } 
        }
    }
    if (PivotingGaussJordan(&work, x)) {
        printf("Solution is: %lf %lf %lf\n", x[0], x[1], x[2]);
    }
    else {
        printf("No solution found\n");
    }

    return 0;
}
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

bool PivotingGaussJordan(MATRIX *m, double x[]) {
    double tol = 1e-6;
    int n = m->rows; // Assuming square matrix excluding augmented column
    for(int i = 0; i < n; i++) {
        double max = 0.0;
        int swap = i;
        for(int k = i; k < n; k++) {
            double temp = fabs(m->data[k*m->cols + i]);
            if(temp > max) {
                max = temp;
                swap = k;
            }
        }
        if (max < tol) return false;

        // Swap rows if needed
        if (swap != i) {
            for(int k = 0; k < m->cols; k++) {
                double temp = m->data[i*m->cols + k];
                m->data[i*m->cols + k] = m->data[swap*m->cols + k];
                m->data[swap*m->cols + k] = temp;
            }
        }

        // Eliminate off-diagonal elements
        for (int j = 0; j < n; j++) {
            if(j != i) {
                double factor = m->data[j*m->cols + i] / m->data[i*m->cols + i];
                for (int k = 0; k < m->cols; k++) {
                    if (k != i) {
                        m->data[j*m->cols + k] -= factor * m->data[i*m->cols + k];
                    }
                }
                m->data[j*m->cols + i] = 0; // Directly set to zero for numerical stability
            }
        }
    }
    // Compute solution
    for (int i = 0; i < n; i++) {
        x[i] = m->data[i*m->cols + n] / m->data[i*m->cols + i];
    }
    printf("Solution is: %lf %lf %lf\n", x[0], x[1], x[2]);
    return true;
}

