#include <stdio.h>
#include <stdlib.h>
#include "EE204Unit4.h"


typedef struct 
{
    double *data;
    int rows;
    int cols;
}MATRIX;

MATRIX *EE204_4_createMatrix(int rows, int cols);
void EE204_4_freeMatrix(MATRIX *m);
void EE204_4_ResizeMatrix(MATRIX *m, int new_rows, int new_cols);
void EE204_4_PrintMatrix(const double *array, int row, int col);
void EE204_4_ResizeResult(double *array, int new_rows, int new_cols);
void EE204_4_Multiplication(
    MATRIX *matrixA, // İlk matris (3x3)
    MATRIX *matrixB, // İkinci matris (3x2)
    double *result // Sonuç matrisi (3x2)
);
//void EE204_4_InverseMatrix();



int main()
{
    int rows1 = 0, cols1 = 0, rows2=0, cols2=0;
    int CalChoice;
    char choice;
    MATRIX *Matrix1, *Matrix2;
    double *result = NULL;

    int counter = 0;
    do{
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
        "Which calculation you want to make: ", 
        "1: Cramers Rule", 
        "2: Determinant", 
        "3: Inverse", 
        "4: Transpose",
        "5: Cofactor", 
        "6: Adjoint", 
        "7: Matrix Multiplication", 
        "8: Matrix Addition", 
        "9: Matrix Substraction",
        "10: Pivoting Gauss Jordan Ellimiation");

        scanf(" %d", &CalChoice);
        printf("Enter the 1. matrix dimensions (rows ,cols)");
        scanf(" %d %d", &rows1, &cols1);
        printf("Enter the second matrix dimensions (rows, cols)");
        scanf(" %d %d", &rows2, &cols2);
        if(counter == 0){
            Matrix1 = EE204_4_createMatrix(rows1, cols1);
            Matrix2 = EE204_4_createMatrix(rows2, cols2);}

        switch (CalChoice){
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            if(counter == 0)  result = (double*)malloc(rows1*cols2*sizeof(double));
            if(counter != 0){
                EE204_4_ResizeMatrix(Matrix1, rows1, cols1);
                EE204_4_ResizeMatrix(Matrix2, rows2, cols2);
                EE204_4_ResizeResult(result, rows1, cols2);
            }
            for(int i = 0; i < rows1; i++){
                for(int j = 0; j < cols1; j++){
                    printf("(%d, %d) = ",i,j);
                    scanf("%lf", &(Matrix1->data[i*Matrix1->cols + j]));
                }
            }
            for(int i = 0; i < rows1; i++){
                for(int j = 0; j < cols1; j++){
                    printf("(%d, %d) = ",i,j);
                    scanf("%lf", &(Matrix2->data[i*Matrix2->cols + j]));
                }
            
            }
            EE204_4_Multiplication(Matrix1, Matrix2, (double*)result);
            EE204_4_PrintMatrix(result, rows1, cols2);
            break;
        case 8:
            /* code */
            break;
        case 9:
            /* code */
            break;
        case 10:
            /* code */        
            break;
        default:
            break;
        



        }
        counter++;
        printf("Do you want to make new calculation \n(Y / N):");
        scanf(" %c", &choice);
    }while(choice == 'Y' || choice == 'y');

    free(result);
    EE204_4_freeMatrix(Matrix1);
    EE204_4_freeMatrix(Matrix2);
    return 0;
}

// Tek boyutlu dizi ile matris oluşturma
MATRIX *EE204_4_createMatrix(int rows, int cols) {
    MATRIX *m = (MATRIX *)malloc(sizeof(MATRIX));
    if (m == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    m->rows = rows;
    m->cols = cols;
    m->data = (double *)malloc(rows * cols * sizeof(double));
    if (m->data == NULL) {
        printf("Memory allocation failed\n");
        free(m);
        return NULL;
    }

    for (int i = 0; i < rows * cols; i++) {
        m->data[i] = 0.0;
    }

    return m;
}
// Belleği serbest bırakma
void EE204_4_freeMatrix(MATRIX *m) {
    free(m->data);
    m->rows = 0;
    m->cols = 0;
}
// Matrisi yeniden boyutlandırma
void EE204_4_ResizeMatrix(MATRIX *m, int new_rows, int new_cols) {
    double *new_data = (double *)realloc(m->data, new_rows * new_cols * sizeof(double));
    if (new_data == NULL) {
        // realloc başarısız oldu, eski veriler hala geçerli
        printf("Memory reallocation failed\n");
    }
    
    // realloc başarılı, yeni verileri ayarla
    m->data = new_data;
    // Hepsini sıfırla
    for (int i = 0; i < new_rows * new_cols; i++) {
        m->data[i] = 0.0;
    }
    // Yeni satır ve sütun sayılarını güncelle
    m->rows = new_rows;
    m->cols = new_cols;
}
// Tek boyutlu dizi kullanarak matrisi ekrana yazdırma
void EE204_4_PrintMatrix(const double *array, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%5.2f ", array[i * col + j]); // Tek boyutlu diziden değer okuma
        }
        printf("\n");
    }
}

void EE204_4_Multiplication(
    MATRIX *matrixA, // İlk matris (3x3)
    MATRIX *matrixB, // İkinci matris (3x2)
    double *result // Sonuç matrisi (3x2)
) {
    // Matris çarpımının boyut kontrolü
    if (matrixA->cols != matrixB->rows) {
        printf("Matris boyutlari uyumsuz.\n");
        return; // Hatalı durumda fonksiyondan çık
    }

    // Matris çarpımını gerçekleştir
    for (int i = 0; i < matrixA->rows; i++) {
        for (int j = 0; j < matrixB->cols; j++) {
            result[i * matrixB->cols + j] = 0; // Sonuç matrisinin ilgili elemanını sıfırla
            for (int k = 0; k < matrixA->cols; k++) {
                result[i * matrixB->cols + j] += (matrixA->data[i * matrixA->cols + k]) * (matrixB->data[k *matrixB->cols + j]);
            }
        }
    }
}

void EE204_4_ResizeResult(double *array, int new_rows, int new_cols) {
    double *temp = (double *)realloc(array, (new_rows *new_cols)*sizeof(double));
    if (temp == NULL) {
        printf("Bellek yeniden boyutlandirma basarisiz.\n");
        free(array); // Yeniden boyutlandirma basarisiz olduysa, orijinal bellek serbest birakilir
    } else {
        array = temp; // Yeniden boyutlandirma basarili olduysa, array artik yeni bellek blokunu gosterir
    }
    for(int i = 0; i<new_rows*new_cols; i++) array[i] = 0.0;
}

