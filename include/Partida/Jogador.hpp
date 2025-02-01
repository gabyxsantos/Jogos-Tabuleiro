#ifndef JOGADOR_H
#define JOGADOR_H

#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

/**
 * @class Placar
 * @brief Representa o placar de um jogo.
 *
 * @details Essa estrutura foi criada para organizar as estatísticas de cada jogo separadamente, evitando a mistura
 * de dados no código principal da classe `Jogador`. Inicialmente, consideramos armazenar todas as estatísticas 
 * diretamente como atributos de `Jogador`, mas isso tornaria a classe mais difícil de expandir e manter. 
 * Com a implementação de `Placar`, cada jogo tem seu próprio conjunto de contadores, permitindo modularidade e 
 * facilitando futuras adições de novos jogos sem a necessidade de grandes refatorações. Além disso, essa separação 
 * torna o código mais intuitivo e melhora a legibilidade.
 */
class Placar {
    public:
        int vitorias = 0;  ///< Número de vitórias.
        int derrotas = 0;  ///< Número de derrotas.
        int empates = 0;   ///< Número de empates.
        int pontos_por_jogo = 0; ///< Pontos ganhos por jogo.
};

/**
 * @class Jogador
 * @brief Representa um jogador e suas estatísticas nos jogos.
 * @details Essa classe armazena informações sobre o jogador, incluindo nome, apelido e desempenho em diferentes jogos.
 * Durante o desenvolvimento, um dos desafios foi garantir que as estatísticas dos jogadores fossem organizadas de 
 * maneira eficiente e extensível. Para isso, optamos por criar a estrutura `Placar` para armazenar dados individuais 
 * de cada jogo, evitando poluir a classe `Jogador` com múltiplos atributos diretos. Além disso, a separação de métodos 
 * `set` e `get` para cada jogo permitiu um melhor controle dos dados. Outro ponto importante foi o uso de diferentes 
 * construtores. Essa abordagem tornou o código mais flexível e facilitou a integração com outras partes do sistema.
 */
class Jogador {
    private:
        std::string nome; ///< Nome do jogador.
        std::string apelido; ///< Apelido do jogador.
        int vitorias_totais = 0;  ///< Total de vitórias do jogador.
        int derrotas_totais = 0;  ///< Total de derrotas do jogador.
        int empates_totais = 0;   ///< Total de empates do jogador.
        int pontos_totais = 0;    ///< Total de pontos do jogador.
        Placar Reversi; ///< Placar do jogo Reversi.
        Placar Lig4; ///< Placar do jogo Lig4.
        Placar JogoVelha; ///< Placar do jogo Jogo da Velha.
        Placar BatalhaNaval; ///< Placar do jogo Batalha Naval.

    public:
        /**
         * @brief Construtor que inicializa um jogador com nome e apelido.
         */
        Jogador(std::string nome, std::string apelido);
        
        /**
         * @brief Construtor padrão do jogador.
         */
        Jogador();
        
        /**
         * @brief Destrutor da classe Jogador.
         */
        ~Jogador();

        void set_nome(); ///< Define o nome do jogador.
        void set_apelido(); ///< Define o apelido do jogador.
        void set_vitorias_totais(); ///< Define o total de vitórias do jogador.
        void set_derrotas_totais(); ///< Define o total de derrotas do jogador.
        void set_empates_totais(); ///< Define o total de empates do jogador.
    
        /**
         * @brief Define o total de vitórias do jogador.
         * @param n Número de vitórias.
         */
        void set_vitorias_totais(int n);
        
        /**
         * @brief Define o total de derrotas do jogador.
         * @param n Número de derrotas.
         */
        void set_derrotas_totais(int n);
        
        /**
         * @brief Define o total de empates do jogador.
         * @param n Número de empates.
         */
        void set_empates_totais(int n);
        
        /**
         * @brief Define o total de pontos do jogador.
         * @param n Número de pontos.
         */
        void set_pontos_totais(int n);

        void set_Lig4(); ///< Atualiza o placar do jogo Lig4.
        void set_JogoVelha(); ///< Atualiza o placar do jogo Jogo da Velha.
        void set_BatalhaNaval(); ///< Atualiza o placar do jogo Batalha Naval.

        /**
         * @brief Atualiza os pontos totais do jogador com base no resultado.
         * @param valor Indica se houve vitória (true) ou empate (false).
         */
        void set_pontos_totais(bool valor);
        void set_Reversi(bool valor);
        void set_Lig4(bool valor);
        void set_JogoVelha(bool valor);
        void set_BatalhaNaval(bool valor);

        /**
         * @brief Define os resultados do jogo Reversi.
         * @param vitorias Número de vitórias.
         * @param derrotas Número de derrotas.
         * @param empates Número de empates.
         * @param pontos Pontuação total.
         */
        void set_Reversi(int vitorias, int derrotas, int empates, int pontos);
        
        /**
         * @brief Define os resultados do jogo Lig4.
         * @param vitorias Número de vitórias.
         * @param derrotas Número de derrotas.
         * @param empates Número de empates.
         * @param pontos Pontuação total.
         */
        void set_Lig4(int vitorias, int derrotas, int empates, int pontos);
        
        /**
         * @brief Define os resultados do jogo Jogo da Velha.
         * @param vitorias Número de vitórias.
         * @param derrotas Número de derrotas.
         * @param empates Número de empates.
         * @param pontos Pontuação total.
         */
        void set_JogoVelha(int vitorias, int derrotas, int empates, int pontos);
        
        /**
         * @brief Define os resultados do jogo Batalha Naval.
         * @param vitorias Número de vitórias.
         * @param derrotas Número de derrotas.
         * @param empates Número de empates.
         * @param pontos Pontuação total.
         */
        void set_BatalhaNaval(int vitorias, int derrotas, int empates, int pontos);

        std::string get_nome(); ///< Retorna o nome do jogador.
        std::string get_apelido(); ///< Retorna o apelido do jogador.
        int get_vitorias_totais(); ///< Retorna o total de vitórias do jogador.
        int get_derrotas_totais(); ///< Retorna o total de derrotas do jogador.
        int get_empates_totais(); ///< Retorna o total de empates do jogador.
        int get_pontos_totais(); ///< Retorna o total de pontos do jogador.
        Placar get_Reversi(); ///< Retorna o placar do jogo Reversi.
        Placar get_Lig4(); ///< Retorna o placar do jogo Lig4.
        Placar get_JogoVelha(); ///< Retorna o placar do jogo Jogo da Velha.
        Placar get_BatalhaNaval(); ///< Retorna o placar do jogo Batalha Naval.
};

#endif