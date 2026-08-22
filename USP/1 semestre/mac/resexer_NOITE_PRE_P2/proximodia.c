#include <stdio.h>

int verificabissexto(int ano){
    if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
        return 1;
    else 
        return 0;
}

int verificaultimodia(int mes, int ano){
    if(mes % 2 == 1)
        return 31;
    if(mes % 2 == 0){
        if(mes == 2)
        {
            if(verificabissexto(ano) == 1)
                return 29;
            else
                return 28;
        }
    else
        return 30;
    }
}

int main(){
    int dia, mes, ano;
    int ultimo;

    scanf("%d %d %d", &dia, &mes, &ano);
    ultimo = verificaultimodia(mes, ano);

    if(dia != ultimo)
        printf("%d, %d, %d\n", dia + 1, mes, ano);
    else{
        if(mes != 12)
        printf("1, %d, %d\n", mes + 1, ano);
        else
        {
        printf("1, 1, %d\n", ano + 1);
        }
    }

return 0;
}