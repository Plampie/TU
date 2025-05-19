// Ex 1
// Всяка редица от равни числа в едномерен сортиран масив,
// се нарича площадка. Да се напише програма, която намира
// началото и дължината на най-дългата площадка в даден
// сортиран във възходящ ред едномерен масив(въвеждат се
// N и самият масив от потребителя).

// Да се използват функции и да се прави проверка за дължината на масива

#include <stdio.h>

//bubble sort
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void findLongest(int arr[], int n, int *start, int *length) {

    int maxLen = 1, maxStart = 0;
    int curLen = 1, curStart = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }
    
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }
    
    *start = maxStart;
    *length = maxLen;
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }
    
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (!isSorted(arr, n)) {
        sortArray(arr, n);
        printf("Array was not sorted. Sorted automatically.\n");
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int start, length;
    findLongest(arr, n, &start, &length);
    
    printf("Longest starts from index %d and is long %d.\n", start, length);
    
    return 0;
}



// Ex 6
// За дадена редица от числа да се намери и отпечата найдългата (монотонно) нарастваща (или намаляваща) под редица

// Да се използват функции и да се правят проверки

#include <stdio.h>

void findMonLong(int arr[], int n, int *start, int *length) {

    int maxLen = 1, maxStart = 0;
    int curLen = 1, curStart = 0;
    
    //raise
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }
    
    //fall
    curLen = 1;
    curStart = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }
    
    *start = maxStart;
    *length = maxLen;
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }
    
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int start, length;
    findMonLong(arr, n, &start, &length);
    
    printf("Longest mon strats from index %d and its lenght is %d.\n", start, length);
    
    return 0;
}



// Ex 9
// Напишете програма, която намира максималната редица от последователни еднакви елементи в масив и ги отпечатва.
// Сканирате масива . Всеки път , когато текущото число е
// различно от следващото от него започва нова поредица, а
// всеки път когато текущото число съвпада със следващото ,
// то е продължение на текущата поредица.

// Да се използват функции и да се правят проверки

#include <stdio.h>

void findMaxSeq(int arr[], int n, int *start, int *length) {

    int maxLen = 1, maxStart = 0;
    int curLen = 1, curStart = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            curLen++;
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                maxStart = curStart;
            }
            curStart = i;
            curLen = 1;
        }
    }
    
    if (curLen > maxLen) {
        maxLen = curLen;
        maxStart = curStart;
    }
    
    *start = maxStart;
    *length = maxLen;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }
    
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int start, length;
    findMaxSeq(arr, n, &start, &length);
    
    printf("Longest same elements starts from index %d and is long %d: ", start, length);
    for (int i = start; i < start + length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}




