#include <stdio.h>

int main(){

    int n;
    float harmonico = 0;
    
    printf("digite o valor de n\n");
    scanf("%d", &n);

    for(float i = 1; i <= n; i++)
    {
        harmonico = harmonico + 1/i;
    }
    printf("Hn = %f", harmonico);

    return 0;
}