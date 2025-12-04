#include <stdio.h>
#include <locale.h> // За поддръжка на кирилица (зависи от конзолата)

#define MAX_N 100 // Максимален размер на матрицата

// Прототипи на функциите
void printTaskInfo();
void inputMatrix(int matrix[MAX_N][MAX_N], int *n);
void printMatrix(int matrix[MAX_N][MAX_N], int n);
void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[], int *size);
void sortArray(int arr[], int size);
void printArray(int arr[], int size, const char* message);

int main() {
    // Настройка за кирилица (може да изисква допълнителни настройки на конзолата в Windows)
    setlocale(LC_ALL, ""); 

    int A[MAX_N][MAX_N]; // Двумерен масив (матрица)
    int C[MAX_N * MAX_N]; // Едномерен масив (максимално може да съдържа всички елементи на A)
    int N; // Размерност на матрицата
    int k = 0; // Брой елементи в масив C

    // 1. Отпечатване на условието
    printTaskInfo();

    // 2. Отпечатване на автора
    printf("Автор на програмата: [Вашето Име]\n");
    printf("--------------------------------------------------\n");

    // 3. Въвеждане на данни
    inputMatrix(A, &N);

    // 4. Отпечатване на входните данни
    printf("\n--- Входна матрица А ---\n");
    printMatrix(A, N);

    // 5. Обработка а): Образуване на масив C (елементи с квадрат > 50)
    createArrayC(A, N, C, &k);

    // Отпечатване на резултата от а)
    if (k > 0) {
        printArray(C, k, "Масив C преди сортиране (елементи с квадрат > 50):");
        
        // 6. Обработка б): Сортиране на масив C
        sortArray(C, k);

        // 7. Отпечатване на резултата от б)
        printArray(C, k, "Масив C след сортиране (възходящ ред):");
    } else {
        printf("\nНяма елементи в матрицата, чиито квадрати са по-големи от 50.\n");
    }

    return 0;
}

// --- Реализация на функциите ---

void printTaskInfo() {
    printf("==================================================\n");
    printf("УСЛОВИЕ НА ЗАДАЧАТА:\n");
    printf("Обработка на масив A[N,N] с числа в интервал [-10; 10].\n");
    printf("а) Образуване на масив C от елементите на A,\n");
    printf("   чиито квадрати са > 50.\n");
    printf("б) Сортиране на масив C по големина.\n");
    printf("==================================================\n");
}

void inputMatrix(int matrix[MAX_N][MAX_N], int *n) {
    // Въвеждане на размерност
    do {
        printf("Въведете брой редове/колони N (макс %d): ", MAX_N);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_N);

    // Въвеждане на елементите
    printf("\nВъведете елементите (цели числа между -10 и 10):\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            int val;
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &val);
                if (val < -10 || val > 10) {
                    printf("  -> Грешка! Числото трябва да е в интервала [-10; 10]. Опитайте пак.\n");
                }
            } while (val < -10 || val > 10);
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

void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[], int *size) {
    *size = 0; // Нулиране на брояча
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Проверка: квадратът на числото да е > 50
            if ((matrix[i][j] * matrix[i][j]) > 50) {
                arr[*size] = matrix[i][j];
                (*size)++;
            }
        }
    }
}

// Сортиране по метода на мехурчето (Bubble Sort)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size, const char* message) {
    printf("\n%s\n[ ", message);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}