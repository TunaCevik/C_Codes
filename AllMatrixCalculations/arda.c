#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20 // Maksimum matris boyutu

typedef struct {
    float data[MAX_SIZE][MAX_SIZE * 2]; // Genişletilmiş matris
    int size; // Matris boyutu
} ExtendedMatrix;

void inputMatrixForInverse(ExtendedMatrix *m) {
    // Matrisin tersini almak için girişler
    printf("Enter the size N for the NxN matrix: ");
    scanf("%d", &m->size);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m->data[i][j]);
            m->data[i][j + m->size] = (i == j) ? 1.0f : 0.0f; // Birim matrisin eklenmesi
        }
    }
}

void inputMatrixForSolution(ExtendedMatrix *m) {
    // Lineer denklem sistemi çözümü için girişler
    printf("Enter the size N for the NxN matrix: ");
    scanf("%d", &m->size);
    printf("Enter the elements of the matrix and the results vector:\n");
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m->data[i][j]);
        }
        printf("Enter result for equation %d: ", i + 1);
        scanf("%f", &m->data[i][m->size]);
    }
}

void gaussJordanElimination(ExtendedMatrix *m) {
    // Gauss-Jordan eliminasyonu
    int n = m->size;
    for (int i = 0; i < n; i++) {
        float pivot = m->data[i][i];
        if (pivot == 0.0f) {
            printf("No unique solution exists or matrix is singular.\n");
            return; // Değişiklik: exit(EXIT_FAILURE)'den return'e
        }
        for (int j = 0; j < 2 * n; j++) {
            m->data[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = m->data[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    m->data[k][j] -= factor * m->data[i][j];
                }
            }
        }
    }
}

void printResults(const ExtendedMatrix *m, int forInverse) {
    // Sonuçların yazdırılması
    if (forInverse) {
        printf("The inverse of the matrix is:\n");
        for (int i = 0; i < m->size; i++) {
            for (int j = m->size; j < 2 * m->size; j++) {
                printf("%.2f\t", m->data[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Solution of the system:\n");
        for (int i = 0; i < m->size; i++) {
            printf("x%d = %.2f\n", i + 1, m->data[i][m->size]);
        }
    }
}

int main() {
    ExtendedMatrix m;
    int choice;

    while (1) { // Sonsuz döngü
        printf("\nChoose the operation:\n1. Find Inverse of Matrix\n2. Solve Linear System\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrixForInverse(&m);
                gaussJordanElimination(&m);
                printResults(&m, 1);
                break;
            case 2:
                inputMatrixForSolution(&m);
                gaussJordanElimination(&m);
                printResults(&m, 0);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0; // Programdan çıkış yap
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0; // Bu satıra ulaşılması gerekmiyor ama standart bir dönüş değeri sağlar.
}
