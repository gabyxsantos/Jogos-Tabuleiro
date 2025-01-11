#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "FuncoesGlobais.hpp"
#include "Cadastro.hpp"
#include "Validacao.hpp"

class Estatisticas{
    private:
        CadastroJogadores acessar_jogadores;
        int jogo_mais_jogado; //tem que calcular isso a cada partida
        std::vector<Jogador*> ranking_jogadores;

    protected:
        void ranking_geral();
        void ranking_reversi();
        void ranking_lig4();
        void ranking_jogovelha();

    public:
        void listar_jogadores();
        void ranking();
};      

#endif