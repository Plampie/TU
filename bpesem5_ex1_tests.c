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

void write_bin(const char *filename, PARTY_DATA data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open binary file for writing.\n");
        exit(1);
    }

    fwrite(&data, sizeof(PARTY_DATA), 1, file);
    fclose(file);
}

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

// compare result
int compare_data(PARTY_DATA a, PARTY_DATA b) {
    return a.guests == b.guests &&
           a.chairs == b.chairs &&
           a.tables == b.tables &&
           a.cup_sets == b.cup_sets &&
           a.dish_sets == b.dish_sets &&
           fabs(a.total_spent - b.total_spent) < 0.01;
}

int main() {
    int guests = 0;
    scanf("%d", &guests);

    int chairs = 0, tables = 0, cup_sets = 0, dish_sets = 0;
    char input[20];

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

    double total_spent = (chairs * CHAIR_PRICE) +
                         (tables * TABLE_PRICE) +
                         (cup_sets * CUP_SET_PRICE) +
                         (dish_sets * DISH_SET_PRICE);

    PARTY_DATA data = {guests, chairs, tables, cup_sets, dish_sets, total_spent};

    // write files
    write_txt("party_data.txt", data);
    write_bin("party_data.bin", data);

    // read files
    PARTY_DATA txt_data = read_txt("party_data.txt");
    PARTY_DATA bin_data = read_bin("party_data.bin");

    if (compare_data(txt_data, bin_data)) {
        printf("MATCH\n");
    } else {
        printf("MISMATCH\n");
    }

    return 0;
}