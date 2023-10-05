#include <stdio.h>

int main() {
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Invalid input for n or columns.\n");
        return 1;
    }

    int matrix[n][m];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // sum of elements from even rows
    int sumEven = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > 0) {
                sumEven += matrix[i][j];
            }
        }
    }

    // Calculate the product of elements smaller than 5 in odd columns
    int prodOdd = 1;
    for (int j = 1; j < m; j += 2) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < 5) {
                prodOdd *= matrix[i][j];
            }
        }
    }

    // Print the results
    printf("Sum of positive elements in even rows: %d\n", sumEven);
    printf("Product of elements smaller than 5 in odd columns: %d\n", prodOdd);

    return 0;
}
