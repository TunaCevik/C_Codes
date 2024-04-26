#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct{
    double data[MAXSIZE][MAXSIZE *2];
    int size;
    int IorC;
}KAREMATRIX;
void InverseInput(KAREMATRIX *m);
void CramerInput(KAREMATRIX *m);
void PivotingGaussJordan(KAREMATRIX *m);
void PrintingResults(const KAREMATRIX *m);
int main()
{
    int choice;
    char YorN;
    KAREMATRIX *M;
    do {
        printf("Which calculation dou you want to make \n1: Inverse\n2:");
        scanf(" %d",&choice);
        if(choice == 1)
        printf("Do you want to make new calculation \n(Y / N):");
        scanf(" %c", &YorN);
    }while(YorN == "Y" || YorN == "y");

    return 0;
}