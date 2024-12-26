#ifndef JOGOS_H
#define JOGOS_H
#include <iostream>
#include <string>
#include <list>

#define RESET   "\033[0m"        // Resetar cor para padrão
#define BOLD    "\033[1m"
#define RED     "\033[91m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[94m"
#define MAGENTA "\033[95m"
#define BLACK   "\033[90m"
#define ORANGE  "\033[38;5;214m"
#define WHITE   "\033[97m"       
#define PECA_VERMELHA "🔴" 
#define PECA_VERDE "🟢"     
#define PECA_AMARELA "🟡"   
#define PECA_AZUL "🔵"      
#define PECA_MAGENTA "🟣"   
#define PECA_LARANJA "🟠"   
#define PECA_PRETA "⚫"     
#define PECA_BRANCO "⚪"    

class Peca{ //Verificar a necessidade e senntido da implementação dessa classe!!!!
    protected:
    char peca;
    int coordenada_X;
    int coordenada_Y;

    public:
    void set_peca();
    void set_X();
    void set_Y();
    void get_peca();
    void get_X();
    void get_Y();
};
class Jogo_De_Tabuleiro {
    protected:
    int X, Y;
    //std::vector<std::vector<char>> tabuleiro; Mais coerente tentar primeiro com uma lógica mais simples, com arrays simples, para depois incrementar o código. Devemos também reavaliar se faz sentido mesmo fazer o tabuleiro com um vetor.
    int tamanho_tabuleiro[2];

    virtual void imprimir_menu();
    virtual void inicializar_tabuleiro()=0;
    virtual void ler_jogada();
    virtual void ler_jogada(int y);
    virtual bool verificar_jogada();
    virtual bool verificar_jogada(int y);
    virtual void testar_vitoria()=0;
    virtual void imprimir_tabuleiro()=0;
    virtual void finalizar_partida();
    virtual void finalizar_partida(std::string apelido_jogador);
    virtual std::string definir_cor(); //Ainda estamos averiguando a possibilidade de utilizar diferentes cores das peças, já que para isso deveríamos averiguar a compatibilidade com diferentes sistemas operacionais
    //Ainda sobre a funcao definir_cor, podemos depois ver formas mais agradáveis para o usuário escolher uma cor
};
class Lig_4 : public Jogo_De_Tabuleiro{
    protected:
    char tabuleiro[6][7];
    int tamanho_tabuleiro[2]={6,7};
    int numero_de_jogadas = 0;

    public:
    virtual void inicializar_tabuleiro();
    //void ler_jogada(); //Ja perguntei no forum da turma, não sei se essas funções (q são herdadas e não redefinidas) se mantém aq no cabecalho ou nao
    //void ler_jogada(int y);
    //virtual bool verificar_jogada();
    //virtual bool verificar_jogada(int y);
    virtual void testar_vitoria()=0;
    virtual void imprimir_tabuleiro()=0;
    virtual void finalizar_partida();
    virtual void finalizar_partida(std::string apelido_jogador);
    void definir_tamanho_tabuleiro();
    virtual std::string definir_cor();
};
class Jogo_Da_Velha : public Jogo_De_Tabuleiro{
    protected:
    char tabuleiro[3][3];
    int tamanho_tabuleiro[2]={3,3};
    int numero_de_jogadas = 0;
};
class Reversi : public Jogo_De_Tabuleiro{
    protected:
    char tabuleiro[8][8];
    int tamanho_tabuleiro[2]={8,8};
    int numero_de_jogadas = 0;

    public:
    void mostrar_posicoes_possiveis();
    void converter_pecas();
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