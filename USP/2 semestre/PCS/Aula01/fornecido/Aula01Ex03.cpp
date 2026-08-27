#include <stdio.h>
#include <string>

using namespace std;

int getQuantidadeDeEquipamentosIguais(string equipamentos1[], int quantidade1, string equipamentos2[], int quantidade2){
    int quantidadeDeEquipamentosIguais = 0;
    for (int i = 0; i < quantidade1; i++){
        for (int k = 0; k < quantidade2; k++){
            if (equipamentos1[i] == equipamentos2[k]){
                quantidadeDeEquipamentosIguais++;
            }
        }
    }
    return quantidadeDeEquipamentosIguais;
}

int main(){
    string equipamentos1[5] = {"Espada", "Escudo", "Armadura", "Elmo", "Botas"};
    string equipamentos2[5] = {"Espada", "Armadura", "Elmo", "Botas", "Capa"};
    int quantidade1 = 5;
    int quantidade2 = 5;
    int quantidadeDeEquipamentosIguais = getQuantidadeDeEquipamentosIguais(equipamentos1, quantidade1, equipamentos2, quantidade2);
    printf("Quantidade de equipamentos iguais: %d\n", quantidadeDeEquipamentosIguais);
    return 0;
}
