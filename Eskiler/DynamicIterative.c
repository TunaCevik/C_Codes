#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Dinamik Programlama
int fibonacci(int n) {
    int fib[n+2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}
