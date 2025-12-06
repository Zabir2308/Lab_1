#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 65

typedef struct WordNode {
    char english[MAX_WORD_LENGTH + 1];
    char hungarian[MAX_WORD_LENGTH + 1];
    struct WordNode* next;
} Words;

Words* addWordPair(Words* head, const char* english, const char* hungarian) {
    Words* newNode = (Words*)malloc(sizeof(Words));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    strncpy(newNode->english, english, MAX_WORD_LENGTH);
    newNode->english[MAX_WORD_LENGTH] = '\0';

    strncpy(newNode->hungarian, hungarian, MAX_WORD_LENGTH);
    newNode->hungarian[MAX_WORD_LENGTH] = '\0';

    newNode->next = head;

    return newNode;
}

void deleteWords(Words* head) {
    Words* current = head;
    Words* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void printWords(Words* head) {
    Words* current = head;
    int count = 1;

    if (current == NULL) {
        printf("Dictionary is empty.\n");
        return;
    }

    printf("\n=== English-Hungarian Dictionary ===\n");
    while (current != NULL) {
        printf("%d. %s - %s\n", count, current->english, current->hungarian);
        count++;
        current = current->next;
    }
    printf("====================================\n");
}

int main() {
    Words* dictionary = NULL;
    char english[MAX_WORD_LENGTH + 1];
    char hungarian[MAX_WORD_LENGTH + 1];

    printf("English-Hungarian Dictionary\n");
    printf("Enter word pairs (English then Hungarian). Type 'STOP' to finish.\n\n");

    while (1) {
        printf("Enter English word: ");
        if (scanf("%65s", english) != 1) {
            break;
        }

        if (strcmp(english, "STOP") == 0) {
            break;
        }

        printf("Enter Hungarian word: ");
        if (scanf("%65s", hungarian) != 1) {
            break;
        }

        if (strcmp(hungarian, "STOP") == 0) {
            break;
        }

        dictionary = addWordPair(dictionary, english, hungarian);
    }

    printWords(dictionary);

    deleteWords(dictionary);

    return 0;
}
