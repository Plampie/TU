#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define DATE_LEN 8

typedef struct {
    char name[NAME_LEN + 1];
    char expiry[DATE_LEN + 1];
    long long code;
    double price;
    int quantity;
} Medicine;

// Task 1: Load data from file
Medicine* load_medicines(const char* filename, int* count) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening the file");
        *count = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    *count = size / sizeof(Medicine);

    Medicine* medicines = (Medicine*)malloc(*count * sizeof(Medicine));
    if (!medicines) {
        perror("Insufficient memory");
        fclose(file);
        return NULL;
    }

    fread(medicines, sizeof(Medicine), *count, file);
    fclose(file);
    return medicines;
}

// Task 2: Filter medicines by expiry date
Medicine* expired_before(Medicine* meds, int count, const char* targetDate, int* resultCount) {
    *resultCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].expiry, targetDate) < 0) {
            (*resultCount)++;
        }
    }

    if (*resultCount == 0) return NULL;

    Medicine* result = malloc(*resultCount * sizeof(Medicine));
    if (!result) return NULL;

    int index = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].expiry, targetDate) < 0) {
            result[index++] = meds[i];
        }
    }

    return result;
}

// Task 3: Save offer to "offer.txt" with price range
int save_offer(Medicine* meds, int count, double minPrice, double maxPrice) {
    FILE* file = fopen("offer.txt", "w");
    if (!file) {
        perror("Error writing to file");
        return 0;
    }

    int saved = 0;
    for (int i = 0; i < count; i++) {
        if (meds[i].price >= minPrice && meds[i].price <= maxPrice) {
            fprintf(file, "%s\n%s\n%013lld\n%.2f leva\n\n",
                meds[i].name, meds[i].expiry, meds[i].code, meds[i].price);
            saved++;
        }
    }

    fclose(file);
    return saved;
}

// Task 4: Delete medicine by name and expiry date
void delete_medicine(Medicine** meds, int* count, const char* name, const char* date) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp((*meds)[i].name, name) == 0 && strcmp((*meds)[i].expiry, date) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                (*meds)[j] = (*meds)[j + 1];
            }
            (*count)--;
            *meds = realloc(*meds, *count * sizeof(Medicine));
            printf("The medicine has been deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("The medicine was not found.\n");
    }
}

int main() {
    Medicine* meds = NULL;
    int count = 0;

    // Task 1
    meds = load_medicines("medicines.bin", &count);
    if (!meds) return 1;

    // Task 2
    const char* targetDate = "05.2025";  
    int expiredCount;
    Medicine* expired = expired_before(meds, count, targetDate, &expiredCount);
    if (expired) {
        printf("Found %d medicines expiring before %s:\n", expiredCount, targetDate);
        for (int i = 0; i < expiredCount; i++) {
            printf("%s | %s\n", expired[i].name, expired[i].expiry);
        }
        free(expired);
    } else {
        printf("No medicines found expiring before %s.\n", targetDate);
    }

    // Task 3
    double minPrice = 10.0, maxPrice = 50.0; 
    int savedCount = save_offer(meds, count, minPrice, maxPrice);
    printf("Saved %d medicines to offer.txt.\n", savedCount);

    // Task 4
    const char* deleteName = "Aspirin";  
    const char* deleteDate = "05.2025"; 
    delete_medicine(&meds, &count, deleteName, deleteDate);

    free(meds);
    return 0;
}