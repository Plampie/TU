// Даден е масив NxM запълнен с цели числа. Намерете числото, което
// има околни на него сбора, на които е най-голям. (околно е всяко число
// което се намира до, над, под или по диагонал на текущото на отстояние не
// повече от 1 поле).

#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLS 20

// check if cell within the array
int is_valid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// calculate the sum neighbor cells
// loop troght matrix
// check valid
// skip center elements
// add to sum 
int get_sum(int matrix[MAX_ROWS][MAX_COLS], int row, int col, int rows, int cols) {
    int sum = 0;
    // 3x3 matrix at (row, col)
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // skip center cell
            if (i == row && j == col)
                continue;
            if (is_valid(i, j, rows, cols))
                sum += matrix[i][j];
        }
    }
    return sum;
}

// find the cell with the maximum sum
// loop every element of the matrix
// get neighbor sum
// track max sum
// store coordinates
void find_maxsum(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int maxsum = -2147483648; // min value of an int
    int maxrow = 0, maxcol = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = get_sum(matrix, i, j, rows, cols);
            if (sum > maxsum) {
                maxsum = sum;
                maxrow = i;
                maxcol = j;
            }
        }
    }

    printf("The number with the highest sum is %d at position (%d, %d).\n", matrix[maxrow][maxcol], maxrow, maxcol);
    printf("The sum of its neighbors is %d.\n", maxsum);
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    find_maxsum(matrix, rows, cols);

    return 0;
}


// В училището на Ели има 1 ≤ N ≤ 100,000 човека. Някои от тях се
// познават с други, като Ели знае, че съществуват 1 ≤ M ≤ 1,000,000 такива
// приятелства. Тя иска да напише програма, която бързо отговаря кои са
// приятелите на даден човек. Ако хората се подават с номера като цяло
// число, както и приятелите им изведете при поискан човек колко приятели
// има. (ако 1 е приятел с 3 то и 3 е приятел с 1).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 100001
#define MAX_FRIENDSHIPS 1000000
#define MAX_NAME_LEN 50

// store each person’s data
typedef struct {
    char name[MAX_NAME_LEN];
    int class;
} Person;

// person has a list of their friends using a linked list
typedef struct FriendNode {
    int friend_index;
    struct FriendNode* next;
} FriendNode;

Person people[MAX_PEOPLE];
FriendNode* adjacency_list[MAX_PEOPLE]; // array of pointers to friend lists

// safely allocate a new friend node
FriendNode* create_friend_node(int friend_index) {
    FriendNode* node = (FriendNode*)malloc(sizeof(FriendNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed for node.\n"); // call output to error stream
        exit(EXIT_FAILURE);
    }
    node->friend_index = friend_index;
    node->next = NULL;
    return node;
}

// FriendNodes are dynamically created and linked in adjacency_list[]
// add a friend in list
void add_friend(int a, int b) {
    // add b to a list
    FriendNode* node1 = (FriendNode*)malloc(sizeof(FriendNode)); // dynamically creating new nodes 
    node1->friend_index = b; // store b into the new node
    node1->next = adjacency_list[a]; // set next pointer new node -> current head of a list.
    adjacency_list[a] = node1; // // update the head of a friend list 

    // add a to b list
    FriendNode* node2 = (FriendNode*)malloc(sizeof(FriendNode));
    node2->friend_index = a;
    node2->next = adjacency_list[b];
    adjacency_list[b] = node2;
}

// counts how many nodes (friends) exist
int count_friends(int person_index) {
    int count = 0;
    FriendNode* current = adjacency_list[person_index];
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// display person info
void print_person_table(int n) {
    printf("People Table:\n");
    for (int i = 1; i <= n; i++) {
        printf("Index: %d | Name: %s | Class: %d\n", i, people[i].name, people[i].class);
    }
}


// free the entire linked list of friends
// clean up memory
void free_memory(int n) {
    for (int i = 1; i <= n; i++) {
        FriendNode* current = adjacency_list[i];
        while (current != NULL) {
            FriendNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int N, M;

    printf("Enter number of people (N): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N >= MAX_PEOPLE) {
        fprintf(stderr, "Invalid number of people.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i <= N; i++) {
        printf("Enter name and class for person %d: ", i);
        if (scanf("%s %d", people[i].name, &people[i].class) != 2) {
            fprintf(stderr, "Invalid input for person info.\n");
            return EXIT_FAILURE;
        }    
    }

    printf("Enter number of friendships (M): ");
    if (scanf("%d", &M) != 1 || M <= 0 || M > MAX_FRIENDSHIPS) {
        fprintf(stderr, "Invalid number of friendships. M must be between 1 and %d.\n", MAX_FRIENDSHIPS);
        return EXIT_FAILURE;
    }

    // read friendships
    printf("Enter %d pairs of friends (in index):\n", M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_friend(a, b);
    }

    // print table of people
    print_person_table(N);

    // query loop
    int query;
    while (1) {
        printf("Enter person index to get number of friends (0 to exit): \n");
        if (scanf("%d", &query) != 1) {
            fprintf(stderr, "Invalid input.\n");
            break;
        }

        if (query == 0)
            break;

        if (query < 1 || query > N) {
            printf("Invalid person index.\n");
            continue;
        }

        int friends = count_friends(query);
        printf("%s from class %d has %d friend(s).\n", people[query].name, people[query].class, friends);
    }

    // free allocated memory
    free_memory(N);

    return 0;
}