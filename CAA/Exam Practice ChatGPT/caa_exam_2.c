#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define MIN_VAL -10
#define MAX_VAL  10

// Helper functions
void printTask() {
    puts("TASK:");
    puts("Write a program that processes a square matrix A[N][N] with integer values in [-10; 10].");
    puts("The program should:");
    puts(" - print the task and author;");
    puts(" - read and display input data;");
    puts(" - (a) create array C[] from elements in A where square > 50;");
    puts(" - (b) sort C in ascending order;");
    puts(" - print results after each step.");
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
            printf("%4d", A[i * N + j]);
        }
        putchar('\n');
    }
    puts("");
}

void printArray(const int *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%4d", A[i]);
    }
    puts("\n");
}

// Insertion sort
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
    printf("Enter N (size of matrix A[N][N]): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Invalid size.\n");
        return 1;
    }

    int *A = malloc(N * N * sizeof(int));
    if (!A) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read matrix A
    printf("Enter %d x %d matrix A (integers between -10 and 10):\n", N, N);
    for (int i = 0; i < N * N; ++i) {
        if (scanf("%d", &A[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(A);
            return 1;
        }
        if (A[i] < MIN_VAL || A[i] > MAX_VAL) {
            printf("Warning: A[%d] = %d is outside of [%d; %d]\n", i, A[i], MIN_VAL, MAX_VAL);
        }
    }
    puts("");

    // Print matrix A
    printMatrix(A, N, "Matrix A");

    // a) Form array C[]
    int *C = malloc(N * N * sizeof(int)); // worst case: all elements qualify
    if (!C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N * N; ++i) {
        int square = A[i] * A[i];
        if (square > 50) {
            C[count++] = A[i];
        }
    }

    if (count == 0) {
        puts("No elements found with square greater than 50.");
    } else {
        printArray(C, count, "AFTER (a): Elements where A[i][j]^2 > 50");

        // b) Sort C[]
        sortArray(C, count);
        printArray(C, count, "AFTER (b): Sorted array C");
    }

    free(A);
    free(C);
    return 0;
}