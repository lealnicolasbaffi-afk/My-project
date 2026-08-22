#include <stdio.h>

int main(){
    int i;
    int j;
    int ij;
    int n;
    int k;
  
    printf("digite quantos multiplos de i,j e ij voce quer:");
    scanf("%d", &n);
    printf("digite o valor de i:");
    scanf("%d", &i);
    printf("digite o valor de j:");
    scanf("%d", &j);
    ij=i*j;
    for(k=1; k<=n; k++){
        i=i*k;
        j=j*k;
        ij=ij*k;
        if(i<=j){
            printf("%d\n",i);
            printf("%d\n",j);
            printf("%d\n",ij);
        }
        else{
            printf("%d\n",j);
            printf("%d\n",i);
            printf("%d\n",ij);
        }

    }



return 0;
}














