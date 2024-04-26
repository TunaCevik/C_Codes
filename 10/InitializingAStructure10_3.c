#include <stdio.h>
typedef struct 
{
    int x;
    int y;
}Point;


int main()
{
    Point pointX = {5, 10};
    printf("pointX.x: %d, pointX.y: %d",pointX.x,pointX.y );
    
}