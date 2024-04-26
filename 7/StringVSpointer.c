#include <stdio.h>

int main()
{
    char s1[] = "abcdef";

    s1[0] = 'x';
    // s1++ you cant write this 
    printf("s1: %s\n", s1);

    const char * s2 = "abcdef";
    // you cant modify this s2[0] = 'X'

    s2++;
    printf("s2: %s\n", s2);


    // s1 = "newstr"; 
    s2 = "new string";
   printf("s2: %s", s2);    


    int b[5];
    int *bPtr;
    bPtr = b;

    return 0;
}