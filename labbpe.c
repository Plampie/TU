//1.	Напишете програма на C, която при въвеждането на пет цели числа да ги подрежда в нарастващ ред, след което да ги отпечатва 
//Забележка: за решаването на тази задача не трябва да се използват масиви. Използвайте подредбата на указателите на променливите за отпечатване на числата ( printf( …,*ptr1,*ptr2, … *ptr5)
#include <stdio.h>

void swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b, c, d, e;
    printf("Enter 5 num: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int *ptr1 = &a, *ptr2 = &b, *ptr3 = &c, *ptr4 = &d, *ptr5 = &e;
    
   // bubble sort
    int *ptrs[] = {ptr1, ptr2, ptr3, ptr4, ptr5};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (*ptrs[j] > *ptrs[j + 1]) {
                swap(&ptrs[j], &ptrs[j + 1]);
            }
        }
    }

    printf("Sorted num: %d %d %d %d %d\n", *ptrs[0], *ptrs[1], *ptrs[2], *ptrs[3], *ptrs[4]);

    return 0;
}


// 2.	Напишете програма на C, която най – напред въвеждат на пет цели числа от потребителя, 
//след което се въвежда ново произволно число. Напишете функция която връща указател към един от стринговете: 
//“This Value Already Exist” или “This Value is unique for now”. Двата стринга са глобални променливи и 
//не подлежат на промяна на стойността
#include <stdio.h>

#define SIZE 5

const char *EXIST_MSG = "This Value Already Exist";
const char *UNIQUE_MSG = "This Value is unique for now";

const char* check_value(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return EXIST_MSG;
        }
    }
    return UNIQUE_MSG;
}

