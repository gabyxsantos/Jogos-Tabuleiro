#ifndef CADASTRO_H
#define CADASTRO_H
#include <iostream>
#include <string>
#include <list>

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int numero_vitorias;
    int numero_derrotas;

    public:
    void set_nome(int numero_jogador);
    void set_apelido(int numero_jogador);
    void adicionar_vitoria();
    void adicionar_derrota();
    std::string get_nome();
    std::string get_apelido();
    int get_vitorias();
    int get_derrotas();
};

class Registro_jogadores{
    private:
    std::list<Jogador> Jogadores;

    public: 
    void ordenar_jogadores();
    void ordenar_jogadores();
    std::string buscar_jogador();
    void adicionar_jogador();
    void remover_jogador();
};


#endif