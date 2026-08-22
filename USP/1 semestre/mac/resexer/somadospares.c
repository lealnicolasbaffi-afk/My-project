#include <stdio.h>
int main(){
    int n;
    int i;
    int numero;
    int soma=0;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);
    printf("digite uma sequencia de n numeros:\n");
i=1;
while(i<= n){
    scanf("%d", &numero);
        if (numero%2==0){
            soma=soma+numero;
        }
        i++;
    }
    printf("a soam dos n pares e:%d",soma);
return 0;
}