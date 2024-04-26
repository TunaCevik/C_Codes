#include <stdio.h>
#include <math.h>

#define A(I, J) (a[(I) * n + (J)])

void mat_vec_mult(
    double *a,
    double b[],
    double c[],
    int m,
    int n
){
    double sum = 0.0;
    int i,j;
    for(i = 0; i<m; i++){
        sum = 0.0; // sum'u her satırın başında sıfırlamak gerekir
        for(j = 0; j<n; j++){
            sum = sum + A(i,j) * b[j];
        }
        c[i] = sum;
    }
}


int main()
{
    // Örnek kullanım
    double matris[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    double vektor[3] = {1.0, 2.0, 3.0};
    double sonuc[2];

    mat_vec_mult((double *)matris, vektor, sonuc, 2, 3);

    // Sonucu yazdırma
    printf("Sonuc: \n");
    for (int i = 0; i < 2; i++) {
        printf("%.2f ", sonuc[i]);
    }
    printf("\n");

    return 0;
}
#undef A