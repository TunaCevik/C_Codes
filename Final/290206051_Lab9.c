#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    //matrix' in Row sayısı;
    int Matrix_R;
    //matrix' in Column sayısı;
    int Matrix_C;
    //2D matrix in elemenlarını içerir
    double *matrixunits;
    // LinkedList için sıradaki node' u tutar
    struct Node* next;
} Node;

typedef struct  {
    //Stackin içinde kaç Node oluğunu söyler
    int MatrixSC;
    //double* matrixS' te olabilecek Max kapasiteyi belirtir (Node olarak)
    int Stack_Capacity;
    //Nodeları dizi gibi sırayla tutar
    Node *matrixS;
} Stack;

typedef struct {
    //linkedListe kaç elemena oluduğunu söyler
    int MatrixLC;
    //Head Node' u tutar
    Node *head;
    //Tail Node' u tutar
    Node *tail;
} LinkedListQ;


Node *CreateNode();
Stack *CreateStack(int StackCapacity);
LinkedListQ *CreateLinkedListQ();

//Public Function
void Menu();
void print2DArrayAs1D(double *array, int rows, int cols);
void freeNode(Node* node);
/*---------------------------------------------------*/

//Stack Function
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool push(Stack *stack, Node *node);
bool pop(Stack *stack, Node *node);
bool peek(Stack *stack, Node *node);
void destroy_stack(Stack *stack);
void printfMatrix_Stack(Stack *stack);
void MenuStack();

/*---------------------------------------------------*/

//LinkedList Function Q
int size_Link(LinkedListQ *queue);
bool is_empty_Link(LinkedListQ *queue);
double  *peek_Link(LinkedListQ *queue, bool *status);
void enqueue_Link(LinkedListQ *queue, Node *node);
double *dequeue_Link(LinkedListQ *queue, bool *status);
void destroy_queue_Link(LinkedListQ *queue);
void printfMatrix_LinkedList(LinkedListQ *linkedlistq);
void MenuLinkedListQ();

/*---------------------------------------------------*/

int main()
{  
    LinkedListQ *LLQ = CreateLinkedListQ();
    Stack *STACK = CreateStack(5);
    int choices;
    int choicesMain;
    Node *NODEX = NULL;
    bool *status = false;
    double *matrix = (double *)malloc(sizeof(double) * 4);
    do{
        Menu();
        puts("Please enter which action you want to take");
        scanf("%d",&choicesMain);
        switch (choicesMain)
        {
        case 0:
            destroy_queue_Link(LLQ);
            destroy_stack(STACK);
            break;
        //Showing Matrix
        case 1: 
        {
            
                puts("1. printfMatrix_Stack");
                puts("2. printfMatrix_LinkedList");
                scanf("%d",&choices);
                switch (choices)
                {
                case 1:
                    printfMatrix_Stack(STACK);
                    break;
                case 2:
                    printfMatrix_LinkedList(LLQ);
                    break;
                default:
                    break;
                }
            break;
        }
        //Stack
        case 2:
        {   
           
            do{
                MenuStack();
                puts("Please enter which action you want to take");     
                scanf("%d",&choices);
                switch (choices)
                {
                case 0:
                    puts("Exiting Stack Menu");
                    break;
                //Push
                case 1:
                    NODEX = CreateNode();
                    if(push(STACK, NODEX)) puts("Pushed Sucessfully");
                    break;
                //Pop
                case 2:
                    if(pop(STACK, NODEX)) puts("Poped Sucessfully");
                    break;
                //Peek
                case 3:
                    if(peek(STACK, NODEX)) {
                    matrix = NODEX->matrixunits; 
                    print2DArrayAs1D(matrix, NODEX->Matrix_R, NODEX->Matrix_C);
                } 
                    break;
                default:
                    break;
                }  

            
            }while(choices != 0);
            freeNode(NODEX);   
            break;
        }
        //Linked List
        case 3:
        {
            
            do{
                puts("Please enter which action you want to take");     
                scanf("%d",&choices);
                switch (choices)
                {
                case 0:
                    puts("Exiting Linked List Menu");
                    break;
                //Enqueue
                case 1:
                    NODEX = CreateNode();
                    enqueue_Link(LLQ, NODEX);
                    puts("Enqueue is done");                      
                    break;
                //Dequeue
                case 2:
                    matrix = dequeue_Link(LLQ, status);
                    puts("Dequeue is done \nDequeued Matrix: ");
                    print2DArrayAs1D(matrix, NODEX->Matrix_R, NODEX->Matrix_C);
                    break;
                //Peek
                case 3:
                    matrix = peek_Link(LLQ, status);
                    print2DArrayAs1D(matrix, NODEX->Matrix_R, NODEX->Matrix_C);
                    break;
                default:
                    break;
                } 

            }while(choices != 0);
            freeNode(NODEX);
            break;
        }
        //Matrix Calculations
        case 4:

            break;
        default:
            break;
        }
    free(matrix);
    }while(choicesMain != 0);

    
    return 0;
}

