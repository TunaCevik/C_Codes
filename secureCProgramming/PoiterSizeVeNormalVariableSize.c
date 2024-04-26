#include <stdio.h>

int main() {
    int arr[10]; // 10 elemanlı int türünden bir dizi
    int *ptr = arr; // Diziye bir pointer

    printf("Dizinin boyutu: %lu\n", sizeof(arr));
    printf("Pointer'in boyutu: %lu\n", sizeof(ptr));

    return 0;
}
