#include <stdio.h>
#include <math.h>

int getQuantidadeDeItens(int tipo, int inventario[], int quantidade){
    int quantidadeDeItemTipo = 0;
    for (int i = 0; i < quantidade; i++) {
        if (inventario[i] == tipo) {
            quantidadeDeItemTipo++;
        }
    }
    return quantidadeDeItemTipo;
}

int main(){
    int quantidade = 10;
    int inventario[30] = {1, 0, 3, 2, 1, 3, 0, 0, 2, 1};
    int tipo = 1;
    int quantidadeDeItemTipo = getQuantidadeDeItens(tipo, inventario, quantidade);
    printf("Quantidade de itens do tipo %d: %d\n", tipo, quantidadeDeItemTipo);
    return 0;
}
