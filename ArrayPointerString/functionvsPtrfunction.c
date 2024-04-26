#include <stdio.h>

int main()
{
    char s1[] = "abcdef";
    s1[0] = 'X';
// s1++; is not possible
    printf("s1: %s\n", s1);
    
    char *s2 = "abcdef";

//    s2[0] = 'x'; s2 is pointer to first element of the string
// diffrent types

    s2++;
    printf("s2: %s\n",s2);





    return (1);
}