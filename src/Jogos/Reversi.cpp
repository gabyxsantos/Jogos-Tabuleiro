#include "Jogos/Reversi.hpp"

Validacao validar_entrada_reversi;

// Funções da classe Reversi
    Reversi::Reversi(){
        definir_tamanho_tabuleiro(8,8);
        inicializar_tabuleiro();
    }
    void Reversi::colocar_pecas_iniciais(std::string jogador1, std::string jogador2){
        this->tabuleiro[3][3] = jogador1;
        this->tabuleiro[4][4] = jogador1;
        this->tabuleiro[4][3] = jogador2;
        this->tabuleiro[3][4] = jogador2;
    }
    bool Reversi::verificar_jogada(int linha, int coluna){
        if (coluna < 1 || coluna > 8){
            validar_entrada_reversi.imprimir_erro("Coluna inválida!");
            return false;
        }
        if (linha < 1 || linha > 8){
            validar_entrada_reversi.imprimir_erro("Linha inválida!");
            return false;
        }
        if (tabuleiro[linha - 1][coluna - 1].compare(PECA_O) != 0){
            validar_entrada_reversi.imprimir_erro("Movimento inválido!");
            return false;
        }
        return true;
    }
    void Reversi::ler_jogada(const std::string& peca){
        int coluna, linha;
        while (true){
            std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
            validar_entrada_reversi.pedir_usuario(coluna);
            std::cout << "Escolha uma linha (1-" << linhas << ") para colocar a peça " << peca << ": ";
            validar_entrada_reversi.pedir_usuario(linha);
                if (verificar_jogada(linha,coluna)) {
                    tabuleiro[linha - 1][coluna - 1] = peca;
                    Reversi::linha_ultima_jogada = (linha-1);
                    Reversi::coluna_ultima_jogada = (coluna-1);
                    return;
                }
        }
    }
    bool Reversi::testar_vitoria(const std::string& peca_1){
        int casas_jogador_1=0;
        int casas_vazias = 0;
        for (const auto& linha : tabuleiro) {
            for (const auto& casa : linha) {
                if (casa == peca_1) {
                    casas_jogador_1++;
                }
                if (casa == filler) {
                    casas_vazias++;
                }
            }
        }
        if (casas_jogador_1 > (64-(casas_jogador_1+casas_vazias))) return true;
        else return false;
    }
    void Reversi::mostrar_posicoes_possiveis(std::string jogador1, std::string jogador2){
        for (int i = 0; i < 8; ++i){ //retira as posições do outro jogador
            for (int j = 0; j < 8; ++j){
                if (tabuleiro[i][j].compare(PECA_O) == 0) {
                    tabuleiro[i][j] = filler;
                }
            }
        }
        //Conferir linhas
        for (int i = 0; i < 8; ++i){ //itera pela esquerda
            for (int j = 0; j < 6; ++j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i][j+1].compare(jogador2) == 0){
                    while (tabuleiro[i][j+1].compare(jogador2) == 0 && j+2<8)
                    {
                        ++j; 
                        if (tabuleiro[i][j+1].compare(filler) == 0) {
                                    tabuleiro[i][j+1] = PECA_O;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 8; ++i){ //itera pela direita
            for (int j = 7; j > 1; --j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i][j-1].compare(jogador2) == 0){
                    while (tabuleiro[i][j-1].compare(jogador2) == 0 && j-2>=0)
                    {
                        --j; 
                        if (tabuleiro[i][j-1].compare(filler) == 0) {
                                    tabuleiro[i][j-1] = PECA_O;
                        }
                    }
                }
            }
        }
        //Conferir colunas
        for (int j = 0; j < 8; ++j){ //itera de cima para baixo
            for (int i = 0; i < 6; ++i){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i+1][j].compare(jogador2) == 0){
                    while (tabuleiro[i+1][j].compare(jogador2) == 0 && i+2<8)
                    {
                        ++i; 
                        if (tabuleiro[i+1][j].compare(filler) == 0) {
                                    tabuleiro[i+1][j] = PECA_O;
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 8; ++j){ //itera de baixo para cima
            for (int i = 7; i > 1; --i){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i-1][j].compare(jogador2) == 0){
                    while (tabuleiro[i-1][j].compare(jogador2) == 0 && i-2>=0)
                    {
                        --i; 
                        if (tabuleiro[i-1][j].compare(filler) == 0) {
                                    tabuleiro[i-1][j] = PECA_O;
                        }
                    }
                }
            }
        }

        //Conferir diagonais
        for (int i = 2; i < 8; ++i){ //diagonais inferior esquerda à superior direita:
            for (int j = 0; j < 6; ++j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i-1][j+1].compare(jogador2) == 0){
                    int confere_linha_diag = i;
                    int confere_coluna_diag = j;
                    while (tabuleiro[confere_linha_diag-1][confere_coluna_diag+1].compare(jogador2) == 0 && confere_linha_diag-2>=0 && confere_coluna_diag+2<8 )
                    {
                        --confere_linha_diag;
                        ++confere_coluna_diag;
                        if (tabuleiro[confere_linha_diag-1][confere_coluna_diag+1].compare(filler) == 0) {
                                    tabuleiro[confere_linha_diag-1][confere_coluna_diag+1] = PECA_O;
                        }
                    }
                }
            }
        }
        for (int i = 2; i < 8; ++i){ //diagonais inferior direita à superior esquerda:
            for (int j = 7; j >= 0; --j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i-1][j-1].compare(jogador2) == 0){
                    int confere_linha_diag = i;
                    int confere_coluna_diag = j;
                    while (tabuleiro[confere_linha_diag-1][confere_coluna_diag-1].compare(jogador2) == 0 && confere_linha_diag-2>=0 && confere_coluna_diag-2>=0)
                    {
                        --confere_linha_diag;
                        --confere_coluna_diag;
                        if (tabuleiro[confere_linha_diag-1][confere_coluna_diag-1].compare(filler) == 0) {
                                    tabuleiro[confere_linha_diag-1][confere_coluna_diag-1] = PECA_O;
                        }
                    }
                }
            }
        }
        for (int i = 0; i <6; ++i){ //diagonais superior direita à inferior esquerda:
            for (int j = 7; j > 1; --j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i+1][j-1].compare(jogador2) == 0){
                    int confere_linha_diag = i;
                    int confere_coluna_diag = j;
                    while (tabuleiro[confere_linha_diag+1][confere_coluna_diag-1].compare(jogador2) == 0 && confere_linha_diag+2<8 && confere_coluna_diag-2>=0)
                    {
                        ++confere_linha_diag;
                        --confere_coluna_diag;
                        if (tabuleiro[confere_linha_diag+1][confere_coluna_diag-1].compare(filler) == 0) {
                                    tabuleiro[confere_linha_diag+1][confere_coluna_diag-1] = PECA_O;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 6; ++i){ //diagonais superior esquerda à inferior direita:
            for (int j = 0; j < 6; ++j){
                if (tabuleiro[i][j].compare(jogador1) == 0 && tabuleiro[i+1][j+1].compare(jogador2) == 0){
                    int confere_linha_diag = i;
                    int confere_coluna_diag = j;
                    while (tabuleiro[confere_linha_diag+1][confere_coluna_diag+1].compare(jogador2) == 0 && confere_linha_diag+2<8 && confere_coluna_diag+2<8 ) 
                    {
                        ++confere_linha_diag;
                        ++confere_coluna_diag;
                        if (tabuleiro[confere_linha_diag+1][confere_coluna_diag+1].compare(filler) == 0) {
                                    tabuleiro[confere_linha_diag+1][confere_coluna_diag+1] = PECA_O;
                        }
                    }
                }
            }
        }
    }
    void Reversi::converter_pecas(std::string& peca_nova, std::string& peca_convertida){
        //CONFERINDO AS POSIÇÕES ABAIXO:
        if (linha_ultima_jogada<6){
            if (tabuleiro[linha_ultima_jogada+1][coluna_ultima_jogada].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                while (i<7 && tabuleiro[i+1][coluna_ultima_jogada].compare(peca_convertida) == 0){
                        ++i; 
                }
                if (i<7 && tabuleiro[i+1][coluna_ultima_jogada].compare(peca_nova) == 0){
                    while (tabuleiro[i][coluna_ultima_jogada].compare(peca_convertida) == 0){
                        tabuleiro[i][coluna_ultima_jogada] = peca_nova;
                        --i; 
                    }
                }
            }
        }
        //CONFERINDO AS POSIÇÕES ACIMA:
        if (linha_ultima_jogada>1){
            if (tabuleiro[linha_ultima_jogada-1][coluna_ultima_jogada].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                while (i>0 && tabuleiro[i-1][coluna_ultima_jogada].compare(peca_convertida) == 0){
                        --i; 
                }
                if (i>0 && tabuleiro[i-1][coluna_ultima_jogada].compare(peca_nova) == 0){
                    while (tabuleiro[i][coluna_ultima_jogada].compare(peca_convertida) == 0){
                        tabuleiro[i][coluna_ultima_jogada] = peca_nova;
                        ++i; 
                    }
                }
            }
        }
        //CONFERINDO AS POSIÇÕES À ESQUERDA:
        if (coluna_ultima_jogada>1){
            if (tabuleiro[linha_ultima_jogada][coluna_ultima_jogada-1].compare(peca_convertida) == 0){
                int i=coluna_ultima_jogada;
                while (i>0 && tabuleiro[linha_ultima_jogada][i-1].compare(peca_convertida) == 0){
                        --i; 
                }
                if (i>0 && tabuleiro[linha_ultima_jogada][i-1].compare(peca_nova) == 0){
                    while (tabuleiro[linha_ultima_jogada][i].compare(peca_convertida) == 0){
                        tabuleiro[linha_ultima_jogada][i] = peca_nova;
                        ++i; 
                    }
                }
            }
        }
        //CONFERINDO AS POSIÇÕES À DIREITA:
        if (coluna_ultima_jogada<6){
            if (tabuleiro[linha_ultima_jogada][coluna_ultima_jogada+1].compare(peca_convertida) == 0){
                int i=coluna_ultima_jogada;
                while (i<7 && tabuleiro[linha_ultima_jogada][i+1].compare(peca_convertida) == 0){
                        ++i; 
                }
                if (i<7 && tabuleiro[linha_ultima_jogada][i+1].compare(peca_nova) == 0){
                    while (tabuleiro[linha_ultima_jogada][i].compare(peca_convertida) == 0){
                        tabuleiro[linha_ultima_jogada][i] = peca_nova;
                        --i; 
                    }
                }
            }
        } 
        //CONFERINDO A DIAGONAL INFERIOR-ESQUERDO A SUPERIOR-DIREITO:
        if (coluna_ultima_jogada<6 && linha_ultima_jogada >1){ //col utl mais ou menos 1
            if (tabuleiro[linha_ultima_jogada-1][coluna_ultima_jogada+1].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                int j=coluna_ultima_jogada;
                while (i>0 && j<7 && tabuleiro[i-1][j+1].compare(peca_convertida) == 0){
                        --i;
                        ++j; 
                }
                if (i>0 && j<7 && tabuleiro[i-1][j+1].compare(peca_nova) == 0){
                    while (tabuleiro[i][j].compare(peca_convertida) == 0){
                        tabuleiro[i][j] = peca_nova;
                        ++i; 
                        --j;
                    }
                }
            }
        }
        //CONFERINDO A DIAGONAL SUPERIOR-DIREITO A INFERIOR-ESQUERDO:
        if (coluna_ultima_jogada>1 && linha_ultima_jogada <6){ //col utl mais ou menos 1
            if (tabuleiro[linha_ultima_jogada+1][coluna_ultima_jogada-1].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                int j=coluna_ultima_jogada;
                while (i<7 && j>0 && tabuleiro[i+1][j-1].compare(peca_convertida) == 0){
                        ++i;
                        --j; 
                }
                if (i<7 && j>0 && tabuleiro[i+1][j-1].compare(peca_nova) == 0){
                    while (tabuleiro[i][j].compare(peca_convertida) == 0){
                        tabuleiro[i][j] = peca_nova;
                        --i; 
                        ++j;
                    }
                }
            }
        }
        //CONFERINDO A DIAGONAL SUPERIOR-ESQUERDO A INFERIOR-DIREITO:
        if (coluna_ultima_jogada<6 && linha_ultima_jogada <6){ 
            if (tabuleiro[linha_ultima_jogada+1][coluna_ultima_jogada+1].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                int j=coluna_ultima_jogada;
                while (i<7 && j<7 && tabuleiro[i+1][j+1].compare(peca_convertida) == 0){
                        ++i;
                        ++j; 
                }
                if (i<7 && j<7 && tabuleiro[i+1][j+1].compare(peca_nova) == 0){
                    while (tabuleiro[i][j].compare(peca_convertida) == 0){
                        tabuleiro[i][j] = peca_nova;
                        --i; 
                        --j;
                    }
                }
            }
        }
        //CONFERINDO A DIAGONAL SUPERIOR-DIREITO A INFERIOR-ESQUERDO:
            if (coluna_ultima_jogada>1 && linha_ultima_jogada >1){ 
            if (tabuleiro[linha_ultima_jogada-1][coluna_ultima_jogada-1].compare(peca_convertida) == 0){
                int i=linha_ultima_jogada;
                int j=coluna_ultima_jogada;
                while (i>0 && j>0 && tabuleiro[i-1][j-1].compare(peca_convertida) == 0){
                        --i;
                        --j; 
                }
                if (i>0 && j>0 && tabuleiro[i-1][j-1].compare(peca_nova) == 0){
                    while (tabuleiro[i][j].compare(peca_convertida) == 0){
                        tabuleiro[i][j] = peca_nova;
                        ++i; 
                        ++j;
                    }
                }
            }
        }
    }

    void Reversi::auxiliar_tutorial(const std::string& peca, int linha, int coluna) {
        tabuleiro[linha - 1][coluna - 1] = peca;
        linha_ultima_jogada = linha - 1;
        coluna_ultima_jogada = coluna - 1;

        std::string peca_convertida = (peca == PECA_VERMELHA) ? PECA_AMARELA : PECA_VERMELHA;
        std::string peca_nova = peca;

        converter_pecas(peca_nova, peca_convertida);

        std::cout << "Peça " << peca << " foi inserida na posição (" << linha << ", " << coluna << ")." << std::endl;
    }