#include <stdio.h>

int main()
{
    int myarr[] = {1, 2, 3, 4, 5};
    printf("%p\n",myarr);
    printf("%d\n", *myarr); //myarr = &myarr[0] it is adress
    printf("%d\n",*&myarr[1]);

    /*
    myarr
    [1,2,3,4,5]
    myarr + (index)*sizeof(int) this is a adress


        a[i]
                *(a+i)
        i[a] 
    */
    printf("%d\n", 3[myarr]);
    printf("%p",3);

    return 0;
}