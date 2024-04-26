#include <stdio.h>

int main() {
    char *my = "allah";
    int *myA = {10, 20, 30, 40};
    printf("%c", *(my+1));
    printf("%d", myA[1]);
    return 0;
}
