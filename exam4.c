#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hospital discharge information
typedef struct {
    int id; // Unique discharge ID
    char date[11]; // Date in format DD.MM.YYYY
    char patient_name[31]; // Patient's name (max 30 characters)
    char diagnosis[51]; // Diagnosis (max 50 characters)
} Treatment;

// Function to count the occurrences of a patient's hospitalizations with a specific diagnosis
int count_treatment(Treatment *history, int count, const char *name, const char *diagnosis) {
    int occurrences = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(history[i].patient_name, name) == 0 && strcmp(history[i].diagnosis, diagnosis) == 0) {
            occurrences++;
        }
    }
    return occurrences;
}

// Function to add a new treatment record
Treatment* add_new_treatment(Treatment *history, int *count) {
    Treatment *new_history = realloc(history, (*count + 1) * sizeof(Treatment));
    if (!new_history) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter discharge ID: ");
    scanf("%d", &new_history[*count].id);
    printf("Enter date (DD.MM.YYYY): ");
    scanf("%s", new_history[*count].date);
    printf("Enter patient name: ");
    scanf(" %30[^"]", new_history[*count].patient_name");
    printf("Enter diagnosis: ");
    scanf(" %50[^"]", new_history[*count].diagnosis");
    
    (*count)++;
    return new_history;
}

// Function to write patient records with a specific diagnosis to a text file
int write_text_file(Treatment *history, int count, const char *diagnosis) {
    FILE *file = fopen("illness.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return 0;
    }
    
    int written = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(history[i].diagnosis, diagnosis) == 0) {
            fprintf(file, "Hospital stay of %s for treatment of %s: %s\n", history[i].patient_name, history[i].diagnosis, history[i].date);
            written++;
        }
    }
    fclose(file);
    return written;
}

int main() {
    FILE *file = fopen("history.bin", "rb");
    if (!file) {
        printf("Error opening binary file!\n");
        return 1;
    }
    
    int count;
    fread(&count, sizeof(int), 1, file);
    
    Treatment *history = malloc(count * sizeof(Treatment));
    if (!history) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }
    
    fread(history, sizeof(Treatment), count, file);
    fclose(file);
    
    printf("Loaded %d patient records.\n", count);
    
    // Example usage of functions
    printf("Occurrences: %d\n", count_treatment(history, count, "John Doe", "Flu"));
    history = add_new_treatment(history, &count);
    if (history) printf("New patient added successfully.\n");
    printf("Records written: %d\n", write_text_file(history, count, "Flu"));
    
    free(history);
    return 0;
}
