#ifndef JOGADOR_H
#define JOGADOR_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"

class Placar{
    public:
        int vitorias = 0;
        int derrotas = 0;
        int empates=0;
    
};

class Jogador{
    private:
    std::string nome;
    std::string apelido;
    int vitorias_totais; 
    int derrotas_totais;
    int empates_totais;
    Placar Reversi;
    Placar Lig4;
    Placar JogoVelha;

    public:
    Jogador(std::string nome, std::string apelido);
    
    void set_nome();
    void set_apelido();
    void set_vitorias_totais();
    void set_derrotas_totais();
    void set_empates_totais();

    void set_vitorias_totais(int n);
    void set_derrotas_totais(int n);
    void set_empates_totais(int n);

    //se os metodos set forem chamados com bool isso indica que é apenas a atualização do placar na partida
    void set_Reversi(bool valor);
    void set_Lig4(bool valor);
    void set_JogoVelha(bool valor);
    //por outro lado, se forem chamados com inteiros, indica que apenas se esta lendo os dados do arquivo
    void set_Reversi(int vitorias, int derrotas, int empates);
    void set_Lig4(int vitorias, int derrotas, int empates);
    void set_JogoVelha(int vitorias, int derrotas, int empates);

    std::string get_nome();
    std::string get_apelido();
    int get_vitorias_totais();
    int get_derrotas_totais();
    int get_empates_totais();
    Placar get_Reversi();
    Placar get_Lig4();
    Placar get_JogoVelha();
};

#endif