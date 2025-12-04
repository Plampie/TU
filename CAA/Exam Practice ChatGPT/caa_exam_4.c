#include <stdio.h>
#include <stdlib.h>

// Constants for value validation
#define MIN_VAL -1000.0
#define MAX_VAL  1000.0

// Function to print task description
void printTask() {
    puts("TASK:");
    puts("Process a square matrix A[N][N] with real numbers in the interval [-1000; 1000].");
    puts("The program should:");
    puts(" - print the task and author name;");
    puts(" - read and display matrix A;");
    puts(" - (a) form array C from elements outside interval [L; M];");
    puts(" - (b) sort array C in ascending order;");
    puts(" - print results after each step.\n");
}

// Function to print author's name
void printAuthor() {
    puts("AUTHOR: <your full name here>\n");
}

// Function to print matrix
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

// Function to print an array
void printArray(const double *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%10.2f", A[i]);
    }
    puts("\n");
}

// Insertion sort for array of doubles
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
        fprintf(stderr, "Invalid size.\n");
        return 1;
    }

    // Allocate memory
    double *A = malloc(N * N * sizeof(double));
    if (!A) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read matrix A
    printf("Enter elements of matrix A (real numbers between -1000 and 1000):\n");
    for (int i = 0; i < N * N; ++i) {
        if (scanf("%lf", &A[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(A);
            return 1;
        }
        if (A[i] < MIN_VAL || A[i] > MAX_VAL) {
            printf("Warning: A[%d] = %.2f is out of range [%.0f; %.0f]\n", i, A[i], MIN_VAL, MAX_VAL);
        }
    }

    puts("");
    printMatrix(A, N, "Matrix A");

    // Read interval [L; M]
    double L, M;
    printf("Enter interval bounds L and M (L <= M): ");
    if (scanf("%lf %lf", &L, &M) != 2 || L > M) {
        fprintf(stderr, "Invalid interval.\n");
        free(A);
        return 1;
    }

    // (a) Form array C from elements outside [L; M]
    double *C = malloc(N * N * sizeof(double));
    if (!C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N * N; ++i) {
        if (A[i] < L || A[i] > M) {
            C[count++] = A[i];
        }
    }

    if (count == 0) {
        printf("No elements found outside the interval [%.2f, %.2f].\n", L, M);
    } else {
        printArray(C, count, "AFTER (a): Elements outside [L; M]");

        // (b) Sort C in ascending order
        sortArray(C, count);
        printArray(C, count, "AFTER (b): Sorted array C");
    }

    // Cleanup
    free(A);
    free(C);
    return 0;
}