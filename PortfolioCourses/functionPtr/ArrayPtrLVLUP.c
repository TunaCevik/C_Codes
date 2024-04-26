#include <stdio.h>

int add(int x, int y) {
    return x+y;
}
int subtraction(int x, int y) {
    return x-y;
}
int (*selection())(int, int) {
    int option = 0;
    printf("Select an operation\n");
    printf("1: Add\n");
    printf("2: SUbstract\n");
    scanf(" %d", &option);
    if(option ==1) return add;
    else if(option == 2) return subtraction;
    else return NULL;
}
int main() 
{
    int (*function)(int, int) = selection();  // Bu C'de doğrudan yapılamaz
    int product = (*function)(2,15);//int product = function[1](2,15);
    printf("%d", product);
    return 0;
}