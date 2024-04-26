#include <stdio.h>

int main()
{
    int static x = 1;
    printf("%d",x);
    x+=1;
    main();
    return 0;
}