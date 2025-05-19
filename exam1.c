#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for IceCream
typedef struct {
    char code[3];  // Unique code (e.g., A2)
    char name[21]; // Name of the product (max 20 chars)
    int weight;    // Weight in kg
    float price;   // Price per kg
} IceCream;

// Function to calculate total price of ice creams starting with a given letter
float calculateTotalPrice(IceCream *arr, int n, char letter) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].code[0] == letter) {
            total += arr[i].weight * arr[i].price;
        }
    }
    return total;
}

// Function to write ice creams to file based on weight and price conditions
int writeFilteredIceCreamsToFile(IceCream *arr, int n, float max_price, int min_weight) {
    FILE *file = fopen("info.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].price < max_price && arr[i].weight > min_weight) {
            fprintf(file, "%s;%s;%d;%.2fleva\n", arr[i].code, arr[i].name, arr[i].weight, arr[i].price);
            count++;
        }
    }
    fclose(file);
    return count;
}

// Function to read ice cream details from a binary file and print if found
void readIceCreamFromBinaryFile(const char *filename, const char *search_code) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening binary file!\n");
        return;
    }
    IceCream ice;
    while (fread(&ice, sizeof(IceCream), 1, file)) {
        if (strcmp(ice.code, search_code) == 0) {
            printf("IceCream found:\nCode: %s\nName: %s\nWeight: %d kg\nPrice: %.2f leva\n",
                   ice.code, ice.name, ice.weight, ice.price);
            fclose(file);
            return;
        }
    }
    printf("No ice cream found with code %s.\n", search_code);
    fclose(file);
}

int main() {
    int n;
    printf("Enter number of ice creams (between 5 and 15): ");
    scanf("%d", &n);
    if (n < 5 || n > 15) {
        printf("Invalid number! Must be between 5 and 15.\n");
        return 1;
    }

    // Allocate memory dynamically
    IceCream *iceCreams = (IceCream *)malloc(n * sizeof(IceCream));
    if (!iceCreams) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input ice creams
    for (int i = 0; i < n; i++) {
        printf("Enter details for ice cream %d (code name weight price): ", i + 1);
        scanf("%s %s %d %f", iceCreams[i].code, iceCreams[i].name, &iceCreams[i].weight, &iceCreams[i].price);
    }

    // Calculate total price of ice creams starting with a given letter
    char letter;
    printf("Enter a letter to calculate total price: ");
    scanf(" %c", &letter);
    float total = calculateTotalPrice(iceCreams, n, letter);
    printf("Total price for ice creams starting with '%c': %.2f leva\n", letter, total);

    // Write to file based on conditions
    float max_price;
    int min_weight;
    printf("Enter max price and min weight for filtering: ");
    scanf("%f %d", &max_price, &min_weight);
    int count = writeFilteredIceCreamsToFile(iceCreams, n, max_price, min_weight);
    printf("%d records written to file info.txt.\n", count);

    // Read from binary file
    char search_code[3];
    printf("Enter code to search in binary file: ");
    scanf("%s", search_code);
    readIceCreamFromBinaryFile("icecream.bin", search_code);

    free(iceCreams);
    return 0;
}