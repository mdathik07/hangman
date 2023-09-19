#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct User {
    char username[20];
    char password[20];
};

int authenticate(struct User user) {
    if (strcmp(user.username, "Atheeq") == 0 && strcmp(user.password, "1RF22IS047") == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

char* getRandomWord() {
    char* words[] = {"atheeq", "nithin", "hangman", "rohit", "apple"};
    int randomIndex = rand() % 5;
    return words[randomIndex];
}

int main() {
    struct User user;
    printf("Welcome to Hangman!\n");

    printf("Enter your username: ");
    scanf("%s", user.username);

    printf("Enter your password: ");
    scanf("%s", user.password);

    if (authenticate(user)) {
        printf("Login successful!\n");

        srand(time(NULL));
        char* word = getRandomWord();
        int length = strlen(word);
        char guessed[length];
        memset(guessed, '_', length);
        guessed[length] = '\0';

        int attempts = 6;
        char guess;
        int found = 0;

        while (attempts > 0) {
            printf("Current word: %s\n", guessed);
            printf("Attempts remaining: %d\n", attempts);
            printf("Enter your guess: ");
            scanf(" %c", &guess);

            found = 0;
            for (int i = 0; i < length; i++) {
                if (word[i] == guess) {
                    if (guessed[i] == guess) {
                        printf("You already guessed '%c'. Try a different letter.\n", guess);
                    } else {
                        guessed[i] = guess;
                        found = 1;
                    }
                }
            }

            if (!found) {
                attempts--;
            }

            if (strcmp(guessed, word) == 0) {
                printf("Congratulations! You guessed the word: %s\n", word);
                break;
            }
        }

        if (attempts == 0) {
            printf("Sorry, you ran out of attempts. The word was: %s\n", word);
        }

    } else {
        printf("Invalid Input or Username.....\n");
    }

    return 0;
}