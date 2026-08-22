#include <stdio.h>

void troca(int *p,int *q)
{
int tmp = *p;
*p = *q;
*q = tmp;
}


int main(int argc, char *argv)
{
 int a = 2;
 int b = 3;

 troca(&a, &b);

 printf("a=%d \nb=%d", a, b);
return 0;
}