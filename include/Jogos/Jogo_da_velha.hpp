#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "Jogos/Jogos.hpp"

/**
 * @class Jogo_Da_Velha
 * @brief Representa o jogo da velha, derivado de Jogo_De_Tabuleiro.
 *
 * @details Esta classe herda de 'Jogo_De_Tabuleiro' e implementa 'Jogo_Da_Velha', permitindo 
 * que os jogadores escolham peças, façam jogadas e verifiquem condições 
 * de vitória. Um dos principais desafios durante o desenvolvimento foi garantir 
 * que as jogadas fossem corretamente validadas e registradas no tabuleiro sem 
 * sobrescrever posições ocupadas. Além disso, a implementação da verificação de 
 * vitória exigiu a criação de verificações eficientes para linhas, colunas e 
 * diagonais, garantindo que todas as condições fossem corretamente testadas 
 * após cada jogada. A funcionalidade `pecas_coloridas` foi adicionada para 
 * permitir que os jogadores escolham peças com cores diferentes, melhorando a 
 * experiência visual do jogo. A classe foi estruturada para garantir 
 * modularidade e facilitar futuras expansões ou melhorias no jogo.
 */

class Jogo_Da_Velha : public Jogo_De_Tabuleiro {
    public:
        bool pecas_coloridas; ///< Indica se as peças do jogo serão coloridas.

        /**
         * @brief Construtor padrão do Jogo_Da_Velha.
         */
        Jogo_Da_Velha();

        /**
         * @brief Destrutor do Jogo_Da_Velha.
         */
        ~Jogo_Da_Velha();

        /**
         * @brief Permite ao jogador escolher uma peça para jogar.
         * @param peca_excluida Peça que não pode ser escolhida (padrão: " ").
         * @param colorido Indica se as peças terão cores (padrão: false).
         * @return Retorna a peça escolhida como string.
         */
        std::string escolher_peca(const std::string& peca_excluida = " ", bool colorido = false);

        /**
         * @brief Permite ao jogador escolher a cor de uma peça.
         * @param peca Peça cuja cor será escolhida.
         * @return Retorna a cor escolhida como string.
         */
        std::string escolher_cor(const std::string& peca);

        /**
         * @brief Verifica se uma jogada é válida.
         * @param linha Linha onde a peça será posicionada.
         * @param coluna Coluna onde a peça será posicionada.
         * @return Retorna true se a jogada for válida, false caso contrário.
         */
        bool verificar_jogada(int linha, int coluna) override;

        /**
         * @brief Lê a jogada do jogador e a processa.
         * @param peca Peça que será posicionada no tabuleiro.
         */
        void ler_jogada(const std::string& peca) override;

        /**
         * @brief Testa se um jogador venceu a partida.
         * @param peca Peça do jogador que pode ter vencido.
         * @return Retorna true se houver vitória, false caso contrário.
         */
        bool testar_vitoria(const std::string& peca) override;

        /**
         * @brief Auxilia no tutorial do jogo da velha.
         * @param peca Peça usada no tutorial.
         * @param linha Linha onde a peça será posicionada.
         * @param coluna Coluna onde a peça será posicionada.
         */
        void auxiliar_tutorial(const std::string& peca, int linha, int coluna);
};

#endif
