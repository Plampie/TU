#include <stdio.h>
#include <stdlib.h>


// perimeter sum
int perimeter(int** matrix, int row, int col) {
    int sum = 0;

    // top
    for (int j = 0; j < col; j++) {
        sum += matrix[0][j];
    }

    // bottom
    if (row > 1) {
        for (int j = 0; j < col; j++) {
            sum += matrix[row - 1][j];
        }
    }

    for (int i = 1; i < row - 1; i++) {
        sum += matrix[i][0]; // left
        if (col > 1) {
            sum += matrix[i][col - 1]; // right
        }
    }

    return sum;
}


void diagonal_sum(int** matrix, int row, int col, int* result) {
    int sum = 0;
    int limit = row < col ? row : col; // if not square

    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    result[0] = sum;
}


void row_sums(int** matrix, int row, int col, int* row_sums) {
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[i][j];
        }
        row_sums[i] = sum;
    }
}


void under_diag(int** matrix, int row, int col, int* result) {
    int count = 0;

    for (int i = 1; i < row; i++) {
        for (int j = 0; j < i && j < col; j++) {
            if (matrix[i][j] < i + j) {
                count++;
            }
        }
    }

    result[0] = count;
}


void secondary_diag(int** matrix, int row, int col, int* result) {
    int sum = 0;
    int limit = row < col ? row : col;

    for (int i = 0; i < limit; i++) {
        int j = col - 1 - i;
        sum += matrix[i][j];
    }

    result[0] = sum;
}


void symmetric_pairs(int** matrix, int row, int col) {
    int limit = row < col ? row : col;

    printf("Symmetric pairs (matrix[i][j] < matrix[j][i]):\n");
    for (int i = 0; i < limit; i++) {
        for (int j = i + 1; j < limit; j++) {
            if (matrix[i][j] < matrix[j][i]) {
                printf("matrix[%d][%d] = %d < matrix[%d][%d] = %d\n",
                       i, j, matrix[i][j], j, i, matrix[j][i]);
            }
        }
    }
}



int main(){

    int row,col;

    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    //memory
    int** matrix = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }

    //enter matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }


    //print matrix
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    // perimeter
    int per = perimeter(matrix, row, col);
    printf("\nPerimeter sum of the matrix: %d\n", per);

    // main diag sum
    int main_diag_sum;
    diagonal_sum(matrix, row, col, &main_diag_sum);
    printf("\nSum of the main diagonal of the matrix: %d\n", main_diag_sum);

    // row sums
    int* row_sum = (int*)malloc(row * sizeof(int));
    row_sums(matrix, row, col, row_sum);
    printf("Sum of each row:\n");
    for (int i = 0; i < row; i++) {
        printf("Row %d sum: %d\n", i, row_sum[i]);
    }
    free(row_sum);

    // under diag elements
    int under_diag_el;
    under_diag(matrix, row, col, &under_diag_el);
    printf("\nCount of elements under the main diagonal lower than sum of their indexes: %d\n", under_diag_el);

    // secondary diag sum
    int sec_diag_sum;
    secondary_diag(matrix, row, col, &sec_diag_sum);
    printf("\nSum of the secondary diagonal of the matrix: %d\n", sec_diag_sum);


    symmetric_pairs(matrix, row, col);


    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}
