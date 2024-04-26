#include <stdio.h>

int main() {
    int array[5];
    array[2] =5;
    //pointer to the first element of the array
    printf(" array: %5zu\n", array);
    printf(" array: %5zu\n", array+1);

    //& array pointer to entire array
    printf("&array: %5zu\n", &array);
    printf("&array + 1: %5zu\n\n", &array + 1);
    //plus 20
    int matrix[3][5] = 
    {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14}
    };
    //pointer to first element
    printf("     matrix[1]: %zu\n", matrix[1]);
    printf("    matrix[1]+1: %zu\n", matrix[1]+1);
    printf("  *(matrix[1]+1): %zu\n\n\n",*(matrix[1]+1));

    //pointer to entire array
    printf("    &matrix[1]: %zu\n",&matrix[1]);
    printf("&matrix[1]+1: %zu\n",&matrix[1]+1);
    //pointer to the array of 5 ints
    printf("*(&matrix[1]+1):%zu\n",*(&matrix[1]+1));
    printf("*(*(&matrix[1]+1)):%zu\n\n\n",*(*(&matrix[1]+1)));

    //  pointer to the int; pointer to the array of 5 ints
    //    int *pointer= &matrix[1]+1;
    // pointer arithmetic first do (int *) (&matrix[1]) so pointed to 6
    int *pointerD = (int *) &matrix[1] +1;
    int *pointer = (int *) (&matrix[1] + 1);
    printf("pointer: %zu\n", pointer);
    printf("*pointer: %zu\n", *pointer);
    printf("pointer1: %zu\n", pointerD);
    printf("*pointer1: %zu\n", *pointerD);




    return 0;
}
