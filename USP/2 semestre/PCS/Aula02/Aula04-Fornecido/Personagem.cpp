/*
 * Faca os includes e coloque a implementacao dos metodos aqui!
 */
#include "Personagem.h"

string Personagem::getNome() {
    return nome;
}
int Personagem::getHp() {
    return hp;
}
int Personagem::getForca() {
    return forca;
}
void Personagem::setForca(int novaForca) {
    forca = novaForca;
}

void Personagem::iniciar(std::string nome, int hp, int forca){
    this->nome = nome;
    this->hp = hp;
    this->forca = forca;
}

int Personagem::atacar(Personagem* p) {
    return p->defender(forca);
}

int Personagem::defender(int dano) {
    int danoEfetivo = min(dano, hp);
    hp -= dano;
    if (hp < 0) hp = 0;
    return danoEfetivo;
}

bool Personagem::estaVivo() {
    return hp > 0;
}

void Personagem::mostrarAtributos() {
    cout << "Nome: " << nome << endl;
    cout << "HP: " << hp << endl;
    cout << "Forca: " << forca << endl;
}
