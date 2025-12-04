#include <stdio.h>
#include <locale.h> // За кирилица

#define MAX_N 100 // Максимален размер на матрицата

// Прототипи на функциите
void printTaskInfo();
void inputMatrix(double matrix[MAX_N][MAX_N], int *n);
void printMatrix(double matrix[MAX_N][MAX_N], int n);
void calculateRowSums(double matrix[MAX_N][MAX_N], int n, double arr[]);
void sortArray(double arr[], int n);
void printArray(double arr[], int n, const char* message);

int main() {
    // Настройка за кирилица
    setlocale(LC_ALL, ""); 

    double A[MAX_N][MAX_N]; // Двумерен масив за реални числа
    double C[MAX_N];        // Едномерен масив за сумите от редовете
    int N;                  // Размерност

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

    // 5. Обработка а): Образуване на масив C (Сума от всеки ред)
    calculateRowSums(A, N, C);

    // Отпечатване на резултата от а)
    printf("\n--- Резултати ---\n");
    printArray(C, N, "а) Масив C (Суми на елементите по редове):");

    // 6. Обработка б): Сортиране на масив C
    sortArray(C, N);

    // 7. Отпечатване на резултата от б)
    printArray(C, N, "б) Масив C след сортиране (възходящ ред):");

    return 0;
}

// --- Реализация на функциите ---

void printTaskInfo() {
    printf("==================================================\n");
    printf("УСЛОВИЕ НА ЗАДАЧАТА:\n");
    printf("Обработка на масив A[N,N] с реални числа в [-1000; 1000].\n");
    printf("а) Образуване на масив C[N], съдържащ сумата на\n");
    printf("   елементите от всеки ред на А.\n");
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
            printf("%8.2lf ", matrix[i][j]); // Форматиране до 2 знак
        }
        printf("\n");
    }
}

// Логика за подточка а) - Сумиране по редове
void calculateRowSums(double matrix[MAX_N][MAX_N], int n, double arr[]) {
    for (int i = 0; i < n; i++) {
        double currentSum = 0;
        // Вътрешният цикъл върти колоните (j) за текущия ред (i)
        for (int j = 0; j < n; j++) {
            currentSum += matrix[i][j];
        }
        arr[i] = currentSum; // Записваме сумата в масив C
    }
}

// Логика за подточка б) - Сортиране (Bubble Sort)
void sortArray(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(double arr[], int n, const char* message) {
    printf("%s\n[ ", message);
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("]\n");
}