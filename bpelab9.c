// 1.В двoичен файл имате цяло число N и след него N цели числа.
// а)Да се напише програма, която създава файла.
// б)Да се напише програма, която изкарва на екрана броя на четните и 
// броя на нечетните цифри от така дадените N числа.
// в)Да се напише програма, която прочита така подадения масив от N елемента и 
// изкарва в текстови файл сортирания по възходящ ред масив.

#include <stdio.h>
#include <stdlib.h>

#define BINARY_FILENAME "numbers.bin"
#define TEXT_FILENAME "sorted_numbers.txt"

// create binary file 
void create_binary_file() {
    FILE *file;
    int N, num;

    file = fopen(BINARY_FILENAME, "wb");
    if (!file) {
        perror("Unable to open binary file for writing");
        return;
    }

    printf("Enter the number of integers (N): ");
    scanf("%d", &N);
    
    // write N first
    fwrite(&N, sizeof(int), 1, file);

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        printf("  Number %d: ", i + 1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);  
    }

    fclose(file);
    printf("Binary file '%s' created successfully.\n", BINARY_FILENAME);
}

// count even digits 
int count_even_digits(int number) {
    int count = 0;
    number = abs(number); 
    if (number == 0) return 1; // Zero considered even digit

    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 == 0) count++;
        number /= 10;
    }
    return count;
}

// count odd digits 
int count_odd_digits(int number) {
    int count = 0;
    number = abs(number);
    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 != 0) count++;
        number /= 10;
    }
    return count;
}

// count even and odd digits from bin file
void count_even_odd_digits() {
    FILE *file;
    int N, num, even_count = 0, odd_count = 0;

    file = fopen(BINARY_FILENAME, "rb");
    if (!file) {
        perror("Unable to open binary file for reading");
        return;
    }

    fread(&N, sizeof(int), 1, file);

    for (int i = 0; i < N; i++) {
        fread(&num, sizeof(int), 1, file);  //reads the next number into num
        even_count += count_even_digits(num);
        odd_count += count_odd_digits(num);
    }

    fclose(file);
    printf("Total even digits: %d\n", even_count);
    printf("Total odd digits: %d\n", odd_count);
}

