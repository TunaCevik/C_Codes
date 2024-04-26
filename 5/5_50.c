#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int Checker(int ,int, int, int);
void TebrikVazgecirmeme(int);

void main(void)
{
    srand(time(NULL));
    int a, b, dortIslem, cheAgiden, SonucKontrol, DOGRU;

    while(1)
    {
        
        a= rand() % 20;
        b= rand() % 20;
        
        dortIslem = rand() % 4;


        switch(dortIslem)
        {
            case 0:
                do{
                    printf("%d * %d = ?", a ,b);
                    scanf("%d",&cheAgiden);
                    SonucKontrol = Checker(a, b, cheAgiden, '*');
                    TebrikVazgecirmeme(SonucKontrol);
                }
                while(SonucKontrol !=1);
                break;
            case 1:
                do{
                    printf("%d / %d = ?", a ,b);
                    scanf("%d",&cheAgiden);
                    SonucKontrol = Checker(a, b, cheAgiden, '/'); 
                    TebrikVazgecirmeme(SonucKontrol);                    
                }
                while(SonucKontrol !=1);
                break;
            case 2:              
                do{
                    printf("%d + %d = ?", a ,b);
                    scanf("%d",&cheAgiden);
                    SonucKontrol = Checker(a, b, cheAgiden, '+');
                    TebrikVazgecirmeme(SonucKontrol);
                }
                while(SonucKontrol !=1);
                break;
            case 3:
                do{
                    printf("%d - %d = ?", a ,b);
                    scanf("%d",&cheAgiden);
                    SonucKontrol = Checker(a, b, cheAgiden, '-');
                    TebrikVazgecirmeme(SonucKontrol);
                }
                while(SonucKontrol != 1);
                break;            

        }
        

        
    }

}
int Checker(int A, int B, int sonuc, int C)
{
    int REnumber;
    if(C == 42){
        if(A*B == sonuc)
            return 1;
        else 
           printf("%d * %d = ?", A ,B);
    }
    if(C==47){
        if(A/B == sonuc)
            return 1;
        else return 0;
    }
    if(C==43){
        if(A+B == sonuc)
            return 1;
        else return 0;
    }    
    if(C==45){
        if(A-B == sonuc)
            return 1;
        else return 0;
    }
   
}
void TebrikVazgecirmeme(int SsS)
{
    int a= rand() % 4;
    if(SsS == 1){
        if(a == 0)puts("Good job");
        else if(a == 1)puts("Excellent");
        else if(a== 2)puts("Nice work");
        else puts("Very good");
    }
    else{
        if(a == 0)puts("No. Please try again");
        else if(a == 1)puts("Wrong. Try once more.");
        else if(a== 2)puts("Don't give up!");
        else puts("No. Keep trying.");
    }

}