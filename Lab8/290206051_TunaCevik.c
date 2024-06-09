#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

const char *c[N] = {"EE311", "EE411", "EE245", "EE443", "EE455", "EE461"};
const char *d[N] = {"Digital Electronics", "Fundementals of Photonics", "Microwawe Engineering", "Embedded Systems", "Mobile Communication", "Nonlinear Control Systems"};

struct Node
{
    char *c_code[N];
    char *courses[N];
    struct Node *next;
};

struct Node *Node_head = NULL;
void insert_front(int c_select);
void insert_rear(int c_select);
void print_cl();
int course_check(int c_select);

int main() 
{

    int i;
    int OSel, CSel;
    while(1) {
        printf("\nChoose operation:\n");
        printf("1. Add a course at the front of the CouseList\n");
        printf("2. Add a course at the end of the CourseList\n");
        scanf("%d", &OSel);

        for(i = 0; i<6; i++) {
            printf("%d %s-%s\n", i+1, c[i], d[i]);
        }
        scanf("%d", &CSel);
        if(course_check(CSel-1) == 0) continue;
        switch (OSel) {
        case 1:
            insert_front(CSel-1);
            break;
        case 2:
            insert_rear(CSel -1);
            break;
        default:
            printf("Please select either add_front or add_end optinon (1 or 2)");
            break;
        }
        printf("\n The updated CorseList is : \n");
        print_cl();

    }

    return 0;
}

void insert_front(int c_select) {
    struct Node *Node_E = (struct Node*)malloc(sizeof(struct Node));
    strcpy(Node_E->c_code, c[c_select]);
    strcpy(Node_E->courses, d[c_select]);
    Node_E->next = Node_head;
    Node_head = Node_E;
}

void insert_rear(int c_select) {
    struct Node *Node_E = (struct Node*)malloc(sizeof(struct Node));
    
    strcpy(Node_E->c_code, c[c_select]);
    strcpy(Node_E->courses, d[c_select]);

    Node_E->next = NULL;
    if (Node_head == NULL) {
        Node_head = Node_E;
        return;
    }
    struct Node *last = Node_head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = Node_E;
}

void print_cl() {
    struct Node *temp = Node_head;
    printf("Course List:\n");
    while (temp != NULL) {
        printf("%s - %s\n", temp->c_code, temp->courses);
        temp = temp->next;
    }
}

int course_check(int c_select) {
    struct Node *temp = Node_head;
    while (temp != NULL) {
        if (strcmp(temp->c_code, c[c_select]) == 0) {
            printf("course alreay added\n");
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}
