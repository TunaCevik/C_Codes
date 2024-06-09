#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int row, int col,int ***matrix);
void printMatrix(int row, int col, int **matrix);
void addMatrix(int row, int col, int **matrix1, int **matrix2);

int main(){

    int **M1;
    int **M2;
    int row1, row2, col1, col2;
    printf("Enter the row num for matrix1: ");
    scanf("%d", &row1);
    printf("Enter the col num for matrix1: ");
    scanf("%d", &col1);

    printf("Enter the row num for matrix2: ");
    scanf("%d", &row2);
    printf("Enter the col num for matrix2: ");
    scanf("%d", &col2);

    fillMatrix(row1, col1, &M1);
    printMatrix(row1, col1, M1);

    fillMatrix(row2, col2, &M2);
    printMatrix(row2, col2, M2);

    printf("\n$ADDITION$\n");
    addMatrix(row1, col1, M1, M2);
    
    return 0;
}

void fillMatrix(int row, int col,int ***matrix) {
    // Allocate memory for the rows
    *matrix = (int **)malloc(row * sizeof(int *));
    if (*matrix == NULL) {
        printf("Memory allocation failed for rows\n");
        exit(1);
    }

    // Allocate memory for the columns in each row
    for (int i = 0; i < row; i++) {
        (*matrix)[i] = (int *)malloc(col * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("Memory allocation failed for columns\n");
            exit(1);
        }
    }

    // Take user input to fill the matrix
    printf("Enter 9 integers to fill the 3x3 matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

void printMatrix(int row, int col, int **matrix) {
    printf("The 3x3 matrix is:\n");
    for (int i = 0; i < row; i++) {
        printf("| ");
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void addMatrix(int row, int col, int **matrix1, int **matrix2)
{
    for(int i=0;i<row;i++){
        printf("| ");
        for(int j=0;j<col;j++){
            printf("%d ", matrix1[i][j] + matrix2[i][j]);
        }
        printf("|\n");
    }
}