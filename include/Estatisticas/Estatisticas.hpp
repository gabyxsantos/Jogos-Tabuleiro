#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "FuncoesGlobais.hpp"

class Estatisticas{
    protected:
    std::string nome_jogador;
    int partidas_jogadas;
    int vitorias;
    int empates;
    int derrotas;

    public:
    void imprimir_estatisticas();
    void estatisticas_jogo_da_velha();
    void estatisticas_lig_4();
    void estatisticas_reversi();
};

#endif