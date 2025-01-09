#ifndef ESTATISTICAS_JOGO_DA_VELHA_H
#define ESTATISTICAS_JOGO_DA_VELHA_H

#include "Estatisticas/Estatisticas.hpp"

class Estatisticas_Jogo_Da_Velha : public Estatisticas{
    protected:
    int numero_medio_jogadas;

    public:
    void imprimir_estatisticas();
};

#endif