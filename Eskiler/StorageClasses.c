#include <stdio.h>

 int y;

void myFunction() {
    static int x = 10; // Static olarak tanımlanan bir değişken
    y=x;
    printf("x adresi: %p\n", &x);
    x++;
}

int main() {
    myFunction();
    puts("");
    printf("%d",y);
    myFunction();

    printf("%d",y);
    puts("");
    printf("%p",&y);
    return 0;
}



