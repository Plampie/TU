#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_VAL -1000
#define MAX_VAL  1000

// --- helpers ---
void printTask(void) {
    puts("TASK:");
    puts("Write a program that processes two N x N integer matrices A and B (values in [-1000;1000]).");
    puts("The program should:");
    puts(" - print the task statement;");
    puts(" - print the program author;");
    puts(" - read the input data and print it back;");
    puts(" - (a) form C[N] where C[i] = A[i][i] + B[i][i];");
    puts(" - (b) sort C by value;");
    puts(" - print results after (a) and after (b).");
    puts("");
}

void printAuthor(void) {
    puts("PROGRAM AUTHOR: ChatGPT");
    puts("");
}

void printMatrix(const int *M, int N, const char *name) {
    printf("%s =\n", name);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%6d", M[i*N + j]);
        }
        putchar('\n');
    }
    puts("");
}

void printArray(const int *A, int N, const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < N; ++i) {
        printf("%6d", A[i]);
    }
    putchar('\n');
    puts("");
}

bool inRange(int x) { return x >= MIN_VAL && x <= MAX_VAL; }

void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

int main(void) {
    printTask();
    printAuthor();

    int N;
    printf("Enter N (size of the square matrices): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Error: invalid N.\n");
        return 1;
    }

    // allocate
    int *A = (int*)malloc(N * N * sizeof(int));
    int *B = (int*)malloc(N * N * sizeof(int));
    int *C = (int*)malloc(N * sizeof(int));
    if (!A || !B || !C) {
        fprintf(stderr, "Error: not enough memory.\n");
        free(A); free(B); free(C);
        return 1;
    }

    // read A
    printf("Enter elements of A[%d,%d] (row by row):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (scanf("%d", &A[i*N + j]) != 1) {
                fprintf(stderr, "Error while reading A.\n");
                free(A); free(B); free(C);
                return 1;
            }
            if (!inRange(A[i*N + j])) {
                fprintf(stderr, "Warning: A[%d][%d]=%d is out of range [%d;%d].\n",
                        i, j, A[i*N + j], MIN_VAL, MAX_VAL);
            }
        }
    }
    puts("");

    // read B
    printf("Enter elements of B[%d,%d] (row by row):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (scanf("%d", &B[i*N + j]) != 1) {
                fprintf(stderr, "Error while reading B.\n");
                free(A); free(B); free(C);
                return 1;
            }
            if (!inRange(B[i*N + j])) {
                fprintf(stderr, "Warning: B[%d][%d]=%d is out of range [%d;%d].\n",
                        i, j, B[i*N + j], MIN_VAL, MAX_VAL);
            }
        }
    }
    puts("");

    // echo input
    puts("INPUT DATA:");
    printMatrix(A, N, "A");
    printMatrix(B, N, "B");

    // (a) form C from main diagonals
    for (int i = 0; i < N; ++i) {
        C[i] = A[i*N + i] + B[i*N + i];
    }
    printArray(C, N, "AFTER (a): C[i] = A[i][i] + B[i][i]");

    // (b) sort C ascending
    insertionSort(C, N);
    printArray(C, N, "AFTER (b): C sorted ascending");

    free(A); free(B); free(C);
    return 0;
}
