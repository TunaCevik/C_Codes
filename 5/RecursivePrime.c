#include <stdio.h>

int isPrime(int A, int division);

int main()
{
    int x;
    int A;
    printf("please enter your number: ");
    scanf("%d",&x);
    A= isPrime(x,2);
    if(A == 1)
        printf("your number is prime");
    else
        printf("your number is not prime");

}

int isPrime(int A, int division)
{
    if(A % 2 == 0)
        return 0;
    if(A <=3)
        return 1;
    if(A % division == 0)
        return 0;
    if(division *division > A)
        return 1;

    return isPrime(A, division +1);
}