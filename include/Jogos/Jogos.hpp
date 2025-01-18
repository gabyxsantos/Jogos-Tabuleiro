#ifndef JOGOS_H
#define JOGOS_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
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

    // Getters
    std::string get_filler();
    int get_linhas();
    int get_colunas();
    std::vector<std::vector<std::string>> get_tabuleiro();

    // Metodos para encerramento da partida
    void finalizar_partida_vencedor(const std::string& apelido_vencedor);
    void finalizar_partida_empate();
    bool testar_empate(const std::string& peca1, const std::string& peca2);

    //metodo para atualizar placar
    void atualizar_placar(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo, CadastroJogadores& buscador);
    void atualizar_placar_empate(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo, CadastroJogadores &buscador);

    // Método para definir uma cor que não pode ser igual a outra
    std::string definir_cor(const std::string& cor_excluida = " ");
};
#endif