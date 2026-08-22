//verifica se um numero é primo

#include <stdio.h>

int main()
{
int i;
int n;

printf("digite um numero:\n");
scanf("%d", &n);

for(i = 2; i < n; i++)
{
if( n % i == 0 )
{
printf("o numero nao e primo");
break;
}
}
if ( i== n)
{
    printf("o numero e primo");
}
 return 0;
}