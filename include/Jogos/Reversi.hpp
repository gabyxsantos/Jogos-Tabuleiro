#ifndef REVERSI_H
#define REVERSI_H

#include "Jogos/Jogos.hpp"

class Reversi : public Jogo_De_Tabuleiro{
    private:
    int linha_ultima_jogada;
    int coluna_ultima_jogada;

    public:
    Reversi();
    ~Reversi();

    void colocar_pecas_iniciais(std::string jogador1, std::string jogador2);
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
    void mostrar_posicoes_possiveis(std::string jogador1, std::string jogador2);
    void converter_pecas(std::string& peca_nova, std::string& peca_convertida);
    void auxiliar_tutorial(const std::string& peca, int linha, int coluna);  // Função auxiliar para o tutorial de Reversi
};

#endif