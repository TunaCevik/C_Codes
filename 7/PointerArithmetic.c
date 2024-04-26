
#include <stdio.h>




int main(void)
{
    int v[5] = {1,2,3,4,5};

    int * vPtr = v;

    int *bPtr;



    vPtr+=3;
    bPtr= vPtr;
    printf("%d", vPtr);
    printf("%d", bPtr);    



    return 0;      
} 






