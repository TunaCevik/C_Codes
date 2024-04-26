#include <stdio.h>

int main()
{
    struct node{
        int data;
        struct node *link;
    };
    struct node a;
    a.data = 3;
    a.link = NULL;
    struct node b;
    b.data = 5;
    b.link = NULL;
    a.link = &b;
    printf("%d\n", a.data);
    printf("%d", a.link -> data);

    return 0;
}