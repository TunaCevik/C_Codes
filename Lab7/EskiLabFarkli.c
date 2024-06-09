#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTACKSIZE 10

struct Deck {
    int val[MAXSTACKSIZE];
    int count;
};

void push(struct Deck *deck, int value) {
    if (deck->count < MAXSTACKSIZE) {
        deck->val[deck->count++] = value;
    } else {
        printf("Deck is full\n");
    }
}

void pop(struct Deck *deck) {
    if (deck->count > 0) {
        deck->count--;
    } else {
        printf("Deck is empty\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fillDeck(struct Deck *deck) {
    for (int i = MAXSTACKSIZE; i > 0; i--) {
        push(deck, i);
    }
}

void printDeck(struct Deck *deck) {
    for (int i = 0; i < deck->count; i++) {
        printf("%d ", deck->val[i]);
    }
    printf("\n");
}

void fisheryatesShuffle(struct Deck *deck) {
    for (int i = deck->count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&deck->val[i], &deck->val[j]);
        printDeck(deck);
    }
}

int main() {
    struct Deck deck = {0};
    srand(time(NULL));
    fillDeck(&deck);
    printDeck(&deck);
    fisheryatesShuffle(&deck);
    return 0;
}
