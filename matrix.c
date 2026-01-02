#include <stdio.h>

// Function declarations
void inputMatrix(int r, int c, int mat[10][10]);
void displayMatrix(int r, int c, int mat[10][10]);
void addMatrix(int r, int c, int a[10][10], int b[10][10]);
void multiplyMatrix(int r1, int c1, int r2, int c2, int a[10][10], int b[10][10]);
void transposeMatrix(int r, int c, int mat[10][10]);

int main() {
    int choice;
    int r1, c1, r2, c2;
    int A[10][10], B[10][10];

    do {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter first matrix:\n");
            inputMatrix(r1, c1, A);

            printf("Enter second matrix:\n");
            inputMatrix(r1, c1, B);

            addMatrix(r1, c1, A, B);
            break;

        case 2:
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Matrix multiplication not possible.\n");
            } else {
                printf("Enter first matrix:\n");
                inputMatrix(r1, c1, A);

                printf("Enter second matrix:\n");
                inputMatrix(r2, c2, B);

                multiplyMatrix(r1, c1, r2, c2, A, B);
            }
            break;

        case 3:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter matrix:\n");
            inputMatrix(r1, c1, A);

            transposeMatrix(r1, c1, A);
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function definitions
void inputMatrix(int r, int c, int mat[10][10]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int r, int c, int mat[10][10]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int r, int c, int a[10][10], int b[10][10]) {
    int sum[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Resultant Matrix (Addition):\n");
    displayMatrix(r, c, sum);
}

void multiplyMatrix(int r1, int c1, int r2, int c2, int a[10][10], int b[10][10]) {
    int mul[10][10] = {0};

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                mul[i][j] += a[i][k] * b[k][j];

    printf("Resultant Matrix (Multiplication):\n");
    displayMatrix(r1, c2, mul);
}

void transposeMatrix(int r, int c, int mat[10][10]) {
    int trans[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = mat[i][j];

    printf("Transpose of Matrix:\n");
    displayMatrix(c, r, trans);
}
