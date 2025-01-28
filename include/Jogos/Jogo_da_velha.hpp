#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "Jogos/Jogos.hpp"

class Jogo_Da_Velha : public Jogo_De_Tabuleiro{
    public:
        bool pecas_coloridas;
        Jogo_Da_Velha();
        ~Jogo_Da_Velha();

        std::string escolher_peca(const std::string& peca_excluida = " ", bool colorido = false);
        std::string escolher_cor(const std::string& peca);
        bool verificar_jogada(int linha, int coluna) override;
        void ler_jogada(const std::string& peca) override;
        bool testar_vitoria(const std::string& peca) override;
        void auxiliar_tutorial(const std::string& peca, int linha, int coluna); // Função auxiliar para o tutorial de Jogo da Velha
};

#endif