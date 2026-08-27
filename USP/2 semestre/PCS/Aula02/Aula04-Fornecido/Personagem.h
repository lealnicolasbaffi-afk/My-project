/*
 * Coloque a definicao da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 *
 *  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
 */

#include <iostream>

using namespace std;

class Personagem {
    // Getters
    public:
    string getNome();
    int getHp();
    int getForca();

    // Setters
    void setForca(int novaForca);

    // Outros métodos
    void iniciar(string nome, int hp, int forca);
    int atacar(Personagem* p);
    int defender(int dano);
    bool estaVivo();
    void mostrarAtributos();
    private:
    string nome;
    int hp;
    int forca;
};