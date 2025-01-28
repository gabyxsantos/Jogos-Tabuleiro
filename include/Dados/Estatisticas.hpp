#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "Cadastro/Cadastro.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

class Estatisticas{
    private:
        CadastroJogadores acessar_jogadores;
        std::vector<Jogador*> ranking_jogadores;

    protected:
        void atualizar_ranking();
        void ranking_geral();
        void ranking_reversi();
        void ranking_lig4();
        void ranking_jogovelha();
        void ranking_batalhanaval();
        void imprimir_ranking(std::vector<Jogador*> vetor_jogadores);

    public:   
        Estatisticas(CadastroJogadores &buscador);
        void listar_jogadores();
        void atualizar_acesso(CadastroJogadores &buscador);
        void estatisticas_jogos();
        ~Estatisticas();
};      

#endif