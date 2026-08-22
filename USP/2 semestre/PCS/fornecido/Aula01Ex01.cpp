#include <math.h>
#include <stdio.h>

int ganhaExperiencia(int nivel, int experienciaAtual, int nivelDoMonstro){
    int experienciaGanha = 0;
    int experienciaParaProximoNivel = 150 * pow(1.5, nivel - 1);
    if(nivelDoMonstro >= 1 && nivelDoMonstro <= 5){
        experienciaGanha = 100;
    } else if(nivelDoMonstro >= 6 && nivelDoMonstro <= 10){
        experienciaGanha = 750;
    } else if(nivelDoMonstro >= 11 && nivelDoMonstro <= 15){
        experienciaGanha = 5000;
    } else if(nivelDoMonstro >= 16 && nivelDoMonstro <= 20){
        experienciaGanha = 15000;
    } 
    if(experienciaAtual + experienciaGanha >= experienciaParaProximoNivel){
      nivel++;
    }
    if(nivel > 20){
        nivel = 20;
    }
    return nivel;
}

int main(){
    int nivel = 1;
    int experienciaAtual = 0;
    int nivelDoMonstro = 10;
    scanf("%d %d %d", &nivel, &experienciaAtual, &nivelDoMonstro);
    nivel = ganhaExperiencia(nivel, experienciaAtual, nivelDoMonstro);//
    printf("Novo nivel: %d\n", nivel);                                  
    return 0;
}