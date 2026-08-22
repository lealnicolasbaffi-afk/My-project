#include <stdio.h>

int main(){
int i;
int n;
int nota;
int notamenor=100;
int notamaior=0;
printf("digite a quantidade de alunos:");
scanf("%d", &n);

for(i=0; i<n; i++){
    printf("digite a nota do aluno:");
    scanf("%d", &nota);
   if (nota<notamenor){
    notamenor=nota;
   }
   if (nota>notamaior){
    notamaior=nota;}

   }
   printf("a menor nota e %d\n", notamenor);
   printf("a maior nota e %d\n", notamaior);




return 0;
}