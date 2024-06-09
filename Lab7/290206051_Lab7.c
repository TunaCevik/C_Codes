
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACES 13

              
typedef struct {                                
   const char *face;     
}Card; 


void fillDeck(Card * const wDeck, const char * wFace[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{ 
   Card deck[FACES]; 

   
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   

   srand(time(NULL)); 

   fillDeck(deck, face); 
   shuffle(deck);
   deal(deck);
} 


void fillDeck(Card * const wDeck, const char * wFace[])
{ 
   
   for (size_t i = 0; i < FACES; ++i) { 
      wDeck[i].face = wFace[i % FACES];
   } 
} 


void shuffle(Card * const wDeck)
{ 
   
   for (size_t i = 0; i < FACES; ++i) { 
      size_t j = rand() % FACES;
      Card temp = wDeck[i];      
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;      
   } 
} 


void deal(const Card * const wDeck)
{ 
   
   for (size_t i = 0; i < FACES; ++i) {
      printf("%5s ",wDeck[i].face);
      if(i%3 == 0){
         printf("\n");
      }
   } 
} 
