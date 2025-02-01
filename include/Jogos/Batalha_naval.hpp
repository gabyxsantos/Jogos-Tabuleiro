#ifndef BATALHANAVAL_H
#define BATALHANAVAL_H

#include "Jogos/Jogos.hpp"

/**
 * @class Batalha_Naval
 * @brief Classe responsável por gerenciar o jogo de Batalha Naval.
 * 
 * @details Essa classe (extra em relação ao escopo original) herda de 'Jogo_De_Tabuleiro'
 * e implementa a lógica específica do jogo, 
 * incluindo posicionamento de navios, jogadas e verificação de vitória. 
 * Durante o desenvolvimento, um dos desafios foi garantir que os jogadores 
 * pudessem posicionar seus navios corretamente, evitando sobreposição e 
 * posicionamentos inválidos. Para isso, foi implementada uma verificação rigorosa 
 * em `posicionar_navios()`. Além disso, a mecânica de ataque exigiu a criação de 
 * um sistema eficiente de detecção de acertos e erros, garantindo que os tiros 
 * fossem registrados corretamente e que a pontuação fosse calculada de forma justa. 
 * A classe também inclui um método `comparar_pontuacoes()` que permite determinar 
 * o vencedor com base nos pontos acumulados. A lógica do jogo foi estruturada 
 * para manter um equilíbrio entre estratégia e acessibilidade, garantindo que a 
 * experiência seja intuitiva para novos jogadores e desafiadora para jogadores 
 * experientes.
 */
class Batalha_Naval : public Jogo_De_Tabuleiro {
    private:
        /**
         * @brief Pontuação do oponente.
         * @details Como o mapa criado pelo jogador é utilizado pelo oponente, os pontos
         * obtidos são referentes ao jogador que joga com o mapa, e não a quem criou.
         */
        int pontos_oponente = 0;

    public:
        /**
         * @brief Construtor da classe Batalha_Naval.
         */
        Batalha_Naval();

        /**
         * @brief Destrutor da classe Batalha_Naval.
         */
        ~Batalha_Naval();

        /**
         * @brief Imprime o tabuleiro do jogo.
         */
        void imprimir_tabuleiro() override;

        /**
         * @brief Permite ao jogador posicionar seus navios no tabuleiro.
         */
        void posicionar_navios();

        /**
         * @brief Define os pontos obtidos na jogada.
         * @param pontos_jogada Número de pontos a ser atribuído.
         */
        void set_pontos(int pontos_jogada);

        /**
         * @brief Retorna os pontos do jogador.
         * @return Número de pontos acumulados.
         */
        int get_pontos();

        /**
         * @brief Lê e valida a posição inicial da peça.
         * @param peca Representação da peça no tabuleiro.
         * @return Verdadeiro se a posição for válida, falso caso contrário.
         */
        bool ler_posicao_inicial(const std::string& peca);

        /**
         * @brief Verifica se a jogada realizada é válida.
         * @param linha Linha escolhida.
         * @param coluna Coluna escolhida.
         * @return Verdadeiro se a jogada for válida, falso caso contrário.
         */
        bool verificar_jogada(int linha, int coluna) override;

        /**
         * @brief Lê a jogada do jogador.
         * @param peca Representação da peça no tabuleiro.
         */
        void ler_jogada(const std::string& peca) override;

        /**
         * @brief Compara pontuações dos jogadores.
         * @param pontos_jogador Pontuação do jogador.
         * @param apelido_jogador Apelido do jogador.
         * @param apelido_adversario Apelido do adversário.
         * @return String indicando o vencedor.
         */
        std::string comparar_pontuacoes(int pontos_jogador, const std::string& apelido_jogador, const std::string& apelido_adversario);

        /**
         * @brief Verifica se houve vitória na partida.
         * @param peca Representação da peça no tabuleiro.
         * @return Verdadeiro se o jogador venceu, falso caso contrário.
         */
        bool testar_vitoria(const std::string& peca) override;
};

#endif
