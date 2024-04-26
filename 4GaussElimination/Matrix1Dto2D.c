#include <stdio.h>
#include <math.h>

#define A(I, J) (a[(I) * n + (J)])



int main()
{
    // Örnek kullanım
    double matris[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    double vektor[3] = {1.0, 2.0, 3.0};
    double sayı = 1.00;

    double *ptr =  &matris[0][0];
    //double *ptr =  (*double)matris;
    double *Mtr = &vektor[0];
    //double *Mtr = (*double)vektor;
    //double *Mtr = vektor;
    double *SayıPrt = &sayı;

    printf("%f", ptr[3]);
    printf("%f", Mtr[0]);
    printf("\n%f", *SayıPrt);

    return 0;
}
#undef A