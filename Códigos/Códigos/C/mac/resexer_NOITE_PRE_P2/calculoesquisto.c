#include <stdio.h>

int main(){
    int n;
    float soma = 0;

    scanf("%d", &n);
    
    for(float i = 0; i <= (n-1); i++){
        soma = soma + (i+1)/(n-i);
    }

    printf("%f", soma);


}