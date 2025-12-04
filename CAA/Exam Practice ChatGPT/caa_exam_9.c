#include <stdio.h>
#include <stdlib.h>

#define MIN_VAL -1000.0
#define MAX_VAL  1000.0

// Print task description
void printTask() {
    puts("TASK:");
    puts("Process a matrix A[N][N] with real numbers in [-1000; 1000].");
    puts("The program should:");
    puts(" - print the task and the author's name;");
    puts(" - read and display the matrix;");
    puts(" - (a) create array C with elements A[i][j] where (i + j) is even;");
    puts(" - (b) sort array C in ascending order;");
    puts(" - print results after steps (a) and (b).");
    puts("");
}

// Print author name
void printAuthor() {
    puts("AUTHOR: <your full name here>\n");
}

// Print matrix
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

// Print array
void printArray(const double *A, int size, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < size; ++i) {
        printf("%10.2f", A[i]);
    }
    puts("\n");
}

// Insertion sort for doubles
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
    printf("Enter N (matrix size A[N][N]): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Invalid matrix size.\n");
        return 1;
    }

    double *A = malloc(N * N * sizeof(double));
    double *C = malloc(N * N * sizeof(double)); // worst case
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

    // (a) Build C[] from elements where (i + j) is even
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i + j) % 2 == 0) {
                C[count++] = A[i * N + j];
            }
        }
    }

    if (count == 0) {
        puts("No elements found where (i + j) is even.");
    } else {
        printArray(C, count, "AFTER (a): Elements where (i + j) is even");

        // (b) Sort C[]
        sortArray(C, count);
        printArray(C, count, "AFTER (b): Sorted array C");
    }

    // Cleanup
    free(A);
    free(C);
    return 0;
}
