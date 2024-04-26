#include <stdio.h>
struct Card{
    const char*face;
    const char *Pattern;

};
typedef struct Card card;

int main()
{
    typedef int Tamsayi;

    Tamsayi sayi1 = 12345;
    printf("%d",sayi1);

    card deck[12];

    deck[0].face = "Allah";
    deck[0].Pattern= "Peygamber";

    printf("\n %s, %s",deck[0].face, deck[0].Pattern);

    int i = 40;
    printf("\n%d  %d",i%13, i/13);
    

}