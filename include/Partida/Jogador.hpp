#ifndef JOGADOR_H
#define JOGADOR_H

#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

class Placar{
    public:
        int vitorias = 0;
        int derrotas = 0;
        int empates= 0;
        int pontos_por_jogo = 0;
    
};

class Jogador{
    private:
        std::string nome;
        std::string apelido;
        int vitorias_totais = 0; 
        int derrotas_totais = 0;
        int empates_totais = 0;
        int pontos_totais = 0;
        Placar Reversi;
        Placar Lig4;
        Placar JogoVelha;
        Placar BatalhaNaval;

    public:
    Jogador(std::string nome, std::string apelido);
    Jogador();
    ~Jogador();

    void set_nome();
    void set_apelido();
    void set_vitorias_totais();
    void set_derrotas_totais();
    void set_empates_totais();
    

//metodos para armazenar os dados do arquivo nos atributos de cada jogador
    void set_vitorias_totais(int n);
    void set_derrotas_totais(int n);
    void set_empates_totais(int n);
    void set_pontos_totais(int n);

    //metodos para atualizar os empates
    void set_Lig4();
    void set_JogoVelha();
    void set_BatalhaNaval();

    //se os metodos set forem chamados com bool isso indica que é apenas a atualização do placar na partida
    //no caso dos pontos, true= vitoria= +3pontos; false = empate = +1ponto
    void set_pontos_totais(bool valor); //passa o jogo pra saber onde add ponto
    void set_Reversi(bool valor);
    void set_Lig4(bool valor);
    void set_JogoVelha(bool valor);
    void set_BatalhaNaval(bool valor);

    //por outro lado, se forem chamados com inteiros, indica que apenas se esta lendo os dados do arquivo
    void set_Reversi(int vitorias, int derrotas, int empates, int pontos);
    void set_Lig4(int vitorias, int derrotas, int empates, int pontos);
    void set_JogoVelha(int vitorias, int derrotas, int empates, int pontos);
    void set_BatalhaNaval(int vitorias, int derrotas, int empates, int pontos);

    std::string get_nome();
    std::string get_apelido();
    int get_vitorias_totais();
    int get_derrotas_totais();
    int get_empates_totais();
    int get_pontos_totais();
    Placar get_Reversi();
    Placar get_Lig4();
    Placar get_JogoVelha();
    Placar get_BatalhaNaval();
};

#endif