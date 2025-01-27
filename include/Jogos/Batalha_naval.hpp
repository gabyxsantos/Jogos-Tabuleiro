#ifndef BATALHANAVAL_H
#define BATALHANAVAL_H

#include "Jogos/Jogos.hpp"

class Batalha_Naval : public Jogo_De_Tabuleiro {
    public:
    Batalha_Naval();
    ~Batalha_Naval();

    void posicionar_navios();
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
    //void auxiliar_tutorial(const std::string& peca, int coluna); // Função auxiliar para o tutorial de Lig4

};

#endif