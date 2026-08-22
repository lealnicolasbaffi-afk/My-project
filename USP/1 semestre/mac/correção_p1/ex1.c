#include <stdio.h>
int SomaDivProp(int n){
    int i, soma = 0;
    for(i = 1; i < n; i++){
        if(n % i == 0){
            soma = soma + i;
        }}
        printf("%d\n", soma);
        return soma;
}
int main()
{
    int a;
    int b;
    int i;
    scanf("%d", &a);
    scanf("%d", &b);
    for(i = a; i < b; i++){
        if(i == SomaDivProp(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}
