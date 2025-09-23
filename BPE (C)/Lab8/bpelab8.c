#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 81

char **text = NULL;  // dynamic array for lines of text // each string = 1 line
int line_count = 0;  // number of lines currently stored

// input lines of text from user
void inputText() {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter lines of text (empty line to stop):\n");

    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin); // read input
        if (buffer[0] == '\n') break; // stop if line is empty
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline

        // allocate memory for a new line
        text = realloc(text, (line_count + 1) * sizeof(char *));
        text[line_count] = malloc(MAX_LINE_LENGTH);
        // copy the input line to the array
        strncpy(text[line_count], buffer, MAX_LINE_LENGTH); // copies up to a specified number of characters from one string
        text[line_count][MAX_LINE_LENGTH - 1] = '\0';
        line_count++;
    }
}

// determine whether a character is a word boundary
int isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '.' || c == '!' || c == '?' || c == '\0';
}

// count all words across all lines
int countWords() {
    int total = 0;
    // loop through characters
    for (int i = 0; i < line_count; i++) {
        char *line = text[i];
        int inWord = 0; // track when a word starts
        for (int j = 0; line[j]; j++) {
            if (!isDelimiter(line[j])) {
                if (!inWord) {
                    inWord = 1;
                    total++;
                }
            } else {
                inWord = 0;
            }
        }
    }
    return total;
}

// left-align a line (remove leading spaces)
void alignLeft(int lineNo) {
    if (lineNo < 0 || lineNo >= line_count) {
        printf("Invalid line number!\n");
        return;
    }

    char *line = text[lineNo];
    int start = 0;

    while (isspace(line[start])) start++; // find the first non-space character

    memmove(line, line + start, strlen(line + start) + 1); // shift the line left
}

// right-align a line by padding with spaces
void alignRight(int lineNo) {
    if (lineNo < 0 || lineNo >= line_count) {
        printf("Invalid line number!\n");
        return;
    }

    char temp[MAX_LINE_LENGTH];
    int len = 0;

    sscanf(text[lineNo], "%[^\n]", temp); // get the line text
    len = strlen(temp);

    int spaces = MAX_LINE_LENGTH - 2 - len;
    if (spaces < 0) spaces = 0;

    snprintf(text[lineNo], MAX_LINE_LENGTH, "%*s", len + spaces, temp); // build a new right-aligned string
}

// reverse a specific line
void reverseLine(int lineNo) {
    if (lineNo < 0 || lineNo >= line_count) {
        printf("Invalid line number!\n");
        return;
    }

    char *line = text[lineNo];
    int len = strlen(line);
    // swap characters from both ends toward the middle
    for (int i = 0; i < len / 2; i++) {
        char tmp = line[i];
        line[i] = line[len - 1 - i];
        line[len - 1 - i] = tmp;
    }
}

// count how many times a word appears in the text
int countWordOccurrences(const char *word) {
    int total = 0;

    for (int i = 0; i < line_count; i++) {
        char *copy = strdup(text[i]); // string duplicate
        char *token = strtok(copy, " \t.!?"); // string tokenizer, split into individual words

        while (token != NULL) {
            if (strcmp(token, word) == 0) // compare each token to the word
                total++;
            token = strtok(NULL, " \t.!?");
        }

        free(copy);
    }

    return total;
}

// replace all of old word with new word in all lines
void replaceWord(const char *oldWord, const char *newWord) {
    for (int i = 0; i < line_count; i++) {
        char buffer[MAX_LINE_LENGTH * 2] = "";
        char *copy = strdup(text[i]); // make temp copy
        char *rest = text[i]; // track original text
        char *token = strtok(copy, " \t.!?");

        while (token) {
            char *found = strstr(rest, token);
            strncat(buffer, rest, found - rest); // appends up to n characters (strcat)
            if (strcmp(token, oldWord) == 0) { // compares two strings character by character
                strcat(buffer, newWord); // appends a string to the end of another
            } else {
                strcat(buffer, token);
            }
            rest = found + strlen(token); // length of a string
            token = strtok(NULL, " \t.!?");
        }

        strncpy(text[i], buffer, MAX_LINE_LENGTH);
        text[i][MAX_LINE_LENGTH - 1] = '\0';
        free(copy);
    }
}

// print menu
void printMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Enter text\n");
    printf("2. Count words\n");
    printf("3. Align line left\n");
    printf("4. Align line right\n");
    printf("5. Reverse line\n");
    printf("6. Search for word\n");
    printf("7. Replace word\n");
    printf("0. Exit\n");
}

// free memory
void freeText() {
    for (int i = 0; i < line_count; i++) {
        free(text[i]);
    }
    free(text);
}

// print the current text 
void printText() {
    printf("\n=== Current Text ===\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, text[i]);  // Line numbers start from 1
    }
    printf("====================\n");
}


// menu loop
int main() {
    int choice;
    do {
        printMenu();
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        int lineNo;
        char word[MAX_LINE_LENGTH];
        char newWord[MAX_LINE_LENGTH];

        switch (choice) {
            case 1:
                inputText();
                break;
            case 2:
                printf("Total words: %d\n", countWords());
                break;
            case 3:
                printf("Enter line number: ");
                scanf("%d", &lineNo);
                getchar();
                lineNo--;
                alignLeft(lineNo);
                break;
            case 4:
                printf("Enter line number: ");
                scanf("%d", &lineNo);
                getchar();
                lineNo--;
                alignRight(lineNo);
                break;
            case 5:
                printf("Enter line number: ");
                scanf("%d", &lineNo);
                getchar();
                lineNo--;
                reverseLine(lineNo);
                break;
            case 6:
                printf("Enter word to search: ");
                scanf("%80s", word);
                getchar();
                printf("Occurrences: %d\n", countWordOccurrences(word));
                break;
            case 7:
                printf("Word to replace: ");
                scanf("%80s", word);
                getchar();
                printf("New word: ");
                scanf("%80s", newWord);
                getchar();
                replaceWord(word, newWord);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (choice >= 1 && choice <= 7) {
            printText();
        }

    } while (choice != 0);

    freeText();
    return 0;
}
