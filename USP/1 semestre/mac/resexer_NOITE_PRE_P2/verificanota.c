#include <stdio.h>

#define n 30    //define o numero de questoes da prova...
#define a 15    //define o numero de alunos da prova...

int main(){
    char gabarito[n]; //define as respostas corretas para cada uma das n questões...
    int acerto[a]; //define o numero de acertos para o aluno indentificado por a...

    for(int i = 0; i < n; i++)
    scanf(" %c", &gabarito[i]);


    for(int i = 0; i < a; i++){
        int numero;
        int acertos = 0;
        scanf("%d", &numero);

        for(int k = 0; k < n; k++)
        {
            char ralu;
            scanf(" %c", &ralu);
            if(ralu == gabarito[k])
            acertos++;
        }
        acerto[numero - 1] = acertos;
    }

    for(int i = 0; i < a; i++)
    printf("a nota do aluno %d foi de %d acertos de um total de %d\n", i + 1, acerto[i], n);

    return 0;
}