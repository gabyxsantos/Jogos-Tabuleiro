#ifndef LIG4_H
#define LIG4_H

#include "Jogos/Jogos.hpp"

/**
 * @class Lig_4
 * @brief Classe responsável pela implementação do jogo Lig-4.
 *
 * @details Esta classe herda de `Jogo_De_Tabuleiro` e implementa as regras específicas do jogo Lig-4,
 * incluindo a escolha de peças, a verificação de jogadas e a lógica de vitória. Durante o desenvolvimento, 
 * enfrentamos desafios ao estruturar a verificação de vitórias, já que é necessário analisar alinhamentos 
 * horizontais, verticais e diagonais, o que resultou em múltiplos loops aninhados. Para otimizar o desempenho, 
 * implementamos verificações eficientes que reduzem o número de iterações desnecessárias. Além disso, 
 * a função `escolher_peca()` foi adicionada para permitir maior personalização ao jogador. Outro ponto 
 * importante foi garantir que a leitura das jogadas fosse intuitiva e validada corretamente, evitando entradas 
 * inválidas e prevenindo erros que poderiam comprometer a estabilidade do jogo.
 */
class Lig_4 : public Jogo_De_Tabuleiro {
    public:
        /**
         * @brief Construtor padrão da classe Lig_4.
         */
        Lig_4();

        /**
         * @brief Destrutor da classe Lig_4.
         */
        ~Lig_4();

        /**
         * @brief Permite ao jogador escolher uma peça diferente da especificada.
         * @param peca_excluida Peça que não pode ser escolhida.
         * @return Retorna a peça escolhida pelo jogador.
         */
        std::string escolher_peca(const std::string& peca_excluida);

        /**
         * @brief Verifica se uma jogada é válida.
         * @param linha Linha onde a peça será posicionada.
         * @param coluna Coluna onde a peça será posicionada.
         * @return Retorna true se a jogada for válida, false caso contrário.
         */
        bool verificar_jogada(int linha, int coluna) override;

        /**
         * @brief Lê e processa a jogada do jogador.
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
         * @brief Função auxiliar para o tutorial do Lig-4.
         * @param peca Peça utilizada no tutorial.
         * @param coluna Coluna onde a peça será posicionada no tutorial.
         */
        void auxiliar_tutorial(const std::string& peca, int coluna);
};

#endif
