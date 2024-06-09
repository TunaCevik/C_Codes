#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTACKSIZE 10

struct Deck {
    int val[MAXSTACKSIZE];
    int count;
};

void push(struct Deck *top, int newVal) {
    if (top->count < MAXSTACKSIZE) {
        top->val[top->count++] = newVal;
    } else {
        printf("Stack is full!\n");
    }
}

void pop(struct Deck *top) {
    if (top->count > 0) {
        top->count--;
    } else {
        printf("Stack is empty!\n");
    }
}

void fillDeck(struct Deck *top, int size) {
    for (int i = size; i > 0; i--) {
        push(top, i);
    }
}

void riffle(struct Deck *top) {
    int temp[MAXSTACKSIZE];
    int mid = top->count / 2;
    int index = 0;
    
    for (int i = 0; i < mid; i++) {
        temp[index++] = top->val[i];
        temp[index++] = top->val[mid + i];
    }
    
    for (int i = 0; i < top->count; i++) {
        top->val[i] = temp[i];
    }
}

// Fisher-Yates shuffle function with print statements
void fisheryates(struct Deck *top) {
    for (int i = top->count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = top->val[i];
        top->val[i] = top->val[j];
        top->val[j] = temp;
        printf("Swapped positions %d and %d: ", i, j);
        for (int k = 0; k < top->count; k++) {
            printf("%d ", top->val[k]);
        }
        printf("\n");
    }
}

void print(struct Deck *top) {
    for (int i = 0; i < top->count; i++) {
        printf("%d ", top->val[i]);
    }
    printf("\n");
}

int main() {
    struct Deck myDeck = { .count = 0 };
    srand(time(NULL)); // Seed random number generator

    fillDeck(&myDeck, MAXSTACKSIZE);
    printf("Deck after filling:\n");
    print(&myDeck);

    // Riffle shuffle 10 times
    for (int i = 0; i < 10; i++) {
        riffle(&myDeck);
        printf("Deck after riffle %d:\n", i + 1);
        print(&myDeck);
    }

    // Fisher-Yates shuffle with detailed swap information
    printf("Starting Fisher-Yates shuffle with detailed swap information:\n");
    fisheryates(&myDeck);
    printf("Deck after Fisher-Yates shuffle:\n");
    print(&myDeck);

    return 0;
}
