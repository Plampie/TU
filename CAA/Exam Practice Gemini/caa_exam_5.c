#include <stdio.h>
#include <locale.h> // За кирилица

#define MAX_N 100 // Максимален размер на матрицата

// Прототипи на функциите
void printTaskInfo();
void inputMatrix(int matrix[MAX_N][MAX_N], int *n);
void printMatrix(int matrix[MAX_N][MAX_N], int n);
void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[]);
void sortArray(int arr[], int n);
void printArray(int arr[], int n, const char* message);

int main() {
    // Настройка за кирилица
    setlocale(LC_ALL, ""); 

    int A[MAX_N][MAX_N]; // Двумерен масив
    int C[MAX_N];        // Едномерен масив за резултатите (максимумите по редове)
    int N;               // Размерност

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

    // 5. Обработка а): Образуване на масив C (Макс. елементи от всеки ред)
    createArrayC(A, N, C);

    // Отпечатване на резултата от а)
    printf("\n--- Резултати ---\n");
    printArray(C, N, "а) Масив C (Максимални елементи от редовете):");

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
    printf("Обработка на масив A[N,N] с числа в интервал [-500; 1000].\n");
    printf("а) Образуване на масив C[N] с максималните елементи\n");
    printf("   от всеки ред на А.\n");
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
    printf("\nВъведете елементите (цели числа между -500 и 1000):\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            int val;
            do {
                printf("A[%d][%d] = ", i, j);
                scanf("%d", &val);
                if (val < -500 || val > 1000) {
                    printf("  -> Грешка! Числото трябва да е в интервала [-500; 1000].\n");
                }
            } while (val < -500 || val > 1000);
            matrix[i][j] = val;
        }
    }
}

void printMatrix(int matrix[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Логика за подточка а) - Намиране на MAX във всеки ред
void createArrayC(int matrix[MAX_N][MAX_N], int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        int maxInRow = matrix[i][0]; // Приемаме, че първият е най-голям
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }
        arr[i] = maxInRow; // Записваме максимума в масив C
    }
}

// Логика за подточка б) - Сортиране (Bubble Sort)
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n, const char* message) {
    printf("%s\n[ ", message);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}