#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define EPSILON 1e-6  

#define IS 1e-12
#define VT 0.026
#define N 1

double FUNC(double ID, double x) {
    return (IS*(exp(x/VT)-1) - ID);
}


double bisection_method(
    double (*f)(double, double), 
    double xleft, 
    double xright, 
    const double ID, 
    double tol,
    int *counterSON
) {
    
    double mid, f_left, f_right, f_mid;

    f_left = f(ID,xleft);
    f_right = f(ID,xright);

    if (f_left * f_right >= 0) {
        printf("Belirtilen aralıkta kok yok veya tek bir kok yok.\n");
        return 0; 
    }
    int counter =0;
    while ((xright - xleft) / 2 > tol) {
        mid = (xleft + xright) / 2;
        f_mid = f(ID,mid);

        if (f_mid == 0) { 
            return mid;
        } else if (f_left * f_mid < 0) { 
            xright = mid;
            f_right = f_mid;
        } else { 
            xleft = mid;
            f_left = f_mid;
        }
    counter++;
    }
    *counterSON = counter;

    return (xleft + xright) / 2; 
}


int main()
{
    double ID, xleft= -1.0, xright=1.0;
    int *counter;
    double verification = FUNC(0.0105, 0.6);
    printf("For Verification: Is(0.6V) = %f\n", verification + 0.0105-0.000024);
    printf("What is the diode current? ");
    scanf(" %lf", &ID);

    double root = bisection_method(FUNC, xleft, xright, ID, EPSILON, counter);
    printf("Approximate root (diode voltage): %f\n",root);
    printf("Total Iterations = %d", *counter);



    

    return 0;
}