// compare func for sorting 
int compare_ints(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// sort and write to txt file
void sort_and_save_to_text() {
    FILE *binary_file, *text_file;
    int N, *arr;

    binary_file = fopen(BINARY_FILENAME, "rb");
    if (!binary_file) {
        perror("Unable to open binary file for reading");
        return;
    }

    fread(&N, sizeof(int), 1, binary_file);
    arr = malloc(N * sizeof(int));
    if (!arr) {
        perror("Memory allocation failed");
        fclose(binary_file);
        return;
    }

    fread(arr, sizeof(int), N, binary_file);
    fclose(binary_file);

    qsort(arr, N, sizeof(int), compare_ints);

    text_file = fopen(TEXT_FILENAME, "w");
    if (!text_file) {
        perror("Unable to open text file for writing");
        free(arr);
        return;
    }

    for (int i = 0; i < N; i++) {
        fprintf(text_file, "%d\n", arr[i]);
    }

    fclose(text_file);
    free(arr);

    printf("Sorted numbers saved to '%s'.\n", TEXT_FILENAME);
}


int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create binary file\n");
        printf("2. Count even and odd digits\n");
        printf("3. Sort and save to text file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_binary_file();
                break;
            case 2:
                count_even_odd_digits();
                break;
            case 3:
                sort_and_save_to_text();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


// 2. В двоичен файл имате цели числа (не е указано колко на брой).
// а)Да се напише програма, която създава файла.
// б)Да се напише програма, която изкарва на екрана броя на четните и броя на нечетните цифри
// от така дадените N числа.
// в)Да се напише програма, която прочита така подадения масив от N елемента и изкарва в
// текстови файл сортирания по възходящ ред масив.

#include <stdio.h>
#include <stdlib.h>

#define BINARY_FILENAME "numbers.bin"
#define TEXT_FILENAME "sorted_numbers.txt"

// create binary file - user-entered num
void create_binary_file() {
    FILE *file;
    int num, count;

    file = fopen(BINARY_FILENAME, "wb");
    if (!file) {
        perror("Unable to open binary file for writing");
        return;
    }

    printf("How many numbers do you want to enter? ");
    scanf("%d", &count);

    printf("Enter %d integers:\n", count);
    for (int i = 0; i < count; i++) {
        printf("  Number %d: ", i + 1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);
    printf("Binary file '%s' created successfully.\n", BINARY_FILENAME);
}

// count even digits in a number
int count_even_digits(int number) {
    int count = 0;
    number = abs(number);
    if (number == 0) return 1;

    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 == 0) count++;
        number /= 10;
    }
    return count;
}

// count odd digits in a number
int count_odd_digits(int number) {
    int count = 0;
    number = abs(number);

    while (number > 0) {
        int digit = number % 10;
        if (digit % 2 != 0) count++;
        number /= 10;
    }
    return count;
}

void count_even_odd_digits() {
    FILE *file;
    int num, even_count = 0, odd_count = 0;

    file = fopen(BINARY_FILENAME, "rb");
    if (!file) {
        perror("Unable to open binary file for reading");
        return;
    }

    while (fread(&num, sizeof(int), 1, file) == 1) {
        even_count += count_even_digits(num);
        odd_count += count_odd_digits(num);
    }

    fclose(file);

    printf("Total even digits: %d\n", even_count);
    printf("Total odd digits: %d\n", odd_count);
}

// compare func for sort
int compare_ints(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

// red numbers from bin file, sort, write to txt file
void sort_and_save_to_text() {
    FILE *binary_file, *text_file;
    int *arr = NULL; // dynamic array to hold nums
    int num, count = 0;

    binary_file = fopen(BINARY_FILENAME, "rb");
    if (!binary_file) {
        perror("Unable to open binary file for reading");
        return;
    }

    // read numbers into dynamic array
    while (fread(&num, sizeof(int), 1, binary_file) == 1) { // until EOF
        int *temp = realloc(arr, (count + 1) * sizeof(int));
        if (!temp) {
            perror("Memory allocation failed");
            free(arr);
            fclose(binary_file);
            return;
        }
        arr = temp; // new number -> end of arr
        arr[count++] = num; 
    }

    fclose(binary_file);

    if (count == 0) {
        printf("No data found in the binary file.\n");
        return;
    }

    qsort(arr, count, sizeof(int), compare_ints);

    text_file = fopen(TEXT_FILENAME, "w");
    if (!text_file) {
        perror("Unable to open text file for writing");
        free(arr);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(text_file, "%d\n", arr[i]);
    }

    fclose(text_file);
    free(arr);

    printf("Sorted numbers saved to '%s'.\n", TEXT_FILENAME);
}

int main() {
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Create binary file\n");
        printf("2. Count even and odd digits\n");
        printf("3. Sort and save to text file\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_binary_file();
                break;
            case 2:
                count_even_odd_digits();
                break;
            case 3:
                sort_and_save_to_text();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}


// 3. Трябва да опишете база данни която работи с автокъща. Данните ви трябва да имат следния
// вид - марка на автомобил, модел на автомобила - 5 знака, обем на двигателя, цена, има ли
// регистрация или не (символ Y/N). Създайте програма, която записва така дадената структура на
// базата данни във двоичен и паралелно в текстови файл. Напишете възможност за добавяне на
// нов запис. Създайте програма, която прочита двата създадени файла и изкарва един след друг
// данните от бинарния и текстовия файл, за да направите сравнение за правилната работа на
// програмата ви.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_FILE "cars.bin"
#define TEXT_FILE "cars.txt"

typedef struct {
    char brand[50];
    char model[6];  // 5 chars + null 
    float engine_volume;
    float price;
    char registered; // Y or N
} Car;

// add a new car 
void add_car() {
    FILE *bin_fp = fopen(BINARY_FILE, "ab");
    FILE *txt_fp = fopen(TEXT_FILE, "a");
    if (!bin_fp || !txt_fp) {
        perror("File open error");
        return;
    }

    Car car;
    printf("Enter car brand: ");
    scanf("%s", car.brand);

    printf("Enter car model (5 characters): ");
    scanf("%5s", car.model);

    printf("Enter engine volume: ");
    scanf("%f", &car.engine_volume);

    printf("Enter price: ");
    scanf("%f", &car.price);

    do {
        printf("Is the car registered? (Y/N): ");
        scanf(" %c", &car.registered);
    } while (car.registered != 'Y' && car.registered != 'N');

    // write to binary file
    fwrite(&car, sizeof(Car), 1, bin_fp);

    // write to text file
    fprintf(txt_fp, "%s %s %.2f %.2f %c\n",
            car.brand, car.model, car.engine_volume, car.price, car.registered);

    printf("Car added successfully!\n");

    fclose(bin_fp);
    fclose(txt_fp);
}

//  display records from both bin and txt files
void display_records() {
    FILE *bin_fp = fopen(BINARY_FILE, "rb");
    FILE *txt_fp = fopen(TEXT_FILE, "r");
    Car car;

    if (!bin_fp || !txt_fp) {
        perror("File open error");
        return;
    }

    printf("\n--- Binary File Records ---\n");
    while (fread(&car, sizeof(Car), 1, bin_fp) == 1) {
        printf("Brand: %s | Model: %s | Engine: %.2f | Price: %.2f | Registered: %c\n",
               car.brand, car.model, car.engine_volume, car.price, car.registered);
    }

    printf("\n--- Text File Records ---\n");
    char brand[50], model[6], reg;
    float engine, price;
    while (fscanf(txt_fp, "%s %s %f %f %c", brand, model, &engine, &price, &reg) == 5) {
        printf("Brand: %s | Model: %s | Engine: %.2f | Price: %.2f | Registered: %c\n",
               brand, model, engine, price, reg);
    }

    fclose(bin_fp);
    fclose(txt_fp);
}

int main() {
    int choice;
    do {
        printf("\n=== Car Dealership Database ===\n");
        printf("1. Add new car\n");
        printf("2. Display records from binary and text files\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_car();
                break;
            case 2:
                display_records();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}