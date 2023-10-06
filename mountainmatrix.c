#include<stdio.h>

void bubbleSort(int array[], int nr_elements){
    for(int i=0; i<nr_elements - 1; i++){
        for(int j=0; j<nr_elements-i-1; j++){
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){

    int n,m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int matrix[n][m];
    printf("Enter the elements of the matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int total = n*m;
    int array[total];

    int k = 0;
    for (int row_nr = 0; row_nr < n; row_nr++) {
        for (int col_nr = 0; col_nr < m; col_nr++) {
            array[k++] = matrix[row_nr][col_nr];
        }
    }

    bubbleSort(array, total);

    int startRow = 0, startCol = 0, lastCol = m-1, lastRow = n-1;
    k = 0; // reseting the index for array

    while(startCol<=lastCol && startRow<=lastRow){
        for(int i=startCol; i<=lastCol;i++){
            matrix[startRow][i] = array[k++];
        } startRow++;

        for(int i=startRow; i<=lastRow; i++){
            matrix[i][lastCol] = array[k++];
        } lastCol--;

        if(startRow<=lastRow){
            for(int i=lastCol; i>=startCol;i--){
                matrix[lastRow][i] = array[k++];
            } lastRow--;
        }
        if(startCol<=lastCol){
            for(int i= lastRow; i>=startRow; i--){
                matrix[i][startCol]=array[k++];
            } startCol++;

        }
    }

    printf("Mountain Matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
