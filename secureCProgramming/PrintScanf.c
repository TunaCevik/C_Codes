#include <stdio.h>

int main() {
    char name[50];
    printf("Enter your name: ");
    // scanf_s kullanımında buffer boyutu argüman olarak eklenmelidir.
    scanf_s("%49s", name,  (unsigned)sizeof(name));
    // sizeof(name)/sizeof(name[0]) bu da kulllanılabililir
    printf_s("Hello, %s!\n", name);
    return 0;
}
