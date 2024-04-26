#include <stdio.h>

int main() {
    int b[] = {10, 20, 30, 40};
    char a[] = "allah";
    char *my = a;
    int *myA = b;
    printf("%c", *(my+1));
    printf("%d", myA[1]);
    return 0;
}
