#include <stdio.h>

void main(void)
{
    const int DEC;
    printf("%s","Please enter your encrypting data");
    puts("");
    scanf("%d",&DEC);

    int a=0;
    while((1000)*a < DEC){
        a+=1;
    }
    a-=1;
    int b =0;
    while((100)*b < DEC - ((1000)*a)){
        b+=1;}
    b-=1;
    int c =0;
    while((10)*c < DEC - (1000*a + 100*b)){
        c+=1;}
    c-=1;
    int d = 0;
    while (d < DEC - (1000*a + 100*b+ 10*c))
    {
        d+=1;
    }
    d-=1;
    int a1, b1, c1, d1;

    a1 = (c+7)%10;
    b1 = (b+7)%10;
    c1 = (a+7)%10;
    d1 = (d+7)%10; 

    int ENC;
    ENC = 1000*a1 + 100*b1 + 10*c1 + d;

    printf("BAS: %d  SON: %d",DEC,ENC);



}