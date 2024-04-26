#include <stdio.h>
#include <math.h>
#include <errno.h>

int main()
{
    double x,y,z;
    errno = 0;

    x= 5000.0;
    y=100.0;
    z=pow(x,y);
    if(errno == EDOM)
        printf("Domain error in computing %lf to the %lf\n"
        ,x,y);

    else if (errno == ERANGE)
        printf("Range error in computing %lf to the %lf\n"
        ,x, y);

    printf("%lf",z);

    return 0;

}