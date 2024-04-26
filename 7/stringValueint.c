#include <stdio.h>

void printfCharactes(const char *sPtr);
void printfValues(const int *vPtr);

int main()
{
    char string[] = "print charactes of string";
    printfCharactes(string);
    int values[] = {1,2,3,4,5};
    printfValues(values);
    puts("--");
    int v[5] = {1,2,3,4,5};
    int *vPtr;

    vPtr = v; // diziye eşitledik şu an dizi gibi davranıyor
    printf("%d", vPtr[1]);

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

   //******************************************/

    return 0;
}

void printfCharactes(const char *sPtr)
{
    for(; *sPtr != '\0'; sPtr++)
        printf("%c",*sPtr);
}
void printfValues(const int *vPtr)
{
    for(; *vPtr != '\0'; vPtr++)
        printf(" %d", *vPtr * 2);
}
