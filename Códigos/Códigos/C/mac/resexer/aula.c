#include <stdio.h>

int main() 
{
 int m;
 int n;
 int x;
 int y;
 int maximo;
 int valorexpressao;
 int i;
 int j;

    printf("digite o valor de m:");
    scanf("%d", &m);
    printf("digite o valor de n:");
    scanf("%d", &n);

   maximo = 0;

    for(x=0; x <= m; x++)
    {
        for(y=0; y<= n; y++)
        {
        valorexpressao = x*y - x*x + y;
        if(valorexpressao > maximo)
        { 
           maximo = valorexpressao; 
        }
        }
    }
   printf("o valor maximo e: %d", maximo);
   
    return 0;
}