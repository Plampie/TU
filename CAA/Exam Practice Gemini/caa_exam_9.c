#include <stdio.h>
#include <locale.h> // За кирилица

#define MAX_N 100 // Максимален размер на матрицата

// Прототипи на функциите
void printTaskInfo();
void inputMatrix(double matrix[MAX_N][MAX_N], int *n);
void printMatrix(double matrix[MAX_N][MAX_N], int n);
void createArrayC(double matrix[MAX_N][MAX_N], int n, double arr[], int *size);
void sortArray(double arr[], int size);
void printArray(double arr[], int size, const char* message);

int main() {
    // Настройка за кирилица
    setlocale(LC_ALL, ""); 

    double A[MAX_N][MAX_N]; // Двумерен масив за реални числа
    double C[MAX_N * MAX_N]; // Едномерен масив (може да събере всички елементи)
    int N;                  // Размерност
    int sizeC = 0;          // Брой елементи в масив C

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

    // 5. Обработка а): Образуване на масив C (Сбор от индексите = четно число)
    createArrayC(A, N, C, &sizeC);

    // Отпечатване на резултата от а)
    if (sizeC > 0) {
        printf("\n--- Резултати ---\n");
        printArray(C, sizeC, "а) Масив C (Елементи с четен сбор на индексите):");

        // 6. Обработка б): Сортиране на масив C
        sortArray(C, sizeC);

        // 7. Отпечатване на резултата от б)
        printArray(C, sizeC, "б) Масив C след сортиране (възходящ ред):");
    } else {
        printf("\nНяма намерени елементи, отговарящи на условието.\n");
    }

    return 0;
}

// --- Реализация на функциите ---

void printTaskInfo() {
    printf("==================================================\n");
    printf("УСЛОВИЕ НА ЗАДАЧАТА:\n");
    printf("Обработка на масив A[N,N] с реални числа в [-1000; 1000].\n");
    printf("а) Образуване на масив C от елементите на A,\n");
    printf("   чийто сбор от индексите (i+j) е ЧЕТНО число.\n");
    printf("б) Сортиране на масив C по големина.\n");
    printf("==================================================\n");
}

void inputMatrix(double matrix[MAX_N][MAX_N], int *n) {
    // Въвеждане на размерност
    do {
        printf("Въведете размерност N (макс %d): ", MAX_N);
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_N);

    // Въвеждане на елементите
    printf("\nВъведете елементите (реални числа между -1000 и 1000):\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            double val;
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%lf", &val);
                if (val < -1000 || val > 1000) {
                    printf("  -> Грешка! Числото трябва да е в интервала [-1000; 1000].\n");
                }
            } while (val < -1000 || val > 1000);
            matrix[i][j] = val;
        }
    }
}

void printMatrix(double matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Логика за подточка а) - Проверка на индексите
void createArrayC(double matrix[MAX_N][MAX_N], int n, double arr[], int *size) {
    *size = 0; // Нулиране на брояча
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Проверка: дали сумата на индексите (i + j) е четно число
            // Използваме оператор % (модул), за да проверим делимост на 2
            if ((i + j) % 2 == 0) {
                arr[*size] = matrix[i][j];
                (*size)++;
            }
        }
    }
}

// Логика за подточка б) - Сортиране (Bubble Sort)
void sortArray(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(double arr[], int size, const char* message) {
    printf("%s\n[ ", message);
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("]\n");
}