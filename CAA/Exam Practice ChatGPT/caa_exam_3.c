#include <stdio.h>
#include <stdlib.h>

// Constants
#define MIN_VAL -100
#define MAX_VAL  100

// Helper functions
void printTask() {
    puts("TASK:");
    puts("Write a program to process a square matrix A[N][N] with integers in [-100; 100].");
    puts("The program should:");
    puts(" - print the task and author name;");
    puts(" - read and print the input matrix;");
    puts(" - (a) extract elements in the interval [K - L] to a 1D array C;");
    puts(" - (b) sort array C in ascending order;");
    puts(" - print the results after each step.");
    puts("");
}

void printAuthor() {
    puts("AUTHOR: <your full name here>");
    puts("");
}

void printMatrix(int *A, int N, const char *name) {
    printf("%s =\n", name);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%5d", A[i * N + j]);
        }
        putchar('\n');
    }
    puts("");
}

void printArray(const int *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%5d", A[i]);
    }
    puts("\n");
}

// Simple insertion sort
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
    if (!A) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter matrix A[%d][%d] (integers between -100 and 100):\n", N, N);
    for (int i = 0; i < N * N; ++i) {
        if (scanf("%d", &A[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(A);
            return 1;
        }
        if (A[i] < MIN_VAL || A[i] > MAX_VAL) {
            printf("Warning: A[%d] = %d is outside the allowed range [%d, %d].\n",
                   i, A[i], MIN_VAL, MAX_VAL);
        }
    }
    puts("");

    printMatrix(A, N, "Matrix A");

    // Read interval [K - L]
    int K, L;
    printf("Enter interval bounds K and L (K <= L): ");
    if (scanf("%d %d", &K, &L) != 2 || K > L) {
        fprintf(stderr, "Invalid interval.\n");
        free(A);
        return 1;
    }

    // a) Extract elements into array C
    int *C = malloc(N * N * sizeof(int));
    if (!C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N * N; ++i) {
        if (A[i] >= K && A[i] <= L) {
            C[count++] = A[i];
        }
    }

    if (count == 0) {
        printf("No elements found in the interval [%d, %d].\n", K, L);
    } else {
        printArray(C, count, "AFTER (a): Elements in [K - L]");

        // b) Sort C
        sortArray(C, count);
        printArray(C, count, "AFTER (b): Sorted array C");
    }

    free(A);
    free(C);
    return 0;
}