int main() {
    int numbers[SIZE];
    int new_value;
    
    printf("Enter %d numbers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }
    
    printf("Enter a new num to check:\n");
    scanf("%d", &new_value);

    printf("%s\n", check_value(numbers, SIZE, new_value));
    
    return 0;
}


// 3.	Напишете програма на C, която да приканва потребителят да въведе  пет уникални цели числа в нарастваща последователност. 
// Програмата да проверява след като се въведе всяко число да проверява дали въведената стойност  отговаря на условията 
//и при неизпълнение да приканва потребителят да въведе друга правилна стойност за това число. 
//След успешно въведени пет числа, програмата да приканва потребителя да въведе ново число. 
// След като „намери“ позицията в така получената нарастваща редица от числа да отпечата редицата на екрана
// Забележка: за решаването на тази задача трябва да се използват само указатели за разместването на числата
#include <stdio.h>

#define SIZE 5

void insert_sorted(int *arr, int *size, int new_val) {
    int i = *size - 1; // start from the last element
    while (i >= 0 && arr[i] > new_val) {
        arr[i + 1] = arr[i]; // move right
        i--; // new element
    }
    arr[i + 1] = new_val; // insert new value
    (*size)++; // increase the size or arr
}

int main() {
    int arr[SIZE + 1]; // 5+1
    int count = 0, input; // track the num of el in arr
    
    printf("Enter %d number:\n", SIZE);
    
    while (count < SIZE) {
        scanf("%d", &input);
        if (count > 0 && input <= arr[count - 1]) {
            printf("Number must be higher: \n");
            continue;
        }
        arr[count++] = input; // if valid -> add to arr
    }
    
    printf("Current array: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("New num: ");
    scanf("%d", &input);
    
    insert_sorted(arr, &count, input);
    
    printf("Simple row: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}


// 4.	Напишете програма в която потребителят въвежда четири числа. 
// Програмата да използва функции в посочената последователност, които:
// ●	Отпечатва последователно въведените числа
// ●	да разменя стойностите на 1-то число с 4-то и 2-то с 3 то.
// ●	Накрая програмата да отпечата последователно числата 
// Забележка: за решаването на тази задача не трябва да се използват масиви
#include <stdio.h>

void print_numbers(int a, int b, int c, int d) {
    printf("Numbers are: %d %d %d %d\n", a, b, c, d);
}

void swap_values(int *a, int *b, int *c, int *d) {
    int temp;
    temp = *a; *a = *d; *d = temp; // 1 to 4
    temp = *b; *b = *c; *c = temp;  // 2 to 3 
}

int main() {
    int a, b, c, d;
    
    printf("First num: ");
    scanf("%d", &a);
    printf("Second num: ");
    scanf("%d", &b);
    printf("Third num: ");
    scanf("%d", &c);
    printf("Forth num: ");
    scanf("%d", &d);
    
    print_numbers(a, b, c, d); 
    swap_values(&a, &b, &c, &d); 
    
    printf("After swap: %d %d %d %d\n", a, b, c, d);
    
    return 0;
}


// 5.	Напишете програма която демонстрира разликата при използване на функции с предаване на стойност (By Value) 
// и предаване на указател (By Reference ). Функцията да приема два параметъра. 
// Първо да отпечатва стойността на сбора на двете променливи преди да бъде извикана функцията, 
// в тялото на функцията да умножи първата с 5, втората да намали с 10, след което да отпечатва отново стойността 
// на сбора в тялото на функцията. Най – накрая в извикващата функция да отпечата сбора на двете числа
#include <stdio.h>

void ByValue(int a, int b) {
    printf("[By Value] Sum before modification: %d\n", a + b); // 1
    a *= 5; // a * 5 - 1 * 5 = 5
    b -= 10; // b - 10 -  0 - 10 = -10
    printf("[By Value] Sum inside function: %d\n", a + b); // -5
}

void ByReference(int *a, int *b) {
    printf("[By Reference] Sum before modification: %d\n", *a + *b);
    *a *= 5; // a (x) -  x * 5  -  1 * 5 = 5
    *b -= 10; // b (y) -  y - 10 -  0 - 10 = -10
    printf("[By Reference] Sum inside function: %d\n", *a + *b);
}

int main() {
    int x = 1, y = 0;
    printf("Initial sum: %d\n", x + y); // 1 + 0 = 1
    
    ByValue(x, y);
    printf("[By Value] Sum after function call: %d\n", x + y); // 1 + 0 = 1
    
    printf("\n"); 

    ByReference(&x, &y);
    printf("[By Reference] Sum after function call: %d\n", x + y); // 5 + (-10) = -5
    
    return 0;
}


// 6.	Да се напише програма в която дефинирате три функции с една и съща сигнатура. След което напишете меню 
// в което потребителя избира на коя от трите функции да бъде отпечатан резултата. 
// Например функция 1 int Add ( int a, int b) , функция 2 int Subtracts ( int a, int b), 
// int Power ( int a, int b). Отпечатването да става в края на безкрайния цикъл в само един оператор и 
// без да се присвоява резултата от функцията на променлива.
#include <stdio.h>
#include <math.h>

int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b) {
    return a - b;
}

int Power(int a, int b) {
    return (int)pow(a, b);
}

int main() {
    int choice, a, b;
    
    // arr of function pointers
    int (*operations[])(int, int) = {Add, Subtract, Power};
    
    while (1) {
        printf("\nChoose:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Power^2\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 4) {
            printf("Exit...\n");
            break;
        }
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice.\n");
            continue;
        }
        
        printf("Enter 2 nums: ");
        if (scanf("%d %d", &a, &b) != 2) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Result: %d\n", operations[choice - 1](a, b));
    }
    
    return 0;
}


// 8.	Напишете програма на C за събиране на две матрици с помощта на указатели. 
// Програмата да използва функции: за въвеждането на двете матрици от потребителя и намиране на 
// сумата от двете матрици с помощта на указатели.
#include <stdio.h>

#define ROWS 3
#define COLS 3

void inputMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", (matrix + i * cols + j));
        }
    }
}

void addMatrices(int *matrix1, int *matrix2, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }
}

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    
    printf("Enter elements of first matrix (%dx%d):\n", ROWS, COLS);
    inputMatrix((int *)matrix1, ROWS, COLS);
    
    printf("Enter elements of second matrix (%dx%d):\n", ROWS, COLS);
    inputMatrix((int *)matrix2, ROWS, COLS);
    
    addMatrices((int *)matrix1, (int *)matrix2, (int *)result, ROWS, COLS);
    
    printf("Sum of the matrices:\n");
    printMatrix((int *)result, ROWS, COLS);
    
    return 0;
}


// 10.	Напишете програма на C за изчисляване на дължината на низ с помощта на указател. 
// За въвеждане на стойността на низа да се използва функцията fgets
#include <stdio.h>

int string_length(char *ptr) {
    int length = 0;
    while (*ptr != '\0' && *ptr != '\n') { // check start and end of str
        length++;
        ptr++;
    }
    return length;
}

int main() {
    char str[100]; 
    
    printf("String: ");
    fgets(str, sizeof(str), stdin); // read str
    
    int length = string_length(str); // calculate len
    printf("Length is: %d\n", length);
    
    return 0;
}
