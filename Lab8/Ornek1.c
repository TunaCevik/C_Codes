#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node yapısı tanımı
typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

// Yeni bir düğüm oluşturur
Node* createNode(const char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

// Listeye düğüm ekler
void appendNode(Node** head, const char* str) {
    Node* newNode = createNode(str);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// `strcpy` fonksiyonunu bağlı listede uygular
void copyString(Node* src, Node* dest) {
    if (src != NULL && dest != NULL) {
        strcpy(dest->data, src->data);
    }
}

// Listeyi yazdırır
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Ana fonksiyon
int main() {
    Node* head = NULL;
    char input[50];

    // Kullanıcıdan stringler al ve listeye ekle
    printf("Bagli listeye eklemek icin stringler girin (sonlandirmak icin 'exit' yazin):\n");
    while (1) {
        printf("String: ");
        scanf("%49s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        appendNode(&head, input);
    }

    // Stringi kopyala
    if (head != NULL && head->next != NULL) {
        copyString(head, head->next);
    }

    // Listeyi yazdır
    printf("\nBagli listedeki stringler:\n");
    printList(head);

    // Belleği serbest bırak
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
