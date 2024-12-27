#ifndef JOGOS_H
#define JOGOS_H
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <iomanip>

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

/*
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
*/

class Jogo_De_Tabuleiro {
    protected:
    int linhas, colunas;
    std::vector<std::vector<std::string>> tabuleiro;

    // Podemos tentar tornar essa função mais geral, não apenas para jogos, talvez colocar em public ou coisa assim. 
    void imprimir_erro(const std::string& erro);

    public:
    virtual ~Jogo_De_Tabuleiro() = default; // Destrutor virtual para permitir limpeza apropriada

    // Métodos abstratos
    virtual void definir_tamanho_tabuleiro(int linhas, int colunas) = 0;
    virtual void inicializar_tabuleiro() = 0;
    virtual void imprimir_tabuleiro() = 0;
    virtual bool verificar_jogada(int linha, int coluna) = 0;
    virtual void ler_jogada(const std::string& peca) = 0;
    virtual bool testar_vitoria(const std::string& peca) = 0;
    virtual void finalizar_partida(const std::string& apelido_vencedor) = 0;

    // Método para definir uma cor que não pode ser igual a outra
    std::string definir_cor(const std::string& cor_excluida = " ");
};

class Lig_4 : public Jogo_De_Tabuleiro {
    public:
    Lig_4();

    void definir_tamanho_tabuleiro(int linhas, int colunas) override;
    void inicializar_tabuleiro() override;
    void imprimir_tabuleiro() override;
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
    void finalizar_partida(const std::string& nome_vencedor) override;
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