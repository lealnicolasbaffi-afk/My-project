#include <stdio.h>

int main(){
float x, y;        //valores de xy do ponto dado
int n;             //numero de pontos
int raio = 1;      //valor da comparação do raio

scanf("%d", n);

for(int i = 1; i <= n; i++){
scanf("%f %f", &x, &y);

if(x >= 0 && y >= 0 && x*x + y*y <= 1 )
printf("o ponto (%d,%d) pertence ao coinjunto\n", x, y);
else
printf("o ponto (%d,%d) nao pertence ao coinjunto\n", x, y);
}
return 0;
}