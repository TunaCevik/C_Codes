#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int *myarr;
    myarr = (int *)malloc(sizeof(int) * 120);  // Casting malloc to (int *) for C++ compatibility
    for (int i = 0; i < 120; i++) {
        *(myarr + i) = i;
    }

    int prime[120];
    for (int i = 0; i < 120; i++) {
        prime[i] = 1;  // Assume all numbers are prime initially
    }
    prime[0] = prime[1] = 0;  // 0 and 1 are not primes

    for (int i = 2; i < 120; i++) {
        if (prime[i]) {  // Only check for primes
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    prime[i] = 0;  // Not a prime number
                    break;  // No need to check further
                }
            }
        }
    }

    for (size_t i = 2; i < 120; i++) {
        printf("%3zu: %d ", i, prime[i]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    free(myarr);
    return 0;
}
