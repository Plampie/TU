#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Medicine structure
typedef struct {
    char name[31];      // Medicine name (max 30 chars)
    char expiry_date[8]; // Expiry date (MM.YYYY)
    long long code;     // Unique 13-digit code
    float price;        // Price per unit
    int quantity;       // Available quantity
} Medicine;

// Function to load medicines from file into dynamic array
int loadMedicines(const char *filename, Medicine **medicines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s!\n", filename);
        return 0;
    }
    int count = 0;
    Medicine temp;
    while (fscanf(file, "%30[^;];%7[^;];%lld;%f;%d\n", temp.name, temp.expiry_date, &temp.code, &temp.price, &temp.quantity) == 5) {
        count++;
    }
    rewind(file);
    *medicines = (Medicine *)malloc(count * sizeof(Medicine));
    if (!(*medicines)) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 0;
    }
    for (int i = 0; i < count; i++) {
        fscanf(file, "%30[^;];%7[^;];%lld;%f;%d\n", (*medicines)[i].name, (*medicines)[i].expiry_date, &(*medicines)[i].code, &(*medicines)[i].price, &(*medicines)[i].quantity);
    }
    fclose(file);
    return count;
}

// Function to reduce price by 20% for expired medicines
void discountExpiredMedicines(Medicine *medicines, int n, const char *date) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(medicines[i].expiry_date, date) < 0) {
            float old_price = medicines[i].price;
            medicines[i].price *= 0.8;
            printf("%s - %s - %.2f leva -> %.2f leva\n", medicines[i].name, medicines[i].expiry_date, old_price, medicines[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No medicines found for discount.\n");
    }
}

// Function to write medicines with quantity greater than threshold to binary file
void saveToBinaryFile(Medicine *medicines, int n, int min_quantity, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening binary file %s!\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (medicines[i].quantity > min_quantity) {
            int name_length = strlen(medicines[i].name);
            fwrite(&name_length, sizeof(int), 1, file);
            fwrite(medicines[i].name, sizeof(char), name_length, file);
            fwrite(medicines[i].expiry_date, sizeof(char), 8, file);
            fwrite(&medicines[i].code, sizeof(long long), 1, file);
            fwrite(&medicines[i].price, sizeof(float), 1, file);
            fwrite(&medicines[i].quantity, sizeof(int), 1, file);
        }
    }
    fclose(file);
}

// Function to delete medicine by code
void deleteMedicine(Medicine **medicines, int *n, long long code) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if ((*medicines)[i].code == code) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Medicine with code %lld not found.\n", code);
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        (*medicines)[i] = (*medicines)[i + 1];
    }
    *n -= 1;
    *medicines = (Medicine *)realloc(*medicines, (*n) * sizeof(Medicine));
    printf("Medicine with code %lld deleted successfully.\n", code);
}

int main() {
    Medicine *medicines;
    int count = loadMedicines("medicines.txt", &medicines);
    if (count == 0) return 1;

    char expiry_check[8];
    printf("Enter expiry date (MM.YYYY) to check for discounts: ");
    scanf("%7s", expiry_check);
    discountExpiredMedicines(medicines, count, expiry_check);

    int min_quantity;
    printf("Enter minimum quantity to save to binary file: ");
    scanf("%d", &min_quantity);
    saveToBinaryFile(medicines, count, min_quantity, "offer.bin");

    long long delete_code;
    printf("Enter medicine code to delete: ");
    scanf("%lld", &delete_code);
    deleteMedicine(&medicines, &count, delete_code);

    free(medicines);
    return 0;
}