#include <stdio.h>
const char * method();
char *method2();

int main()
{
    const char *str1= method();
    printf("str1: %s\n", str1);
    char *str2 = method2();
    printf("str2: %s\n", str2);

    //returning string s cannot be modified
    return 0;
}

const char * method(){
    return "string";
}
char *method2(){
    char try[] = "try";

    return try;
}