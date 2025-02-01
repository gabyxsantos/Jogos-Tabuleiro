#ifndef JOGOS_H
#define JOGOS_H

#include "Cadastro/Cadastro.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

/**
 * @class Jogo_De_Tabuleiro
 * @brief Classe base para jogos de tabuleiro.
 * 
 * @details Esta classe fornece a estrutura genérica para a implementação de jogos de tabuleiro,
 * incluindo métodos para gerenciar o tabuleiro, processar jogadas e verificar condições de vitória.
 * Jogos específicos devem herdar desta classe e implementar os métodos abstratos, garantindo que 
 * cada jogo tenha sua própria lógica de jogadas e regras. A classe possui funcionalidades essenciais 
 * como inicialização do tabuleiro, impressão, validação de jogadas e gerenciamento de partidas 
 * (verificação de vitória, empate e atualização do placar). 
 * 
 * Para facilitar a implementação de diferentes jogos, foram incluídos métodos para definir e obter 
 * informações do tabuleiro, além de ferramentas auxiliares como a remoção de cores de peças 
 * e personalização do preenchimento do tabuleiro. A classe também lida com o gerenciamento do placar 
 * dos jogadores, permitindo a atualização automática de vitórias, derrotas e empates no sistema de 
 * cadastro. Sua estrutura foi planejada para ser reutilizável, permitindo que novos jogos sejam 
 * adicionados sem grandes modificações na arquitetura principal.
 */

class Jogo_De_Tabuleiro {
    protected:
        std::string filler; ///< Caractere usado para preencher espaços vazios no tabuleiro.
        int linhas, colunas; ///< Dimensões do tabuleiro.
        std::vector<std::vector<std::string>> tabuleiro; ///< Matriz representando o tabuleiro do jogo.

    public:
        /**
         * @brief Destrutor virtual para permitir limpeza apropriada.
         */
        virtual ~Jogo_De_Tabuleiro() = default;

        // Métodos abstratos
        /**
         * @brief Verifica se a jogada é válida.
         * @param linha Linha onde a peça será posicionada.
         * @param coluna Coluna onde a peça será posicionada.
         * @return Retorna true se a jogada for válida, false caso contrário.
         */
        virtual bool verificar_jogada(int linha, int coluna) = 0;

        /**
         * @brief Lê a jogada do jogador e a processa.
         * @param peca Peça que será posicionada no tabuleiro.
         */
        virtual void ler_jogada(const std::string& peca) = 0;

        /**
         * @brief Testa se um jogador venceu a partida.
         * @param peca Peça do jogador que pode ter vencido.
         * @return Retorna true se houver vitória, false caso contrário.
         */
        virtual bool testar_vitoria(const std::string& peca) = 0;

        // Métodos para o tabuleiro
        /**
         * @brief Define o caractere de preenchimento do tabuleiro.
         * @param filler Caractere usado para preencher espaços vazios.
         */
        void definir_filler(std::string filler);

        /**
         * @brief Define o tamanho do tabuleiro.
         * @param linhas Número de linhas do tabuleiro.
         * @param colunas Número de colunas do tabuleiro.
         */
        void definir_tamanho_tabuleiro(int linhas, int colunas);

        /**
         * @brief Inicializa o tabuleiro com o filler definido.
         */
        void inicializar_tabuleiro();

        /**
         * @brief Imprime o tabuleiro atual.
         * 
         * @details Virtual devido ao tamanho superior do tabuleiro de Batalha Naval.
         */
        virtual void imprimir_tabuleiro();

        /**
         * @brief Imprime o tabuleiro no tutorial.
         */
        void imprimir_tabuleiro_tutorial();

        /**
         * @brief Verifica se o tabuleiro está completamente preenchido.
         * @return Retorna true se o tabuleiro estiver cheio, false caso contrário.
         */
        bool tabuleiro_cheio();

        // Remover cor das peças
        /**
         * @brief Remove a cor do texto fornecido.
         * @param texto Texto com formatação de cor.
         * @return Retorna o texto sem formatação de cor.
         */
        std::string remover_cor(const std::string& texto);

        // Getters
        /**
         * @brief Obtém o caractere de preenchimento do tabuleiro.
         * @return O caractere usado como filler.
         */
        std::string get_filler();

        /**
         * @brief Obtém o número de linhas do tabuleiro.
         * @return O número de linhas do tabuleiro.
         */
        int get_linhas();

        /**
         * @brief Obtém o número de colunas do tabuleiro.
         * @return O número de colunas do tabuleiro.
         */
        int get_colunas();

        /**
         * @brief Obtém a matriz que representa o tabuleiro.
         * @return Matriz do tabuleiro.
         */
        std::vector<std::vector<std::string>> get_tabuleiro();

        // Setters
        /**
         * @brief Define o tabuleiro com uma matriz personalizada.
         * @param tabuleiro Nova matriz a ser usada como tabuleiro.
         */
        void set_tabuleiro(std::vector<std::vector<std::string>> tabuleiro);

        // Métodos para encerramento da partida
        /**
         * @brief Finaliza a partida com um vencedor.
         * @param apelido_vencedor Nome do jogador vencedor.
         */
        void finalizar_partida_vencedor(const std::string& apelido_vencedor);

        /**
         * @brief Finaliza a partida em empate.
         */
        void finalizar_partida_empate();

        /**
         * @brief Testa se houve empate entre os jogadores.
         * @param peca1 Peça do primeiro jogador.
         * @param peca2 Peça do segundo jogador.
         * @return Retorna true se houver empate, false caso contrário.
         */
        bool testar_empate(const std::string& peca1, const std::string& peca2);

        // Métodos para atualizar placar
        /**
         * @brief Atualiza o placar após uma partida com vencedor.
         * @param apelido_vencedor Nome do jogador vencedor.
         * @param apelido_perdedor Nome do jogador perdedor.
         * @param jogo Nome do jogo.
         * @param buscador Objeto de busca no cadastro de jogadores.
         */
        void atualizar_placar(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo, CadastroJogadores& buscador);

        /**
         * @brief Atualiza o placar após uma partida empatada.
         * @param apelido_vencedor Nome do primeiro jogador.
         * @param apelido_perdedor Nome do segundo jogador.
         * @param jogo Nome do jogo.
         * @param buscador Objeto de busca no cadastro de jogadores.
         */
        void atualizar_placar_empate(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo, CadastroJogadores &buscador);

        // Método para definir cor
        /**
         * @brief Define uma cor para a peça que não pode ser igual à outra já escolhida.
         * @param cor_excluida Cor que deve ser evitada (padrão: " ").
         * @return Retorna a cor definida.
         */
        std::string definir_cor(const std::string& cor_excluida = " ");
};

#endif
