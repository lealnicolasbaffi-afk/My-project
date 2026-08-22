#include <stdio.h>

int main()
{
 int n;
 int numero;
 int i;
 int soma = 0;

 printf("digite o numero de sequencias que voce quer verifica:");
 scanf("%d", &n);

 for (i = 0; i < n; i++)
 { 
    scanf("%d", &numero);
    while( numero != 0)
    {
    if( numero % 2 ==0)
    {
        soma = soma + numero;
    }
    scanf("%d", &numero);
    }

 }
 printf("a soma dos numeros pares e: %d", soma);




}