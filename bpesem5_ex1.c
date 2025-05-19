// Plamena Vasileva Georgieva
// Faculty Number: 381224060
// Group: 95
// Exercise Group: 4

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define CHAIR_PRICE 13.99
#define TABLE_PRICE 42.00
#define CUP_SET_PRICE 5.98
#define DISH_SET_PRICE 21.02

#define PEOPLE_PER_TABLE 8
#define ITEMS_PER_SET 6

typedef struct {
    int guests;
    int chairs;
    int tables;
    int cup_sets;
    int dish_sets;
    double total_spent;
} PARTY_DATA;

typedef struct {
    int missing_chairs;
    int missing_tables;
    int missing_cup_sets;
    int missing_dish_sets;
} PARTY_MISSING;

// write data to text file
void write_txt(const char *filename, PARTY_DATA data) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open text file for writing.\n");
        exit(1);
    }

    fprintf(file, "%d %d %d %d %d %.2lf\n", data.guests, data.chairs, data.tables,
            data.cup_sets, data.dish_sets, data.total_spent);
    fclose(file);
}

// write data to binary file
void write_bin(const char *filename, PARTY_DATA data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open binary file for writing.\n");
        exit(1);
    }

    fwrite(&data, sizeof(PARTY_DATA), 1, file);
    fclose(file);
}

// read data from txt file
PARTY_DATA read_txt(const char *filename) {
    PARTY_DATA data;
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open text file for reading.\n");
        exit(1);
    }

    fscanf(file, "%d %d %d %d %d %lf", &data.guests, &data.chairs, &data.tables,
           &data.cup_sets, &data.dish_sets, &data.total_spent);
    fclose(file);
    return data;
}

// read binary file	
PARTY_DATA read_bin(const char *filename) {
    PARTY_DATA data;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open binary file for reading.\n");
        exit(1);
    }

    fread(&data, sizeof(PARTY_DATA), 1, file);
    fclose(file);
    return data;
}

// compare data from txt and bin files
int compare_data(PARTY_DATA a, PARTY_DATA b) {
    return a.guests == b.guests &&
           a.chairs == b.chairs &&
           a.tables == b.tables &&
           a.cup_sets == b.cup_sets &&
           a.dish_sets == b.dish_sets &&
           fabs(a.total_spent - b.total_spent) < 0.01; // allow for precision issues
}

// calculates how many more items are needed
PARTY_MISSING missing_items(PARTY_DATA data) {
    PARTY_MISSING missing;

    missing.missing_chairs = data.guests - data.chairs; // guests - chairs
    int required_tables = (int)ceil((double)data.guests / PEOPLE_PER_TABLE); // guests / PEOPLE_PER_TABLE
    missing.missing_tables = required_tables - data.tables; // required_tables - tables

    int required_sets = (int)ceil((double)data.guests / ITEMS_PER_SET); // guests / ITEMS_PER_SET
    missing.missing_cup_sets = required_sets - data.cup_sets; // required_sets - cup_sets
    missing.missing_dish_sets = required_sets - data.dish_sets; // required_sets - dish_sets

    if (missing.missing_chairs < 0) missing.missing_chairs = 0;
    if (missing.missing_tables < 0) missing.missing_tables = 0;
    if (missing.missing_cup_sets < 0) missing.missing_cup_sets = 0;
    if (missing.missing_dish_sets < 0) missing.missing_dish_sets = 0;

    return missing;
}

// print needed items
void print_missing_items(PARTY_MISSING missing) {
    if (missing.missing_tables > 0)
        printf("%d Table%s needed\n", missing.missing_tables, missing.missing_tables > 1 ? "s" : "");
    if (missing.missing_chairs > 0)
        printf("%d Chair%s needed\n", missing.missing_chairs, missing.missing_chairs > 1 ? "s" : "");
    if (missing.missing_cup_sets > 0)
        printf("%d Cup set%s needed\n", missing.missing_cup_sets, missing.missing_cup_sets > 1 ? "s" : "");
    if (missing.missing_dish_sets > 0)
        printf("%d Dish set%s needed\n", missing.missing_dish_sets, missing.missing_dish_sets > 1 ? "s" : "");
}

int main() {
    int guests = 0;
    scanf("%d", &guests);

    int chairs = 0, tables = 0, cup_sets = 0, dish_sets = 0;
    char input[25];

    while (1) {
        scanf("%s", input);
        
        if (strcmp(input, "PARTY!") == 0) {
            break;
        }

        if (strcmp(input, "Chair") == 0) {
            chairs++;
        } else if (strcmp(input, "Table") == 0) {
            tables++;
        } else if (strcmp(input, "Cups") == 0) {
            cup_sets++;
        } else if (strcmp(input, "Dishes") == 0) {
            dish_sets++;
        }
    }

    double total_spent = (chairs * CHAIR_PRICE) + (tables * TABLE_PRICE) + (cup_sets * CUP_SET_PRICE) + (dish_sets * DISH_SET_PRICE);

    PARTY_DATA data = {guests, chairs, tables, cup_sets, dish_sets, total_spent};

    write_txt("party_data.txt", data);
    write_bin("party_data.bin", data);

    PARTY_DATA txt_data = read_txt("party_data.txt");
    PARTY_DATA bin_data = read_bin("party_data.bin");

    if (compare_data(txt_data, bin_data)) {
        printf("MATCH\n");
    } else {
        printf("MISMATCH\n");
    }

    PARTY_MISSING missing = missing_items(data);
    print_missing_items(missing);

    return 0;
}