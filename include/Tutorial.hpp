#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "FuncoesGlobais.hpp"
#include "Jogos/Jogos.hpp"
#include "Jogos/Lig_4.hpp"
#include "Jogos/Jogo_da_velha.hpp"
#include "Jogos/Reversi.hpp"

class Tutorial{
    private:
        void imprimir_regras_lig4();
        void imprimir_regras_reversi();
        void imprimir_regras_jogo_da_velha(); 

        void iniciar_tutorial_lig4();
        void iniciar_tutorial_reversi();
        void iniciar_tutorial_jogo_da_velha();
    public:
        void mostrar_opcoes_tutorial();
        void iniciar_tutorial(int opcao_jogo);
};

#endif
