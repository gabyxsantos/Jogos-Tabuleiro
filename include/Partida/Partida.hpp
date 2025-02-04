#ifndef PARTIDA_H
#define PARTIDA_H

#include "Cadastro/Cadastro.hpp"
#include "Jogos/Jogos.hpp"
#include "Jogos/Batalha_naval.hpp"
#include "Jogos/Lig_4.hpp"
#include "Jogos/Jogo_da_velha.hpp"
#include "Jogos/Reversi.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

/**
 * @class Partida
 * @brief Representa uma partida entre dois jogadores.
 *
 * @details Essa classe gerencia o processo de escolha de jogo, definição de jogadores e início da partida.
 * Durante o desenvolvimento, enfrentamos desafios relacionados à organização dos métodos e atributos, 
 * garantindo que a lógica fosse clara e modular. Inicialmente, os métodos de escolha de jogos 
 * estavam misturados na lógica de seleção de jogadores, o que dificultava a manutenção e expansão do código. 
 * Para solucionar isso, organizamos melhor a classe, separando claramente a escolha do jogo da definição dos jogadores. 
 * Outro problema enfrentado foi o controle de jogadores cadastrados, pois precisávamos garantir que apenas 
 * jogadores válidos fossem selecionados para uma partida, o que levou à criação de métodos específicos para 
 * identificação.
 */

class Partida {
    private:
        CadastroJogadores acesso_lista; ///< Acesso à lista de jogadores cadastrados.
        char nome_do_jogo; ///< Nome do jogo escolhido.
        std::string apelido_jogador_1; ///< Apelido do primeiro jogador.
        std::string apelido_jogador_2; ///< Apelido do segundo jogador.

    public:
        /**
         * @brief Construtor que inicializa a partida com um cadastro de jogadores.
         * @param buscador Referência ao cadastro de jogadores.
         */
        Partida(CadastroJogadores& buscador);
        
        /**
         * @brief Destrutor da classe Partida.
         */
        ~Partida();
        
        /**
         * @brief Atualiza o acesso à lista de jogadores.
         * @param buscador Referência ao novo cadastro de jogadores.
         */
        void atualizar_acesso(CadastroJogadores &buscador);
        
        /**
         * @brief Inicia a partida com os jogadores definidos.
         */
        void iniciar_partida();
        
        /**
         * @brief Permite ao jogador escolher o jogo a ser jogado.
         */
        void escolher_jogo();
        
        /**
         * @brief Identifica um jogador na lista de jogadores.
         * @param jogador Iterador para o jogador a ser identificado.
         */
        void identificar_jogador(std::list<Jogador*>::iterator& jogador);
        
        /**
         * @brief Define os dois jogadores que participarão da partida.
         */
        void definir_jogadores();
        
        /**
         * @brief Inicia uma partida de Batalha Naval.
         */
        void jogar_batalha_naval();
        
        /**
         * @brief Inicia uma partida de Lig 4.
         */
        void jogar_lig_4();
        
        /**
         * @brief Inicia uma partida de Jogo da Velha.
         */
        void jogar_jogo_da_velha();
        
        /**
         * @brief Inicia uma partida de Reversi.
         */
        void jogar_reversi();
};

#endif
