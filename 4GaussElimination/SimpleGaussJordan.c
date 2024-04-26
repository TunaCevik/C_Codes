#include <stdio.h>
#include <math.h>

#define A(I, J) (*(a + (I)*n + (J))) // Katsayılar matrisine erişim
#define WORK(I, J) (*(work + (I)*(n+1) + (J))) // Çalışma matrisine (genişletilmiş matris) erişim

void simple_gauss(
    double *a, // Katsayılar matrisi
    double b[], // Sağ taraf vektörü
    double *work, // Çalışma matrisi
    double x[], // Çözümler dizisi
    int n // Denklem sayısı
) {
    double m;
    int i, j, k;
    // Çalışma matrisini kur
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            WORK(i, j) = A(i, j);
        }
        WORK(i, n) = b[i];
    }
    // Satırlar arasında döngü
    for (i = 0; i < n; i++) {
        // Eleme işlemini gerçekleştir
        for (j = 0; j < n; j++) {
            if (j != i) {
                m = WORK(j, i) / WORK(i, i);
                for (k = i; k <= n; k++) {
                    WORK(j, k) -= m * WORK(i, k);
                }
            }
        }
    }
    // Çözümü hesapla (sağ taraf bölü diyagonal)
    for (i = 0; i < n; i++) {
        x[i] = WORK(i, n) / WORK(i, i);
    }
}

int main() {
    double coeff[3][3] = {{2, 3, 5}, {1, 2, 4}, {4, 7, 3}}; // Katsayılar matrisi
    double rhs[3] = {10, 5, 15}; // Sağ taraf vektörü
    double place[3][4]; // Çalışma (genişletilmiş) matrisi
    double answer[3]; // Çözümler dizisi
    simple_gauss((double *)coeff, rhs, (double *)place, answer, 3); // Gauss eleme işlevini çağır
    printf("Solution is: %f %f %f\n", answer[0], answer[1], answer[2]); // Çözümleri yazdır
    return 0;
}
