#ifndef PARTIDA_H
#define PARTIDA_H
#include "FuncoesGlobais.hpp"
#include "Cadastro.hpp"
#include "Jogos.hpp"

class Partida{
    private:
    char nome_do_jogo;
    std::string apelido_jogador_1;
    std::string apelido_jogador_2;

    public:
    void iniciar_partida();
    void escolher_jogo();
    void definir_jogadores();
    void jogar_lig_4();
    void jogar_jogo_da_velha();
    void jogar_reversi();
    };

class Estatisticas{
    protected:
    RegistroJogadores lista;
    int partidas_jogadas;
    
    /* ideias para as estatisticas:
    - listagem dos jogadores com os respectivos dados
    - ranking geral
    - ranking por jogo
    - jogo mais escohido
    */

    public:
    virtual void imprimir_estatisticas();
    void estatisticas_jogo_da_velha();
    void estatisticas_lig_4();
    void estatisticas_reversi();
};

class Estatisticas_Lig_4 : public Estatisticas{
    protected:
    int numero_medio_jogadas;

    public:
    void imprimir_estatisticas();
};

class Estatisticas_Jogo_Da_Velha : public Estatisticas{
    protected:
    int numero_medio_jogadas;

    public:
    void imprimir_estatisticas();
};

class Estatisticas_Reversi : public Estatisticas{
    protected:
    int porcentagem_tabuleiro_vitorias;
    int porcentagem_tabuleiro_derrotas;

    public:
    void imprimir_estatisticas();
};

class Registro_Estatisticas{
    private:
    std::list<Estatisticas> estatisticas_por_usuario;
    
    public:
    void buscar_usuario();
};

#endif