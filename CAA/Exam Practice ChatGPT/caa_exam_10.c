#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -1000.0
#define MAX_VAL  1000.0

void printTask() {
    puts("TASK:");
    puts("Process a matrix A[N][N] with real numbers in [-1000; 1000].");
    puts("The program should:");
    puts(" - print the task and the author's name;");
    puts(" - read and display matrix A;");
    puts(" - (a) create array C with elements below the main diagonal (i > j);");
    puts(" - (b) sort array C in ascending order;");
    puts(" - print results after steps (a) and (b).\n");
}

void printAuthor() {
    puts("AUTHOR: <your full name here>\n");
}

void printMatrix(double *A, int N, const char *name) {
    printf("%s =\n", name);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%10.2f", A[i * N + j]);
        }
        putchar('\n');
    }
    puts("");
}

void printArray(const double *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%10.2f", A[i]);
    }
    puts("\n");
}

void sortArray(double *A, int size) {
    for (int i = 1; i < size; ++i) {
        double key = A[i];
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
        fprintf(stderr, "Invalid matrix size.\n");
        return 1;
    }

    double *A = malloc(N * N * sizeof(double));
    double *C = malloc(N * (N - 1) / 2 * sizeof(double));  // Only below-diagonal elements
    if (!A || !C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A); free(C);
        return 1;
    }

    // Input matrix
    printf("Enter elements of matrix A (real numbers in [-1000; 1000]):\n");
    for (int i = 0; i < N * N; ++i) {
        if (scanf("%lf", &A[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(A); free(C);
            return 1;
        }
        if (A[i] < MIN_VAL || A[i] > MAX_VAL) {
            printf("Warning: A[%d] = %.2f is out of range [%.0f; %.0f]\n", i, A[i], MIN_VAL, MAX_VAL);
        }
    }

    puts("");
    printMatrix(A, N, "Matrix A");

    // (a) Extract elements below main diagonal (i > j)
    int count = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            C[count++] = A[i * N + j];
        }
    }

    if (count == 0) {
        puts("No elements found below the main diagonal.");
    } else {
        printArray(C, count, "AFTER (a): Elements below the main diagonal");

        // (b) Sort
        sortArray(C, count);
        printArray(C, count, "AFTER (b): Sorted array C");
    }

    // Cleanup
    free(A);
    free(C);
    return 0;
}
