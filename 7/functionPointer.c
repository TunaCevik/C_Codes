#include <stdio.h>

// Function 1: Adds two integers
int add(int x, int y) {
    return x + y;
}

// Function 2: Multiplies two integers
int multiply(int x, int y) {
    return x * y;
}
int main() {
    // Define a function pointer named 'operation'. It can point to any function that takes two ints and returns an int
    int (*operation)(int, int);

    int a = 5, b = 10;
    int result;

    // Point 'operation' to the 'add' function and call it
    operation = add;
    result = operation(a, b); // This calls 'add(a, b)'
    printf("Adding: %d\n", result);

    // Point 'operation' to the 'multiply' function and call it
    operation = multiply;
    result = operation(a, b); // This calls 'multiply(a, b)'
    printf("Multiplying: %d\n", result);

    return 0;
}
