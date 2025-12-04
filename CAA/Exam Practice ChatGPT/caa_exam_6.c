#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -500
#define MAX_VAL  500

void printTask() {
    puts("TASK:");
    puts("Process a square matrix A[N][N] with integers in [-500; 500].");
    puts("The program should:");
    puts(" - print the task and the author's name;");
    puts(" - read and display the input matrix A;");
    puts(" - (a) form array C[N] with the maximum element from each column;");
    puts(" - (b) sort C in ascending order;");
    puts(" - print results after step (a) and step (b).\n");
}

void printAuthor() {
    puts("AUTHOR: <your full name here>\n");
}

void printMatrix(int *A, int N, const char *name) {
    printf("%s =\n", name);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%6d", A[i * N + j]);
        }
        putchar('\n');
    }
    puts("");
}

void printArray(const int *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%6d", A[i]);
    }
    puts("\n");
}

void sortArray(int *A, int size) {
    for (int i = 1; i < size; ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

int main() {
    printTask();
    printAuthor();

    int N;
    printf("Enter N (matrix size A[N][N]): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Invalid size.\n");
        return 1;
    }

    int *A = malloc(N * N * sizeof(int));
    int *C = malloc(N * sizeof(int));
    if (!A || !C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A); free(C);
        return 1;
    }

    printf("Enter %d x %d matrix A (integers between -500 and 500):\n", N, N);
    for (int i = 0; i < N * N; ++i) {
        if (scanf("%d", &A[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(A); free(C);
            return 1;
        }
        if (A[i] < MIN_VAL || A[i] > MAX_VAL) {
            printf("Warning: A[%d] = %d is out of range [%d; %d]\n", i, A[i], MIN_VAL, MAX_VAL);
        }
    }

    puts("");
    printMatrix(A, N, "Matrix A");

    // a) Maximum per column
    for (int col = 0; col < N; ++col) {
        int max = A[col];
        for (int row = 1; row < N; ++row) {
            int value = A[row * N + col];
            if (value > max) {
                max = value;
            }
        }
        C[col] = max;
    }

    printArray(C, N, "AFTER (a): Max elements from each column");

    // b) Sort C
    sortArray(C, N);
    printArray(C, N, "AFTER (b): Sorted array C");

    free(A);
    free(C);
    return 0;
}
