#include <stdio.h>

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

    printf("digite seu numero n\n");
    scanf("%d", &n);

    int cont = calculalgarismos(&n);

    int primeiro = n;

    while(primeiro >= 10){
        primeiro /= 10;
    }

    printf("ha %d algarismos nesse numero e o primeiro algarismo e: %d\n",
           cont, primeiro);

    return 0;
}
