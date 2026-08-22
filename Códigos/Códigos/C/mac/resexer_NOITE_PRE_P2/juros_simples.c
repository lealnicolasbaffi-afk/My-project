    #include <stdio.h>

    int main(){
    float investido,    //em complexos
          juros,        //em %
          montante;     //em complexos 
    int mes;

    scanf("%f", &investido);
    scanf("%f", &juros);
    
    juros = 1 + (juros/100); //transforma os juros em valor usável...
    montante = investido;
    
    for(mes = 1; mes <= 12; mes++){
    montante = montante * juros;    
    
    printf("mes %d: %f\n", mes, montante);
    
    }
    return 0;
    }