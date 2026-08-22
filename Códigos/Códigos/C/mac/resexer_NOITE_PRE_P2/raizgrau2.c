#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c;
    float determinante;
    float raizunica;
    float raiz1, raiz2;
    float real, comp;

    printf("digite os coeficientes a,b,c, respectivamente...\n");
    scanf("%f %f %f", &a, &b, &c);

    determinante = b*b - 4*a*c;

    printf("determinante = %f\n", determinante);

    if(determinante = 0){
        raizunica = -(b/(2*a));
        printf("a raiz unica e: %f", raizunica);
    }

    else if(determinante > 0){
        raiz1 = (-b - sqrt(determinante))/(2*a);
        raiz1 = (-b + sqrt(determinante))/(2*a);
    
        printf("raiz1: %f\n", raiz1);
        printf("raiz2: %f\n", raiz2);
    }

    else{
        real = -b /(2*a);
        comp = sqrt(-determinante)/(2*a);

        printf("raiz1: %f - %fi\n", real, comp);
        printf("raiz1: %f + %fi\n", real, comp);

    }

}