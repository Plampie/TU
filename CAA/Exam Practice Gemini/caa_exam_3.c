#include <stdio.h>
#include <locale.h> // За кирилица (ако конзолата поддържа)

#define MAX_N 100 // Максимален размер на матрицата

// Прототипи на функциите
void printTaskInfo();
void inputMatrix(int matrix[MAX_N][MAX_N], int *n);
void printMatrix(int matrix[MAX_N][MAX_N], int n);
void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[], int *size, int k, int l);
void sortArray(int arr[], int size);
void printArray(int arr[], int size, const char* message);

int main() {
    int A[MAX_N][MAX_N]; // Двумерен масив
    int C[MAX_N * MAX_N]; // Едномерен масив за резултата
    int N; // Размерност
    int K, L; // Граници на интервала
    int sizeC = 0; // Брой елементи в масив C

    // 1. Отпечатване на условието
    printTaskInfo();

    // 2. Отпечатване на автора
    printf("Автор на програмата: [Вашето Име]\n");
    printf("--------------------------------------------------\n");

    // 3. Въвеждане на матрицата
    inputMatrix(A, &N);

    // Въвеждане на интервала [K, L]
    printf("\n--- Въвеждане на интервал [K - L] ---\n");
    do {
        printf("Въведете долна граница K: ");
        scanf("%d", &K);
        printf("Въведете горна граница L: ");
        scanf("%d", &L);
        
        if (K > L) {
            printf("  -> Грешка! K трябва да е по-малко или равно на L. Опитайте пак.\n");
        }
    } while (K > L);

    // 4. Отпечатване на входните данни
    printf("\n--- Входна матрица А ---\n");
    printMatrix(A, N);

    // 5. Обработка а): Образуване на масив C (елементи в интервала [K, L])
    createArrayC(A, N, C, &sizeC, K, L);

    // Отпечатване на резултатите
    if (sizeC > 0) {
        printf("\n--- Резултати ---\n");
        printArray(C, sizeC, "а) Масив C (елементи в интервала):");
        
        // 6. Обработка б): Сортиране на масив C
        sortArray(C, sizeC);

        // 7. Отпечатване на сортирания масив
        printArray(C, sizeC, "б) Масив C след сортиране (възходящ ред):");
    } else {
        printf("\nНяма намерени елементи в интервала [%d, %d].\n", K, L);
    }

    return 0;
}

// --- Реализация на функциите ---

void printTaskInfo() {
    printf("==================================================\n");
    printf("УСЛОВИЕ НА ЗАДАЧАТА:\n");
    printf("Обработка на масив A[N,N] с числа в интервал [-100; 100].\n");
    printf("а) Образуване на масив C от елементите на A,\n");
    printf("   попадащи в интервал [K, L].\n");
    printf("б) Сортиране на масив C по големина.\n");
    printf("==================================================\n");
}

void inputMatrix(int matrix[MAX_N][MAX_N], int *n) {
    // Въвеждане на размерност
    do {
        printf("Въведете размерност N (макс %d): ", MAX_N);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_N);

    // Въвеждане на елементите
    printf("\nВъведете елементите (цели числа между -100 и 100):\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            int val;
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &val);
                if (val < -100 || val > 100) {
                    printf("  -> Грешка! Числото трябва да е в интервала [-100; 100].\n");
                }
            } while (val < -100 || val > 100);
            matrix[i][j] = val;
        }
    }
}

void printMatrix(int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Логика за подточка а)
void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[], int *size, int k, int l) {
    *size = 0; // Нулиране на брояча
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int current = matrix[i][j];
            // Проверка дали елементът е в интервала [K, L]
            if (current >= k && current <= l) {
                arr[*size] = current;
                (*size)++;
            }
        }
    }
}

// Логика за подточка б) - Метод на мехурчето
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Размяна
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size, const char* message) {
    printf("%s\n[ ", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}