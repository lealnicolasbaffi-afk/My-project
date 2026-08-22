#include <stdio.h>
#include <math.h>

int verificabissexto(int ano){

if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    return 1;
else 
    return 0;
}

int main(){
 int ano;
 printf("digite o ano\n");
 scanf("%d", &ano);
 int a = verificabissexto(ano);
 printf("%d", a);
 return 0;
}