#include <stdio.h>


int main()
{

    int x = 4;
    int * pX = NULL;
    pX = &x;
    int y;
    y = *pX;
    
    printf("%s : %d, %s : %p","Value of the the y", y, "Adress of the y", &y);
    puts(" *");
    printf("Adress of px: %p value of px: %d",pX, *pX);
    return 0;
}