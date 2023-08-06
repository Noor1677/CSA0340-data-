#include <stdio.h>
#define ROWS 3
#define COLS 3
void matrixMultiplication(int mat1[ROWS][COLS], int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat1[ROWS][COLS];
    int mat2[ROWS][COLS];

    printf("Enter elements for Matrix 1 (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
   printf("Enter elements for Matrix 2 (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    int result[ROWS][COLS];
    matrixMultiplication(mat1, mat2, result);
    printf("\nMatrix 1:\n");
    printMatrix(mat1);
    printf("\nMatrix 2:\n");
    printMatrix(mat2);
    printf("\nMatrix Multiplication:\n");
    printMatrix(result);
    return 0;
}
