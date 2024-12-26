#ifndef JOGOS_H
#define JOGOS_H
#include <iostream>
#include <string>
#include <vector>

class Jogo_De_Tabuleiro {
    protected:
    std::vector<std::vector<char>> tabuleiro;
    int tamanho_tabuleiro[2];

    virtual void imprimir_menu()=0;
    virtual void ler_jogada()=0;
    virtual void verificar_jogada()=0;
    virtual void testar_vitoria()=0;
    virtual void imprimir_tabuleiro()=0;
    virtual void finalizar_partida()=0;
    virtual void definir_cor()=0;
};
class Lig_4 : public Jogo_De_Tabuleiro{
    protected:
    int numero_de_jogadas;

    public:
    void definir_tamanho_tabuleiro();
    void definir_cor();
};
class Jogo_Da_Velha : public Jogo_De_Tabuleiro{};
class Reversi : public Jogo_De_Tabuleiro{
    protected:
    int numero_de_jogadas;

    public:
    void mostrar_posicoes_possiveis();
    void converter_pecas();
};
class Peca{
    protected:
    int coordenada_X;
    int coordenada_Y;

    public:
    void set_X();
    void set_Y();
};
class Tutorial{
    public:
    void iniciar_tutorial_lig4();
    void iniciar_tutorial_reversi();
    void iniciar_tutorial_jogo_da_velha();
    void imprimir_regras_lig4();
    void imprimir_regras_reversi();
    void imprimir_regras_jogo_da_velha();
};
#endif