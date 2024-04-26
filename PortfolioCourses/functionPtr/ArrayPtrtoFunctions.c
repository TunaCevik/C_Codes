#include <stdio.h>

int add(int x, int y) {
    return x+y;
}
int subtraction(int x, int y) {
    return x-y;
}
int (*selection())(int, int) {
    
}
int main() 
{
    int (*function[2])(int, int) = {add, subtraction};  // Bu C'de doğrudan yapılamaz
    int product = (*function[1])(2,15);//int product = function[1](2,15);
    printf("%d", product);
    return 0;
}