#include <stdio.h>

int main(){
    float prod = 0;
    float x[3];
    float y[3];

    for(int i = 0; i < 3; i++)
    scanf("%f", x[i]);

    for(int i = 0; i < 3; i++)
    scanf("%f", y[i]);

    for(int i = 0; i < 3; i++)
    prod = prod + x[i]*y[i];

    printf("%d", prod);
}