#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 100

// Structure to hold the game data
typedef struct {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int attemptsLeft;
} HangmanGame;

// Function prototypes
void initializeGame(HangmanGame *game, const char *word, int attempts);
void displayWord(const char *guessed);
int isWordGuessed(const char *word, const char *guessed);
void processGuess(HangmanGame *game, char guess);

int main() {
    srand(time(NULL)); // Seed for random word selection
    HangmanGame game;
    char category;
    const char *wordToGuess;

    // Predefined categories and words
    const char *fruits[] = {"apple", "banana", "cherry"};
    const char *colors[] = {"red", "blue", "green"};
    const char *vegetables[] = {"carrot", "potato", "spinach"};

    printf("Welcome to Hangman!\n");
    printf("Select a category:\n");
    printf("1. Fruit Names\n");
    printf("2. Color Names\n");
    printf("3. Vegetable Names\n");

    do {
        printf("Enter your choice (1/2/3): ");
        scanf(" %c", &category);
    } while (category != '1' && category != '2' && category != '3');

    switch (category) {
        case '1':
            wordToGuess = fruits[rand() % 3];
            printf("You selected: Fruit Names\n");
            break;
        case '2':
            wordToGuess = colors[rand() % 3];
            printf("You selected: Color Names\n");
            break;
        case '3':
            wordToGuess = vegetables[rand() % 3];
            printf("You selected: Vegetable Names\n");
            break;
        default:
            wordToGuess = fruits[rand() % 3];
    }

    int attempts = (int)strlen(wordToGuess) + 3;
    initializeGame(&game, wordToGuess, attempts);

    while (game.attemptsLeft > 0) {
        printf("\nWord to guess: ");
        displayWord(game.guessed);
        printf("Attempts left: %d\n", game.attemptsLeft);
        printf("Enter your guess: ");

        char guess;
        scanf(" %c", &guess);
        guess = tolower(guess);

        processGuess(&game, guess);

        if (isWordGuessed(game.word, game.guessed)) {
            printf("\nCongratulations! You guessed the word: %s\n", game.word);
            break;
        }
    }

    if (game.attemptsLeft == 0) {
        printf("\nGame over! The word was: %s\n", game.word);
    }

    return 0;
}

void initializeGame(HangmanGame *game, const char *word, int attempts) {
    strncpy(game->word, word, MAX_WORD_LENGTH);
    size_t length = strlen(word);
    for (int i = 0; i < (int)length; i++) {
        game->guessed[i] = '_';
    }
    game->guessed[length] = '\0';
    game->attemptsLeft = attempts;
}

void displayWord(const char *guessed) {
    for (int i = 0; guessed[i] != '\0'; i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}

int isWordGuessed(const char *word, const char *guessed) {
    return strcmp(word, guessed) == 0;
}

void processGuess(HangmanGame *game, char guess) {
    int found = 0;
    size_t length = strlen(game->word);
    for (int i = 0; i < (int)length; i++) {
        if (game->word[i] == guess) {
            game->guessed[i] = guess;
            found = 1;
        }
    }

    if (!found) {
        game->attemptsLeft--;
        printf("Incorrect guess!\n");
    } else {
        printf("Good guess!\n");
    }
}
