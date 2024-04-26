#include <stdio.h>
#define M(I, J) (*(m + (I)*ncols + (J)))

double sum_vals(
    double *m,
    int nrows,
    int ncols
){
    int i,j;
    double sum = 0.0;
    for(i = 0; i<nrows; i++){
        for(j = 0; j<ncols; j++){
            sum += M(i, j);

        }
    }
    return (sum);
}

int main()
{
    double Matrix[12] = {1.0, 2.0, 3.0 ,4.0 ,5.0 ,6.0 ,7.0 ,8.0 ,9.0, 10.0, 11.0, 12.0};
    double a = sum_vals(Matrix, 4, 3);
    printf("%f", a);
    return 0;
}
#undef M