#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "FuncoesGlobais.hpp"
#include "Jogos/Jogos.hpp"
#include "Jogos/Lig_4.hpp"
#include "Jogos/Jogo_da_velha.hpp"
#include "Jogos/Reversi.hpp"

class Tutorial{
    public:
        void imprimir_regras_lig4();
        void imprimir_regras_reversi();
        void imprimir_regras_jogo_da_velha(); 

        void simular_lig4(Lig_4& jogo, const std::string& peca, int coluna);
        void simular_reversi();
        void simular_jogo_da_velha();

        void iniciar_tutorial_lig4();
        void iniciar_tutorial_reversi();
        void iniciar_tutorial_jogo_da_velha();
};

#endif
