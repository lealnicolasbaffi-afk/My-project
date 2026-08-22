#include <stdio.h>
#include <math.h>

int calculalgarismos(int *n){
    int cont = 0;
    int u = *n;

    while(u != 0){
        u /= 10;
        cont++;
    }

    return cont;
}

int main(){
    int n;
    int k;

    printf("quantos numeros tem a sequencia\n");
    scanf("%d", &k);

    for(int i = 1; i <= k; i++){
    
        printf("digite seu numero n\n");
        scanf("%d", &n);

        int cont = calculalgarismos(&n);

        int primeiro = n;

        while(primeiro >= 10){
        primeiro /= 10;
      }

        printf("ha %d algarismos no numero %d e o primeiro algarismo e: %d\n", cont, n, primeiro);
    }
    return 0;
}