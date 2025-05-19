// Попълнете масив Х елемента и го попълнете с числа.
// Изкарайте елементите на главния диагонал. 
// Изкарайте елементите на второстепенния диагонал.
// Изведете елементите над главния диагонал. 
// Изведете елементите под главния диагонал.

#include <stdio.h>

#define N 3 

void printMainDiagonal(int matrix[N][N]) {
    printf("Main Diagonal: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void printSecondaryDiagonal(int matrix[N][N]) {
    printf("Secondary Diagonal: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][N - i - 1]);
    }
    printf("\n");
}

void printAboveMainDiagonal(int matrix[N][N]) {
    printf("Elements above diagonal:\n");
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printBelowMainDiagonal(int matrix[N][N]) {
    printf("Elements below diagonal:\n");
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N];

    printf("Eneter elements of matrix %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printMainDiagonal(matrix);
    printSecondaryDiagonal(matrix);
    printAboveMainDiagonal(matrix);
    printBelowMainDiagonal(matrix);

    return 0;
}


// Направете програма, която проверява дали един квадрат е магически(сумите на
// числата във всички редове и колони да е равна на едно и също число).
#include <stdio.h>

#define N 3 

int sumMainDiagonal(int matrix[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int sumSecondaryDiagonal(int matrix[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][N - i - 1];
    }
    return sum;
}

int isMagicSquare(int matrix[N][N]) {
    int magicSum = sumMainDiagonal(matrix);

    if (sumSecondaryDiagonal(matrix) != magicSum) {
        return 0;
    }

    // Check sum rows
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) {
            return 0;
        }
    }

    // Check sum coloms
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) {
            return 0;
        }
    }

    return 1; 
}

int main() {
    int matrix[N][N];

    printf("Enter elements of matrix %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isMagicSquare(matrix)) {
        printf("Magic Square!\n");
    } else {
        printf("NOT a Magic Square!\n");
    }

    return 0;
}


// Дадена с квадратна матрица NxN. 
// Създай нова матрица, която с получена чре завъртане на оригиналната на 90° по часовниковата стрелка.
#include <stdio.h>

#define N 3

void rotateMatrix90Clock(int matrix[N][N], int rotated[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - 1 - i] = matrix[i][j];
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N], rotated[N][N];

    printf("Enter elements of matrix %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotateMatrix90Clock(matrix, rotated);

    printf("Normal matrix is :\n");
    printMatrix(matrix);
    
    printf("Rotated matrix is :\n");
    printMatrix(rotated);

    return 0;
}


// Да се създаде матрица, която се запълва със стойности от 1 до и последни начин
// първият ред - отляво надясно 
// вторият ред  - отдясно наляво  
// третият ред - отляво надясно
#include <stdio.h>

#define N 3

void fillMatrixZigzag(int matrix[N][N]) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { 
            // отляво надясно
            for (int j = 0; j < N; j++) {
                matrix[i][j] = value++;
            }
        } else { 
            // отдясно наляво
            for (int j = N - 1; j >= 0; j--) {
                matrix[i][j] = value++;
            }
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N];

    fillMatrixZigzag(matrix);

    printf("Matrix Xigxag is:\n");
    printMatrix(matrix);

    return 0;
}


// дена с основна матрица A[m][n] и по-малка матрица B[p][q]. 
// Програмата трябва да провери дали се съдържа като подматрица в А (т.е. всички нейни елементи да са в точно 
// тази форма някъде в А). 
// Пример: Матрица А
// 1 2 3 4 
// 5 6 7 8 
// 9 0 1 2 
// Матрица В
// 6 7 
// 0 1 
// Матрица В се съдържа в А, започвайки от ред 1, колона 1.
#include <stdio.h>

void inputMatrix(int matrix[][10], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]); 
        }
    }
}

int isSubmatrix(int A[][10], int B[][10], int m, int n, int p, int q, int *row, int *col) {
    // Loop through all possible positions
    for (int i = 0; i <= m - p; i++) { // A[m][n] B[p][q]
        for (int j = 0; j <= n - q; j++) { 
            int match = 1; 

            // Check if all elements of B match the corresponding submatrix in A
            for (int x = 0; x < p; x++) {
                for (int y = 0; y < q; y++) {
                    if (A[i + x][j + y] != B[x][y]) { // If any element doesn't match
                        match = 0; 
                        break;
                    }
                }
                if (!match) 
                    break;
            }

            if (match) { 
                *row = i; // Store the starting row index
                *col = j; // Store the starting column index
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int m, n, p, q;
    int A[10][10], B[10][10]; 

    printf("Enter the dimensions of matrix A (rows columns): ");
    scanf("%d %d", &m, &n);
    inputMatrix(A, m, n); 

    printf("Enter the dimensions of matrix B (rows columns): ");
    scanf("%d %d", &p, &q);
    inputMatrix(B, p, q);

    int row, col;
    if (isSubmatrix(A, B, m, n, p, q, &row, &col)) {
        printf("Matrix B is found in Matrix A starting at row %d, column %d.\n", row + 1, col + 1);
    } else {
        printf("Matrix B is NOT found in Matrix A.\n");
    }

    return 0; 
}
