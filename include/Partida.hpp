#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
#include <string>
#include "Cadastro.hpp"
#include "Jogos.hpp"

class Partida{
private:
std::string nome_do_jogo;
std::string apelido_jogador_1;
std::string apelido_jogador_2;

public:
void escolher_jogo();
void definir_jogadores();
void jogar_lig_4();
void jogar_jogo_da_velha();
void jogar_reversi();
};

class Estatisticas{
    protected:
    std::string nome_jogador;
    int partidas_jogadas;
    int vitorias;
    int empates;
    int derrotas;

    public:
    virtual void imprimir_estatisticas();
    void estatisticas_jogo_da_velha();
    void estatisticas_lig_4();
    void estatisticas_reversi();
};

class Estatisticas_Lig_4 : public Estatisticas{
    protected:
    int numero_medio_jogadas;

    public:
    void imprimir_estatisticas();
};

class Estatisticas_Jogo_Da_Velha : public Estatisticas{
    protected:
    int numero_medio_jogadas;

    public:
    void imprimir_estatisticas();
};

class Estatisticas_Reversi : public Estatisticas{
    protected:
    int porcentagem_tabuleiro_vitorias;
    int porcentagem_tabuleiro_derrotas;

    public:
    void imprimir_estatisticas();
};

class Registro_Estatisticas{
    private:
    std::list<Estatisticas> estatisticas_por_usuario;
    
    public:
    void buscar_usuario();
};

#endif