#include <stdio.h>

double add(double x, double y) {
    return x+y;
}
int main() 
{
    double (*add_pointer)(double, double);
   add_pointer = add;
   double result;
   result = add_pointer(50.0, 30.0);
   printf("%lf",result);
    return 0;
}