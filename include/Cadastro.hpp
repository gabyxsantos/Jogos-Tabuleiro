#ifndef CADASTRO_H
#define CADASTRO_H
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int numero_vitorias;
    int numero_derrotas;

    public:
    void set_nome();
    void set_apelido();
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

    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    public: 
    void ordenar_jogadores_nome();
    void ordenar_jogadores_apelido(); ////////////OBSERVAÇÃO//////////ESSE CODIGO DISTINGUE MAIUSCULAS E MINUSCULAS, E POR ISSO APRESENTA UM BUG AO ORDENAR!!!!
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    std::list<Jogador>::iterator buscar_jogador(std::string& apelido);
    bool adicionar_jogador(Jogador jogador_novo, std::string apelido);
    void remover_jogador(std::string& apelido);
    void mostrar_jogadores();
};


#endif