#include <stdio.h>

// Defined constant for maximum array size
#define MAX_N 100

// Function Prototypes
void printTaskInfo();
void inputMatrix(int matrix[MAX_N][MAX_N], int n, char name);
void printMatrix(int matrix[MAX_N][MAX_N], int n, char name);
void sortArray(int arr[], int n);
void printArray(int arr[], int n, const char* description);

int main() {
    // Data structures
    int A[MAX_N][MAX_N];
    int B[MAX_N][MAX_N];
    int C[MAX_N];
    int N;
    int i; // Loop counter

    // 1. Print Task Condition
    printTaskInfo();

    // 2. Print Author
    printf("Author: Student Name / AI Assistant\n");
    printf("--------------------------------------------------\n");

    // 3. Input Data
    printf("Enter the dimension N (max %d): ", MAX_N);
    if (scanf("%d", &N) != 1 || N > MAX_N || N <= 0) {
        printf("Error: Invalid dimension entered.\n");
        return 1;
    }

    printf("\n--- Input for Matrix A ---\n");
    inputMatrix(A, N, 'A');

    printf("\n--- Input for Matrix B ---\n");
    inputMatrix(B, N, 'B');

    // 4. Print Input Data
    printf("\n--- Visualizing Input Matrices ---\n");
    printMatrix(A, N, 'A');
    printMatrix(B, N, 'B');

    // 5. Processing (a): Create array C from main diagonals
    // Logic: C[i] = A[i][i] + B[i][i]
    for (i = 0; i < N; i++) {
        C[i] = A[i][i] + B[i][i];
    }

    // Print result after step (a)
    printf("\n--- Result A: Array C (Sum of diagonals) ---\n");
    printArray(C, N, "Unsorted C");

    // 6. Processing (b): Sort array C by magnitude (Ascending)
    sortArray(C, N);

    // 7. Print result after step (b)
    printf("\n--- Result B: Array C (Sorted by magnitude) ---\n");
    printArray(C, N, "Sorted C");

    return 0;
}

// --- Function Implementations ---

void printTaskInfo() {
    printf("==================================================\n");
    printf("TASK DESCRIPTION:\n");
    printf("Process two matrices A[N,N] and B[N,N] with integers\n");
    printf("in the range [-1000; 1000].\n");
    printf("a) Form array C[N] summing main diagonal elements of A and B.\n");
    printf("b) Sort array C by magnitude.\n");
    printf("==================================================\n");
}

void inputMatrix(int matrix[MAX_N][MAX_N], int n, char name) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int val;
            do {
                printf("Enter element %c[%d][%d] (-1000 to 1000): ", name, i, j);
                scanf("%d", &val);
                if (val < -1000 || val > 1000) {
                    printf("Warning: Value out of range! Try again.\n");
                }
            } while (val < -1000 || val > 1000);
            matrix[i][j] = val;
        }
    }
}

void printMatrix(int matrix[MAX_N][MAX_N], int n, char name) {
    int i, j;
    printf("Matrix %c:\n", name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // %6d reserves 6 spaces for the integer, aligning the columns
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Bubble Sort implementation (O(N^2))
void sortArray(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n, const char* description) {
    int i;
    printf("%s: [ ", description);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}