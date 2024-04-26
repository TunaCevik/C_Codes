#include <stdio.h>

void function(int x) {
    printf("x: %d\n",x);
}
double add(double x, double y) {
    return x+y;
}
int main() 
{
    void (*function_pointer)(int);
    function_pointer = &function;
    (*function_pointer)(4); // function_pointer(4) de geçerli
    return 0;
}