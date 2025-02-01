#ifndef REVERSI_H
#define REVERSI_H

#include "Jogos/Jogos.hpp"


/**
 * @class Reversi
 * @brief Implementa o jogo de tabuleiro Reversi.
 *
 * @details Essa classe herda de `Jogos_de_Tabuleiro` e implementa as regras específicas do Reversi. 
 * Durante o desenvolvimento, encontramos desafios devido às regras únicas do jogo, como a necessidade 
 * de capturar peças adversárias ao fazer um movimento. Para lidar com isso, implementamos a função 
 * `converter_pecas()`, que altera o controle das peças no tabuleiro após uma jogada válida. Outra 
 * particularidade foi a implementação da função `passar_a_vez()`, pois um jogador só pode jogar se 
 * houver uma jogada válida disponível. Além disso, a função `mostrar_posicoes_possiveis()` foi criada 
 * para auxiliar o jogador a visualizar suas opções. Por fim, a verificação de vitória exigiu um teste 
 * cuidadoso das condições de término da partida, garantindo que todas as regras fossem corretamente 
 * aplicadas e evitando inconsistências no jogo.
 */
class Reversi : public Jogo_De_Tabuleiro {
    private:
        int linha_ultima_jogada;  ///< Armazena a linha da última jogada.
        int coluna_ultima_jogada; ///< Armazena a coluna da última jogada.

    public:
        /**
         * @brief Construtor da classe Reversi.
         */
        Reversi();

        /**
         * @brief Destrutor da classe Reversi.
         */
        ~Reversi();

        /**
         * @brief Coloca as peças iniciais no tabuleiro.
         * @param jogador1 Nome ou símbolo do jogador 1.
         * @param jogador2 Nome ou símbolo do jogador 2.
         */
        void colocar_pecas_iniciais(std::string jogador1, std::string jogador2);

        /**
         * @brief Verifica se a jogada é válida.
         * @param linha Linha escolhida para a jogada.
         * @param coluna Coluna escolhida para a jogada.
         * @return true se a jogada for válida, false caso contrário.
         */
        bool verificar_jogada(int linha, int coluna) override;

        /**
         * @brief Determina se o jogador deve passar a vez.
         * @return true se o jogador precisar passar a vez, false caso contrário.
         */
        bool passar_a_vez();

        /**
         * @brief Processa a jogada do jogador.
         * @param peca Símbolo do jogador que está jogando.
         */
  
        void ler_jogada(const std::string& peca) override;

        /**
         * @brief Verifica se o jogo terminou e declara um vencedor.
         * @param peca Símbolo do jogador atual.
         * @return true se houver um vencedor, false caso contrário.
         */
        bool testar_vitoria(const std::string& peca) override;

        /**
         * @brief Exibe as posições possíveis para a jogada do jogador atual.
         * @param jogador1 Nome ou símbolo do jogador 1.
         * @param jogador2 Nome ou símbolo do jogador 2.
         */
        void mostrar_posicoes_possiveis(std::string jogador1, std::string jogador2);

        /**
         * @brief Converte peças do oponente após uma jogada bem-sucedida.
         * @param peca_nova Símbolo do jogador que fez a jogada.
         * @param peca_convertida Símbolo da peça do adversário que será convertida.
         */
        void converter_pecas(std::string& peca_nova, std::string& peca_convertida);

        /**
         * @brief Função auxiliar para o tutorial de Reversi.
         * @param peca Símbolo do jogador que está aprendendo.
         * @param linha Linha da jogada.
         * @param coluna Coluna da jogada.
         */
        void auxiliar_tutorial(const std::string& peca, int linha, int coluna);
};

#endif