#include <stdio.h>
#include <stdlib.h>

struct card {
    char *face;
    char *suit;
};

int main() {
    // Kart yüzleri ve takımları için sabit diziler
    char *faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // Kart destesi oluşturma
    struct card deck[52];

    // Kartları oluşturma
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[i * 4 + j].face = faces[i];
            deck[i * 4 + j].suit = suits[j];
        }
    }

    // Desteyi karıştırma (opsiyonel)

    // Rastgele bir dizge oluşturmak için srand() fonksiyonunu kullan
    srand(time(NULL));
    // Fisher-Yates shuffle algoritmasını uygula
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Karıştırılmış desteği yazdırma
    for (int i = 0; i < 52; i++) {
        printf("%s of %s\n", deck[i].face, deck[i].suit);
    }

    return 0;
}
