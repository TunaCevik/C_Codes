#include <stdio.h>
#define MAX 10

void getCofactor(int mat[MAX][MAX], int temp[MAX][MAX], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[MAX][MAX], int n) {
    int D = 0;
    if (n == 1)
        return mat[0][0];

    int temp[MAX][MAX];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return D;
}

void adjoint(int mat[MAX][MAX], int adj[MAX][MAX], int N) {
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1, temp[MAX][MAX];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(mat, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}

void display(int mat[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }
}

void inputMatrix(int mat[MAX][MAX], int N) {
    printf("Enter the elements of the matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &mat[i][j]);
}

int main() {
    int N;
    printf("Enter the size of the matrix: ");
    scanf("%d", &N);

    int mat[MAX][MAX], adj[MAX][MAX];

    if (N > MAX) {
        printf("Error: The maximum size allowed is %d.\n", MAX);
        return 1;
    }

    inputMatrix(mat, N);

    printf("Original matrix is:\n");
    display(mat, N);

    adjoint(mat, adj, N);
    printf("The adjoint is:\n");
    display(adj, N);

    printf("The determinant is: %d\n", determinant(mat, N));

    return 0;
}
