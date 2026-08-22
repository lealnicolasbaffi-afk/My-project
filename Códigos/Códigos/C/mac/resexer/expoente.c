//calcula x elevado a n
#include <stdio.h>;

int main(){
int x; 
int n;
int i;
int resultado = 1;

scanf("%d", &x);
scanf("%d", &n);

for(i=0; i<n; i++){
    resultado = resultado*x;

}
printf("%d", resultado);
return 0;
}