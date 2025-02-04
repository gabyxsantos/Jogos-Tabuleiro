#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "Cadastro/Cadastro.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"
#include <vector>

/**
 * @class Estatisticas
 * @brief Classe responsável por calcular e exibir estatísticas dos jogadores.
 *
 * @details A classe gera rankings gerais e específicos para cada jogo, além de listar os jogadores cadastrados.
 * Para isso, ela mantém um vetor com os jogadores ordenados conforme seu desempenho, atualizado a partir do 
 * sistema de cadastro. Cada jogo tem um ranking próprio, permitindo análise detalhada de cada modalidade. Além 
 * de organizar as classificações, a classe possibilita a listagem de todos os jogadores e a exibição 
 * de estatísticas gerais, consolidando informações de desempenho. O sistema permite atualização dinâmica
 * dos rankings e acesso aos dados de jogadores cadastrados, garantindo que as informações estejam sempre 
 * atualizadas conforme os resultados das partidas. Como os dados do jogos também são armazenados, o módulo 
 * 'Estatísticas também se encontra na pasta Dados.
 */

class Estatisticas {
    private:
        /**
         * @brief Objeto para acessar a lista de jogadores cadastrados.
         */
        CadastroJogadores acessar_jogadores;

        /**
         * @brief Vetor que armazena o ranking de jogadores.
         */
        std::vector<Jogador*> ranking_jogadores;

    protected:
        /**
         * @brief Atualiza o ranking dos jogadores.
         */
        void atualizar_ranking();

        /**
         * @brief Gera o ranking geral dos jogadores.
         */
        void ranking_geral();

        /**
         * @brief Gera o ranking específico do jogo Reversi.
         */
        void ranking_reversi();

        /**
         * @brief Gera o ranking específico do jogo Lig-4.
         */
        void ranking_lig4();

        /**
         * @brief Gera o ranking específico do jogo da Velha.
         */
        void ranking_jogovelha();

        /**
         * @brief Gera o ranking específico do jogo Batalha Naval.
         */
        void ranking_batalhanaval();

        /**
         * @brief Imprime o ranking de jogadores fornecido.
         * @param vetor_jogadores Vetor contendo os jogadores a serem exibidos.
         */
        void imprimir_ranking(std::vector<Jogador*> vetor_jogadores);

    public:   
        /**
         * @brief Construtor da classe Estatisticas.
         * @param buscador Objeto CadastroJogadores contendo os jogadores cadastrados.
         */
        Estatisticas(CadastroJogadores &buscador);

        /**
         * @brief Lista todos os jogadores cadastrados.
         */
        void listar_jogadores();

        /**
         * @brief Atualiza o acesso aos jogadores cadastrados.
         * @param buscador Novo objeto CadastroJogadores contendo os jogadores.
         */
        void atualizar_acesso(CadastroJogadores &buscador);

        /**
         * @brief Exibe as estatísticas gerais dos jogos.
         */
        void estatisticas_jogos();

        /**
         * @brief Destrutor da classe Estatisticas.
         */
        ~Estatisticas();
};      

#endif