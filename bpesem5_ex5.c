// Plamena Vasileva Georgieva
// Faculty Number: 381224060
// Group: 95
// Exercise Group: 4

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 25
#define EXTRA_ATTEMPTS 2

const char *TARGET_WORD = "coNCatEnaTioN";

void hidden_word(const char *word, const int *revealed) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (revealed[i]) {
            printf("%c", word[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int guessed(const int *revealed, int length) {
    for (int i = 0; i < length; i++) {
        if (!revealed[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char word[MAX_WORD_LENGTH];
    strcpy(word, TARGET_WORD);

    // word to lowercase
    for (int i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    int word_length = strlen(word);
    int revealed[MAX_WORD_LENGTH] = {0};
    int guess_count = 0;
    char guess;
    int max_attempts = word_length + EXTRA_ATTEMPTS;

    printf("Welcome to Hangman!\n");
    printf("The word has %d letters:\n", word_length);

    while (guess_count < max_attempts) {
        hidden_word(word, revealed);
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        // input is a letter
        if (!isalpha(guess)) {
            printf("Invalid input! Please enter a letter only.\n\n");
            continue; 
        }

        guess = tolower(guess);
        guess_count++;

        int found = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                revealed[i] = 1;
                found = 1;
            }
        }

        if (!found) {
            printf("Letter '%c' is not in the word.\n", guess);
        }

        int remaining = max_attempts - guess_count;
        printf("Remaining guesses: %d\n", remaining);

        if (guessed(revealed, word_length)) {
            printf("Congratulations! You've guessed the word '%s' in %d guesses.\n", word, guess_count);
            return 0;
        }

        printf("\n"); 
    }

    printf("Sorry, you've used too many guesses. The word was '%s'.\n", word);
    return 0;
}