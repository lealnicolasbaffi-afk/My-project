/* Dizemos que um número natural é triangular se ele é produto de três números naturais consecutivos.

Exemplo: 120 é triangular, pois 4.5.6 = 120.

Dado um inteiro não-negativo n, verificar se n é triangular. */
#include <stdio.h>

int main()
{
int n;
int i;

printf("digite um numero:\n");
scanf("%d", &n);
for( i = 0; i<= n; i++){
if(i*(i+1)*(i+2) == n)
{
    printf(" o numero %d e triangular", n);
    break;
}
}
if(i > n)
{
    printf(" o numero %d nao e triangular", n);
}
    return 0;
}