#include <stdio.h>
#include <stdlib.h>
#include "MatrixMultipilication.h"

int main()
{
    double matris1[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double matris2[6]= {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    
    double matris3[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double matris4[6] = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0};
    
    double *sonuc;
    sonuc = malloc(sizeof(double)*4);
    mat_vec_multiplication((double *)matris1, 2, 3, (double *)matris2, 3, 2, sonuc);

    for (int i = 0; i < 4; i++) printf("%.2f ", sonuc[i]);
    
    printf("\n");

    double *sonuc1;
    sonuc1 = malloc(sizeof(double) *6);
    mat_vec_addition((double *)matris1, 2, 3, (double *)matris2, 2, 3, sonuc1);

    for (int i = 0; i < 6; i++) printf("%.2f ", sonuc1[i]);
    
    printf("\n");
    free(sonuc1);
    mat_vec_subtraction((double *)matris3, 2, 3, (double *)matris4, 2, 3, sonuc1);

    for (int i = 0; i < 6; i++) 
        printf("%.2f ", sonuc1[i]);

    printf("\n");
    double sonuc2[6];
    matrix_transpose((double *)matris1, 2, 3, sonuc2);
    for (int i = 0; i < 6; i++) printf("%.2f ", sonuc2[i]);
             
    return 0;
}