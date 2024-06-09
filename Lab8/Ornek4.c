#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node yapısı tanımı
typedef struct Node {
    char data[100];
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

// Listeyi ters çevirir ve `strcpy` ile kopyalar
Node* reverseList(Node* head) {
    Node* reversedHead = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* newNode = createNode(temp->data);
        newNode->next = reversedHead;
        reversedHead = newNode;
        temp = temp->next;
    }
    return reversedHead;
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
    char input[100];

    // Kullanıcıdan stringler al ve listeye ekle
    printf("Bağlı listeye eklemek için stringler girin (sonlandırmak için 'exit' yazın):\n");
    while (1) {
        printf("String: ");
        scanf("%99s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        appendNode(&head, input);
    }

    // Listeyi ters çevir ve yeni listeyi yazdır
    Node* reversedHead = reverseList(head);

    printf("\nTers çevrilmiş bağlı listedeki stringler:\n");
    printList(reversedHead);

    // Belleği serbest bırak
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    while (reversedHead != NULL) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        free(temp);
    }

    return 0;
}
