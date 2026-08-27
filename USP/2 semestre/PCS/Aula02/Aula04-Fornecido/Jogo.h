/*
 * Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 */

#define MAXIMO_DE_MONSTROS 10

class Jogo {
    /*
     * Os atributos devem ser acessiveis somente internamente ao escopo
     * da classe
     */

    /*
     * Os metodos devem ser acessíveis de fora do escopo da classe
     */
    void setJogador(Personagem* p);
    void adicionarMonstro(Personagem* monstro);
    void lutar(Personagem* monstro);
    int jogar();
    int getQuantidadeDeMonstros();
    Personagem** getMonstros();
    Personagem* getJogador();
};