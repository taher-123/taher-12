#include <stdio.h>

int main() {
    int A[2][2], B[2][2], sum[2][2], diff[2][2];

    // Input for Matrix A
    printf("Enter elements of Matrix A (2x2):\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input for Matrix B
    printf("Enter elements of Matrix B (2x2):\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition and Subtraction
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    // Print Sum
    printf("\nSum of A and B:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // Print Difference
    printf("\nDifference of A and B:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}
