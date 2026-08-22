#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
 int x,cont = 0, maior = 0;
 while ( scanf("%d", &x) != EOF)
 {
    if (x > maior)
    {
        maior = x;
        cont ++;
    }
 }
 printf("O maior numero e: %d\n", maior);
 printf("O numero de vezes que o maior numero apareceu e: %d\n", cont);
    return 0;
}