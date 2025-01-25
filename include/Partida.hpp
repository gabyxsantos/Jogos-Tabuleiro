#ifndef PARTIDA_H
#define PARTIDA_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
#include "Cadastro.hpp"
#include "Jogos/Jogos.hpp"
#include "Jogos/Lig_4.hpp"
#include "Jogos/Jogo_da_velha.hpp"
#include "Jogos/Reversi.hpp"

class Partida{
    private:
        CadastroJogadores acesso_lista;
        char nome_do_jogo;
        std::string apelido_jogador_1;
        std::string apelido_jogador_2;

    public:
        Partida(CadastroJogadores& buscador);
        ~Partida();
        void atualizar_acesso(CadastroJogadores &buscador);
        void iniciar_partida();
        void escolher_jogo();
        void identificar_jogador(std::list<Jogador*>::iterator& jogador);
        void definir_jogadores();
        void jogar_lig_4();
        void jogar_jogo_da_velha();
        void jogar_reversi();
};

#endif