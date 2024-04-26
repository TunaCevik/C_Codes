#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 20;

    // Constant pointer to an integer
    const int *ptr1 = &num1;

    // Attempting to modify the value pointed to by ptr1 will result in a compilation error
    // *ptr1 = 15; // Error: assignment of read-only location

    // However, the pointer itself can be changed to point to a different memory location
    ptr1 = &num2;

    // Constant pointer to an integer
    int * const ptr2 = &num1;

    // The value pointed to by ptr2 can be modified
    *ptr2 = 15;

    // Attempting to change the memory location pointed to by ptr2 will result in a compilation error
    // ptr2 = &num2; // Error: assignment of read-only variable 'ptr2'

    return 0;
}
