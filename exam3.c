#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Course structure
typedef struct {
    char name[51];      // Course name (max 50 chars)
    char start_date[11]; // Start date (YYYY.MM.DD)
    int total_lectures; // Total number of lectures
    float price;        // Course price
} Course;

// Function to load courses from binary file
int loadCourses(const char *filename, Course **courses) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s!\n", filename);
        return 0;
    }
    int count;
    fread(&count, sizeof(int), 1, file);
    *courses = (Course *)malloc(count * sizeof(Course));
    if (!(*courses)) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 0;
    }
    fread(*courses, sizeof(Course), count, file);
    fclose(file);
    return count;
}

// Function to apply a 10% discount to a specific course
void applyDiscount(Course *courses, int n, int index) {
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return;
    }
    courses[index].price *= 0.9;
    printf("%.2f leva - %s - %s\n", courses[index].price, courses[index].name, courses[index].start_date);
}

// Function to save courses within a price range to a text file
int saveCoursesInPriceRange(Course *courses, int n, float min_price, float max_price, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s!\n", filename);
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (courses[i].price >= min_price && courses[i].price <= max_price) {
            fprintf(file, "%s\n%s\n%d lectures\n%.2f leva\n\n", 
                    courses[i].name, courses[i].start_date, courses[i].total_lectures, courses[i].price);
            count++;
        }
    }
    fclose(file);
    return count;
}

// Function to delete a course by name and start date
Course* deleteCourse(Course **courses, int *n, const char *name, const char *start_date) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp((*courses)[i].name, name) == 0 && strcmp((*courses)[i].start_date, start_date) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Course not found!\n");
        return NULL;
    }
    for (int i = index; i < *n - 1; i++) {
        (*courses)[i] = (*courses)[i + 1];
    }
    *n -= 1;
    *courses = (Course *)realloc(*courses, (*n) * sizeof(Course));
    printf("Course deleted successfully.\n");
    return *courses;
}

int main() {
    Course *courses;
    int count = loadCourses("courses.bin", &courses);
    if (count == 0) return 1;

    int index;
    printf("Enter index to apply discount: ");
    scanf("%d", &index);
    applyDiscount(courses, count, index);

    float min_price, max_price;
    printf("Enter min and max price: ");
    scanf("%f %f", &min_price, &max_price);
    saveCoursesInPriceRange(courses, count, min_price, max_price, "offer.txt");

    char course_name[51], course_date[11];
    printf("Enter course name to delete: ");
    scanf("%50s", course_name);
    printf("Enter start date (YYYY.MM.DD): ");
    scanf("%10s", course_date);
    courses = deleteCourse(&courses, &count, course_name, course_date);

    free(courses);
    return 0;
}