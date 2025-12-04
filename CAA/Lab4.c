#include <stdio.h>
#include <limits.h>

#define N 4 

// --- Helper function 
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// -----------------------------------------------------------------------------------
// Task 1: Process the 2D array and populate the 1D result array (4 elements)
// -----------------------------------------------------------------------------------
void process_matrix_task1(int matrix[N][N], int result_array[4]) {
    // Count even elements on the main diagonal
    int even_main_diag = 0;
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] % 2 == 0) {
            even_main_diag++;
        }
    }
    result_array[0] = even_main_diag;

    // Count negative elements on the secondary diagonal
    int neg_secondary_diag = 0;
    for (int i = 0; i < N; i++) {
        int j = N - 1 - i; 
        if (matrix[i][j] < 0) {
            neg_secondary_diag++;
        }
    }
    result_array[1] = neg_secondary_diag;

    // Find the row index of the maximum element & 4. Find the column index of the minimum element
    int max_element = INT_MIN; 
    int max_row_index = -1; 
    int min_element = INT_MAX; 
    int min_col_index = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > max_element) {
                max_element = matrix[i][j];
                max_row_index = i; 
            }
            if (matrix[i][j] < min_element) {
                min_element = matrix[i][j];
                min_col_index = j; 
            }
        }
    }
    
    result_array[2] = max_row_index;
    result_array[3] = min_col_index;
}

// -----------------------------------------------------------------------------------
// Task 2: Create a 1D array with GCD of all main diagonal pairs 
// -----------------------------------------------------------------------------------
#define NUM_GCD_PAIRS (N * (N - 1) / 2)

void calculate_gcd_pairs(int matrix[N][N], int gcd_results[NUM_GCD_PAIRS]) {
    int diagonal_elements[N];
    for (int i = 0; i < N; i++) {
        diagonal_elements[i] = matrix[i][i];
    }

    int k = 0; 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            gcd_results[k] = gcd(diagonal_elements[i], diagonal_elements[j]);
            k++;
        }
    }
}

// -----------------------------------------------------------------------------------
// Task 3: Find the largest negative value in each column
// -----------------------------------------------------------------------------------
void find_largest_negative_per_column(int matrix[N][N], int negative_results[N]) {
    for (int j = 0; j < N; j++) {
        int largest_neg = INT_MIN; 
        int negative_found = 0; 

        for (int i = 0; i < N; i++) {
            int current_element = matrix[i][j];

            if (current_element < 0) {
                negative_found = 1;
                if (current_element > largest_neg) {
                    largest_neg = current_element;
                }
            }
        }

        if (negative_found) {
            negative_results[j] = largest_neg;
        } else {
            negative_results[j] = 0;
        }
    }
}

// -----------------------------------------------------------------------------------
// Task 4: Zero out elements greater than their row's average. This function takes a copy of the matrix
// -----------------------------------------------------------------------------------
void zero_elements_above_row_average(int original_matrix[N][N], int modified_matrix[N][N]) {
    // First, copy the original matrix to the modified_matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            modified_matrix[i][j] = original_matrix[i][j];
        }
    }

    // Now, process the modified_matrix row by row
    for (int i = 0; i < N; i++) {
        long long sum = 0; // Use long long for sum to prevent potential overflow
        
        // Calculate the sum of the current row (i)
        for (int j = 0; j < N; j++) {
            sum += modified_matrix[i][j];
        }

        // Calculate the average for the current row
        // Use float for the average calculation to maintain precision
        float average = (float)sum / N;

        // Compare each element in the row with the average and zero it out if larger
        printf("Row %d Average: %.2f\n", i, average);
        for (int j = 0; j < N; j++) {
            if (modified_matrix[i][j] > average) {
                modified_matrix[i][j] = 0; 
            }
        }
    }
}


void print_matrix(int matrix[N][N], const char* title) {
    printf("\n--- %s (%dx%d) ---\n", title, N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

void print_task1_results(int results[4]) {
    printf("\n--- Task 1 Results (4 Elements) ---\n");
    printf("Result 0: Even Main Diag Count: %d\n", results[0]);
    printf("Result 1: Neg Secondary Diag Count: %d\n", results[1]);
    printf("Result 2: Max Element Row Index: %d\n", results[2]);
    printf("Result 3: Min Element Col Index: %d\n", results[3]);
    printf("Full Array: [ %d, %d, %d, %d ]\n", results[0], results[1], results[2], results[3]);
    printf("----------------------------------\n");
}

void print_task2_results(int gcd_results[NUM_GCD_PAIRS]) {
    printf("\n--- Task 2 Results (GCD of Main Diagonal Pairs) ---\n");
    printf("The result array has %d elements (GCDs of pairs):\n[ ", NUM_GCD_PAIRS);
    for (int i = 0; i < NUM_GCD_PAIRS; i++) {
        printf("%d", gcd_results[i]);
        if (i < NUM_GCD_PAIRS - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("---------------------------------------------------\n");
}

void print_task3_results(int negative_results[N]) {
    printf("\n--- Task 3 Results (Largest Negative per Column) ---\n");
    printf("Full Array: [ ");
    for (int j = 0; j < N; j++) {
        printf("%d", negative_results[j]);
        if (j < N - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
    printf("---------------------------------------------------\n");
}


int main() {
    // Example 2D array (N x N)
    int matrix[N][N] = {
        { 1,   5,  10,   8},
        { 3,  -2,   6,   4},
        {-7,   1,   0,   9},
        { 2,   3,  -4, -11}
    };
    
    // Arrays to store the results
    int task1_results[4]; 
    int task2_gcd_results[NUM_GCD_PAIRS];
    int task3_negative_results[N];
    int task4_modified_matrix[N][N]; // Array for the modified matrix in 4

    print_matrix(matrix, "Original Input Matrix");
    
    // ---  Task 1 ---
    printf("\n*** Starting Task 1: Analyzing Diagonals and Extremes ***\n");
    process_matrix_task1(matrix, task1_results);
    print_task1_results(task1_results);

    // ---  Task 2 ---
    printf("\n*** Starting Task 2: Calculating GCD of Main Diagonal Pairs ***\n");
    calculate_gcd_pairs(matrix, task2_gcd_results);
    print_task2_results(task2_gcd_results);

    // ---  Task 3 ---
    printf("\n*** Starting Task 3: Finding Largest Negative per Column ***\n");
    find_largest_negative_per_column(matrix, task3_negative_results);
    print_task3_results(task3_negative_results);

    // ---  Task 4 ---
    printf("\n*** Starting Task 4: Zeroing Elements Above Row Average ***\n");
    zero_elements_above_row_average(matrix, task4_modified_matrix);
    print_matrix(task4_modified_matrix, "Matrix After Task 4 Modification");

    return 0;
}