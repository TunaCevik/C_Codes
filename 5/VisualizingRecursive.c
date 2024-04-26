#include <stdio.h>

long factorial(int n, int level) {
    // Print the current level and value
    for (int i = 0; i < level; i++) {
        printf("  ");  // Two spaces for each level of indentation
    }
    printf("factorial(%d)\n", n);

    // Base case
    if (n <= 1) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("Returning 1\n");
        return 1;
    } else {
        // Recursive case
        long result = n * factorial(n - 1, level + 1);
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("Returning %ld\n", result);
        return result;
    }
}

int main() {
    int number = 5;
    printf("Factorial of %d:\n", number);
    long fact = factorial(number, 0);
    printf("Result: %ld\n", fact);
    return 0;
}
