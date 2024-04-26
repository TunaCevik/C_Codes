#include <stdio.h>  
void changer(int b[], int c);
int main()
{
    unsigned long int a[20] = {0};
    unsigned long long int d[10];
    int K;
    int b=5;
    K=b;
    printf("b:%p K:%p\n",&b,&K);
    printf("b: %d K:%d\n",b,K);
    b=5;
    printf("b:%p K:%p\n",&b,&K);
    printf("b: %d K:%d\n",b,K);
    b=6;
    printf("b:%p K:%p\n",&b,&K);
    printf("b: %d K:%d\n",b,K);
    K=7;
    printf("b:%p K:%p\n",&b,&K); 
    printf("b: %d K:%d\n",b,K);  

    printf("a:%p\n",&a);     
    printf("a1:%p\n",&a[1]); 
    printf("a:%p\n",&a[2]);   
    // printf("%lu",sizeof(a[3]));
    printf("a1:%p d1:%p\n",&a[1],&d[1]);
    d[1]=a[1];
    printf("a1:%p d1:%p\n",&a[1],&d[1]);
    d[1]=7;
    printf("a1:%p d1:%p\n",&a[1],&d[1]);   


    return 0;
}
void changer(int b[], int c)
{
    
}