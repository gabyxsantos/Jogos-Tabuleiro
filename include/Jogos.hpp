#ifndef JOGOS_H
#define JOGOS_H
#include "FuncoesGlobais.hpp"
#include "Cadastro.hpp"

class Jogo_De_Tabuleiro {
    protected:
    std::string filler;
    int linhas, colunas;
    std::vector<std::vector<std::string>> tabuleiro;


    public:
    virtual ~Jogo_De_Tabuleiro() = default; // Destrutor virtual para permitir limpeza apropriada

    // Métodos abstratos
    virtual bool verificar_jogada(int linha, int coluna) = 0;
    virtual void ler_jogada(const std::string& peca) = 0;
    virtual bool testar_vitoria(const std::string& peca) = 0;
    
    
    // Métodos para o tabuleiro
    void definir_filler(std::string filler);
    void definir_tamanho_tabuleiro(int linhas, int colunas);
    void inicializar_tabuleiro();
    void imprimir_tabuleiro();
    bool tabuleiro_cheio();

    // Metodos para encerramento da partida
    void finalizar_partida_vencedor(const std::string& apelido_vencedor);
    void finalizar_partida_empate();
    bool testar_empate(const std::string& peca1, const std::string& peca2);

    //metodo para atualizar placar
    void atualizar_placar(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo);

    // Método para definir uma cor que não pode ser igual a outra
    std::string definir_cor(const std::string& cor_excluida = " ");
};

class Lig_4 : public Jogo_De_Tabuleiro {
    public:
    Lig_4();

    std::string escolher_peca(const std::string& peca_excluida);
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
};

class Jogo_Da_Velha : public Jogo_De_Tabuleiro{
    public:
    bool pecas_coloridas;
    Jogo_Da_Velha();

    std::string escolher_peca(const std::string& peca_excluida = " ", bool colorido = false);
    std::string escolher_cor(const std::string& peca);
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
};

class Reversi : public Jogo_De_Tabuleiro{
    private:
    int linha_ultima_jogada;
    int coluna_ultima_jogada;

    public:
    Reversi();

    void colocar_pecas_iniciais(std::string jogador1, std::string jogador2);
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
    void mostrar_posicoes_possiveis(std::string jogador1, std::string jogador2);
    void converter_pecas(std::string& peca_nova, std::string& peca_convertida);
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