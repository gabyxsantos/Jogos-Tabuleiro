#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "Jogos/Jogos.hpp"
#include "Jogos/Lig_4.hpp"
#include "Jogos/Jogo_da_velha.hpp"
#include "Jogos/Reversi.hpp"
#include "Variaveis_globais.hpp"

/**
 * @class Tutorial
 * @brief Classe responsável por fornecer tutoriais e regras para os jogos.
 *
 * @details Classe extra que criamos (fora do escopo original do trabalho) para ensinar os jogadores 
 * as regras dos jogos. Durante o desenvolvimento, percebemos que alguns jogadores não estavam 
 * familiarizados com todos os jogos disponíveis, o que dificultava a jogabilidade. Para solucionar 
 * isso, criamos um sistema de tutoriais que apresenta regras e exemplos de jogadas. Inicialmente, 
 * pensamos em apenas imprimir as regras, mas percebemos que tutoriais simulados poderiam melhorar 
 * a experiência do usuário. Assim, dividimos a classe em métodos de impressão de regras e métodos de 
 * tutoriais simulados, permitindo uma explicação mais clara e dinâmica.  
 */
class Tutorial{
    private:
        /**
         * @brief Imprime as regras do jogo Lig-4.
         */
        void imprimir_regras_lig4();
        
        /**
         * @brief Imprime as regras do jogo Reversi.
         */
        void imprimir_regras_reversi();
        
        /**
         * @brief Imprime as regras do jogo da Velha.
         */
        void imprimir_regras_jogo_da_velha();
        
        /**
         * @brief Imprime as regras do jogo Batalha Naval.
         */
        void imprimir_regras_batalha_naval();

        /**
         * @brief Inicia o tutorial do jogo Lig-4.
         */
        void iniciar_tutorial_lig4();
        
        /**
         * @brief Inicia o tutorial do jogo Reversi.
         */
        void iniciar_tutorial_reversi();
        
        /**
         * @brief Inicia o tutorial do jogo da Velha.
         */
        void iniciar_tutorial_jogo_da_velha();
    
    public:
        /**
         * @brief Mostra as opções de tutorial disponíveis para os jogos.
         */
        void mostrar_opcoes_tutorial();
        
        /**
         * @brief Inicia o tutorial de um jogo específico.
         * @param opcao_jogo Código do jogo para iniciar o tutorial.
         */
        void iniciar_tutorial(int opcao_jogo);
};

#endif