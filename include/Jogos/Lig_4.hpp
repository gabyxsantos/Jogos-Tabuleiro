#ifndef LIG4_H
#define LIG4_H

#include "Jogos/Jogos.hpp"

class Lig_4 : public Jogo_De_Tabuleiro {
    public:
    Lig_4();

    std::string escolher_peca(const std::string& peca_excluida);
    bool verificar_jogada(int linha, int coluna) override;
    void ler_jogada(const std::string& peca) override;
    bool testar_vitoria(const std::string& peca) override;
    void auxiliar_tutorial(const std::string& peca, int coluna); // Função auxiliar para o tutorial de Lig4

};

#endif