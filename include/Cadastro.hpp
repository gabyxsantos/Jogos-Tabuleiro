#ifndef CADASTRO_H
#define CADASTRO_H
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class Placar{
    public:
        int vitorias = 0;
        int derrotas = 0;
    
};

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int vitorias_totais; 
    int derrotas_totais;
    Placar Reversi;
    Placar Lig4;
    Placar JogoVelha;

    public:
    Jogador(std::string nome, std::string apelido);
    void set_nome();
    void set_apelido();
    void set_vitorias_totais();
    void set_derrotas_totais();

    void set_vitorias_totais(int n);
    void set_derrotas_totais(int n);

    //se os metodos set forem chamados com bool isso indica que é apenas a atualização do placar na partida
    void set_Reversi(bool valor);
    void set_Lig4(bool valor);
    void set_JogoVelha(bool valor);
    //por outro lado, se forem chamados com inteiros, indica que apenas se esta lendo os dados do arquivo
    void set_Reversi(int vitorias, int derrotas);
    void set_Lig4(int vitorias, int derrotas);
    void set_JogoVelha(int vitorias, int derrotas);

    std::string get_nome();
    std::string get_apelido();
    int get_vitorias_totais();
    int get_derrotas_totais();
    Placar get_Reversi();
    Placar get_Lig4();
    Placar get_JogoVelha();
};

class RegistroJogadores{
    private:
    std::list<Jogador*> Jogadores;

    public: 
    void ordenar_jogadores_nome();
    void ordenar_jogadores_apelido(); ////////////OBSERVAÇÃO//////////ESSE CODIGO DISTINGUE MAIUSCULAS E MINUSCULAS, E POR ISSO APRESENTA UM BUG AO ORDENAR!!!!
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
    std::list<Jogador*>::iterator buscar_jogador(std::string& apelido);
    bool adicionar_jogador(Jogador* jogador_novo, std::string apelido);
    void remover_jogador(std::string& apelido);
    void mostrar_jogadores();
};


#endif