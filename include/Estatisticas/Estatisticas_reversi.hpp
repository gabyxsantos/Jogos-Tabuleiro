#ifndef ESTATISTICAS_REVERSI_H
#define ESTATISTICAS_REVERSI_H

#include "Estatisticas/Estatisticas.hpp"

class Estatisticas_Reversi : public Estatisticas{
    protected:
    int porcentagem_tabuleiro_vitorias;
    int porcentagem_tabuleiro_derrotas;

    public:
    void imprimir_estatisticas();
};

#endif