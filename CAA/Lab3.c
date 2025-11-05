#include <stdio.h>
#include <stdlib.h>

// Задача 1
static void print_binary(int x) {
    if (x >= 2) {
        print_binary(x / 2);
    }
    printf("%d", x % 2);
}

void convert_to_binary(void) {
    int n;

    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid \n");
        return;
    }
    if (n < 0) {
        printf("Natural numbers cannot be negative.\n");
        return;
    }
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    printf("Binary: ");
    print_binary(n);
    printf("\n");
}

// Задача 2
double power(double x, int n) {
    if (n > 0) {
        return x * power(x, n - 1);
    } else if (n == 0) {
        return 1.0;
    } else { // n < 0
        return 1.0 / power(x, -n);
    }
}

void calculate_power(void) {
    double x;
    int n;

    printf("Enter x and n: ");
    if (scanf("%lf %d", &x, &n) != 2) {
        printf("Invalid \n");
        return;
    }

    if (x == 0 && n < 0) {
        printf("Error \n");
        return;
    }

    double result = power(x, n);
    printf("Result: %.10g\n", result);
}

// Задача 3
static void input_array(int *arr, int size) {
    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            exit(1); 
        }
    }
}

static int sum_array(const int *arr, int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sum_array(arr, size - 1);
}

static void output_result(int result) {
    printf("Sum = %d\n", result);
}

void sum_array_task(void) {
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size < 0) {
        printf("Invalid input.\n");
        return;
    }

    if (size == 0) {                // handle empty array safely
        output_result(0);
        return;
    }

    int *arr = malloc((size_t)size * sizeof *arr);
    if (!arr) {
        printf("Memory allocation failed.\n");
        return;
    }

    input_array(arr, size);
    int result = sum_array(arr, size);
    output_result(result);

    free(arr);
}

// Задача 4
int contains_digit(int n, int d) { // returns 1 if digit is found, 0 otherwise 
    if (n == 0) {
        return 0;
    }
    if (n % 10 == d) {
        return 1;
    }
    return contains_digit(n / 10, d);
}

void digit_check_task(void) {
    int n, d;

    printf("Enter a number: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter a digit (0-9): ");
    if (scanf("%d", &d) != 1 || d < 0 || d > 9) {
        printf("Invalid digit.\n");
        return;
    }

    if (n == 0) {   // special case - number is 0
        if (d == 0)
            printf("Digit %d is present.\n", d);
        else
            printf("Digit %d is NOT present.\n", d);
        return;
    }

    if (contains_digit(n, d)) {
        printf("Digit %d is present in %d.\n", d, n);
    } else {
        printf("Digit %d is NOT present in %d.\n", d, n);
    }
}


int main(void) {
    convert_to_binary();
    calculate_power();
    sum_array_task();
    digit_check_task();
    return 0;
}

