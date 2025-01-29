#ifndef BATALHANAVAL_H
#define BATALHANAVAL_H

#include "Jogos/Jogos.hpp"

class Batalha_Naval : public Jogo_De_Tabuleiro {
    private:
        int pontos_oponente = 0; // como o mapa que o jogador cria na verdade é utilizado pelo seu oponente para jogar,
                                // os pontos obtidos são referentes ao jogador que joga com o mapa, e não àquele que criou o mapa.
    public:
        Batalha_Naval();
        ~Batalha_Naval();
        void imprimir_tabuleiro() override;
        void posicionar_navios();
        void set_pontos(int pontos_jogada);
        int get_pontos();
        bool ler_posicao_inicial(const std::string& peca);
        bool verificar_jogada(int linha, int coluna) override;
        void ler_jogada(const std::string& peca) override;
        std::string comparar_pontuacoes(int pontos_jogador, const std::string& apelido_jogador, const std::string& apelido_adversario);
        bool testar_vitoria(const std::string& peca) override;
};

#endif