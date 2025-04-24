#include <stdio.h>

#define MAX 10

void getMatrixInput(int matrix[MAX][MAX], int rows, int cols, char name) {
    printf("Enter elements of Matrix %c (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d] = ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols, const char* label) {
    printf("%s:\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

void divideMatrix(int a[MAX][MAX], int b[MAX][MAX], float result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = (b[i][j] != 0) ? (float)a[i][j] / b[i][j] : 0;
}

void printFloatMatrix(float matrix[MAX][MAX], int rows, int cols, const char* label) {
    printf("%s:\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], add[MAX][MAX], sub[MAX][MAX], mul[MAX][MAX];
    float div[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    getMatrixInput(a, r1, c1, 'A');
    getMatrixInput(b, r2, c2, 'B');

    // Addition and subtraction
    if (r1 == r2 && c1 == c2) {
        addMatrix(a, b, add, r1, c1);
        subtractMatrix(a, b, sub, r1, c1);
        printMatrix(add, r1, c1, "Addition Result");
        printMatrix(sub, r1, c1, "Subtraction Result");
        divideMatrix(a, b, div, r1, c1);
        printFloatMatrix(div, r1, c1, "Element-wise Division Result");
    } else {
        printf("Addition/Subtraction/Division not possible: Matrix sizes don't match.\n");
    }

    // Multiplication
    if (c1 == r2) {
        multiplyMatrix(a, b, mul, r1, c1, c2);
        printMatrix(mul, r1, c2, "Multiplication Result");
    } else {
        printf("Multiplication not possible: Column of A != Row of B.\n");
    }

    return 0;
}