Node *CreateNode() {
    int MatrixR, MatrixC;
    puts("Please enter your matrix Row");
    scanf("%d",&MatrixR);
    puts("Plase enter your matrix Column");
    scanf("%d",&MatrixC);

    Node *Matrix_Node = malloc(sizeof(Node));
    if(Matrix_Node == NULL) return NULL;

    Matrix_Node->matrixunits = malloc(sizeof(double) * MatrixC * MatrixR);
    if(Matrix_Node->matrixunits == NULL) {
        free(Matrix_Node);
        return NULL;
    }

    Matrix_Node->Matrix_C = MatrixC;
    Matrix_Node->Matrix_R = MatrixR;
    Matrix_Node->next = NULL;


    return Matrix_Node;
} 
Stack *CreateStack(int StackCapacity) {
    if(StackCapacity == 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->matrixS = malloc(sizeof(Node) * StackCapacity);
    if(stack->matrixS == NULL) {
        free(stack);
        return NULL;
    }
    stack->Stack_Capacity = StackCapacity;
    stack->MatrixSC = 0;

    return stack;
}
LinkedListQ *CreateLinkedListQ() {
    LinkedListQ *linkedlist = malloc(sizeof(LinkedListQ));
    if(linkedlist == NULL) return NULL;

    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->MatrixLC = 0;

    return linkedlist;
}

//StackFunctions

bool is_full(Stack *stack) {
    return stack->Stack_Capacity == stack->MatrixSC;
}
bool is_empty(Stack *stack) {
    return stack->MatrixSC == 0;
}
bool push(Stack *stack, Node *node) {
    bool is_full(Stack *stack);
    if(is_full(stack)) return false;
    
    stack->matrixS[stack->MatrixSC] = *node;
    stack->MatrixSC++;

    return true;
}
bool pop(Stack *stack, Node *node) {
    bool is_empty(Stack *stack);
    if(is_empty(stack)) return false;

    stack->MatrixSC--;

    *node = stack->matrixS[stack->MatrixSC];

    return true;

}
bool peek(Stack *stack, Node *node) {
    bool is_empty(Stack *stack);
    if (is_empty(stack)) return false;
  
    *node = stack->matrixS[stack->MatrixSC - 1];

    return true;
}
void destroy_stack(Stack *stack)
{
  free(stack->matrixS);
  free(stack);
}
void printfMatrix_Stack(Stack *stack) {
    if (stack == NULL || stack->MatrixSC == 0) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contains %d matrices:\n", stack->MatrixSC);
    for (int i = 0; i < stack->MatrixSC; i++) {
        Node current = stack->matrixS[i];
        printf("Matrix %d (%d x %d):\n", i + 1, current.Matrix_R, current.Matrix_C);
        for (int row = 0; row < current.Matrix_R; row++) {
            for (int col = 0; col < current.Matrix_C; col++) {
                printf("%8.2f ", current.matrixunits[row * current.Matrix_C + col]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void MenuStack() {
    puts("0. Exit");
    puts("1. Push");   
    puts("2. Pop");
    puts("3. Peek");
}
//LinkedListQ

int size_Link(LinkedListQ *queue) {
    return queue->MatrixLC;
}
bool is_empty_Link(LinkedListQ *queue) {
    return queue->MatrixLC == 0;
}
double  *peek_Link(LinkedListQ *queue, bool *status) {
    bool is_empty_Link(LinkedListQ *queue);
    if((is_empty_Link(queue))) {
        *status = false;
        return NULL;
    }
    *status = true;

    return queue->head->matrixunits;
}
void enqueue_Link(LinkedListQ *queue, Node *node) {
    bool is_empty_Link(LinkedListQ *queue);

    Node *newNode = malloc(sizeof(Node));
    
    newNode = node;

    newNode->next = NULL;

    if(is_empty_Link(queue)) {
        queue->head = newNode; 
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->MatrixLC++;
}
double *dequeue_Link(LinkedListQ *queue, bool *status) {
    bool is_empty_Link(LinkedListQ *queue);
    if(is_empty_Link(queue)) {
        *status = false;
        return NULL;
    }

    *status = true;

    double *value = queue->head->matrixunits;

    Node *oldhead = queue->head;

    if(queue->MatrixLC == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else {
        queue->head = queue->head->next;
    }

    free(oldhead);

    queue->MatrixLC--;

    return value;
}
void destroy_queue_Link(LinkedListQ *queue) {
    Node *currentNode = queue->head;
    Node *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode->matrixunits);
        free(currentNode);
        currentNode = nextNode;
    }

    free(queue);
}
void printfMatrix_LinkedList(LinkedListQ *linkedlistq) {
    if (linkedlistq == NULL || linkedlistq->head == NULL) {
        printf("LinkedList is empty.\n");
        return;
    }

    int count = 1;
    Node *currentNode = linkedlistq->head;
    printf("LinkedList contains %d matrices:\n", linkedlistq->MatrixLC);
    while (currentNode != NULL) {
        printf("Matrix %d (%d x %d):\n", count, currentNode->Matrix_R, currentNode->Matrix_C);
        for (int row = 0; row < currentNode->Matrix_R; row++) {
            for (int col = 0; col < currentNode->Matrix_C; col++) {
                printf("%8.2f ", currentNode->matrixunits[row * currentNode->Matrix_C + col]);
            }
            printf("\n");
        }
        printf("\n");
        currentNode = currentNode->next;
        count++;
    }
}
void MenuLinkedListQ() {
    puts("0. Exit");
    puts("1. Enqueue");   
    puts("2. Dequeue");
    puts("3. Peek");
}
//Public Functions

void Menu() {
    puts("0. Exit and free all stack & linkedlist");
    puts("1. Showing Matrixs");   
    puts("2. (Stack) Push & Pop & Peek");
    puts("3. (Linked List) Enqueue & Dequeue & Peek");
    puts("4. Matrix Calculations");
}
void freeNode(Node* node) {
    if (node == NULL) return;

    // İlk olarak matris elemanlarını tutan dizi serbest bırakılır
    free(node->matrixunits);

    // Node yapı türünün kendisini serbest bırak
    free(node);
}
void print2DArrayAs1D(double *array, int rows, int cols) {
    if (array == NULL) {
        printf("Array pointer is NULL.\n");
        return;
    }

    printf("Printing 2D array stored in 1D format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", array[i * cols + j]);
        }
        printf("\n");
    }
}
