#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, WON, LOST};

int rollDice(void);


void main(void)
{
    srand(time(NULL));
    int sum = rollDice();
    printf ("%d",sum);

}

int rollDice(void)
{
    int die1 = 1 + (rand() % 6);
    int die2 = 1 + (rand() % 6);


    return die1 + die2;
}