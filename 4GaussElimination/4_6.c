#include <stdio.h>

double sum_vals(
    double *m,
    int nrows,
    int ncols
){
    int i,j;
    double sum = 0.0;
    for(i = 0; i<nrows; i++){
        for(j = 0; j<ncols; j++){
            sum += *(m + i*ncols + j);

        }
    }
    return (sum);
}
int main()
{
    double array[2][2] = {{1.00, 2.00}, {1.00, 2.00}};
    double *pointer = (double *) &array[0];
    printf("%lf", sum_vals(pointer, 2, 2));
    return 0;
}