#include "Jogos.hpp"

/*
//Funções da classe Peça:
void Peca::set_peca(){};
void Peca::set_X() {};
void Peca::set_Y() {};
void Peca::get_peca() {
    std::cout << peca;
};
void Peca::get_X() {};
void Peca::get_Y() {};
*/

// Podemos discutir se varias das funções da classe base precisam ser implementadas ou podemos deixa-las como virtuais puras, ja que a implementação muda de jogo pra jogo
/*
void Jogo_De_Tabuleiro::imprimir_menu(){
    std::cout << "Para iniciar partida, tecle <I> " << std::endl << "Para ver o tutorial do jogo, tecle <T> " << std::endl;
    };
void Jogo_De_Tabuleiro::inicializar_tabuleiro(){};
void Jogo_De_Tabuleiro::ler_jogada(){
    std::cout << "Insira a coordenada X (coluna) da próxima peça: " << std::endl;
    std::cin >> X;
};
void Jogo_De_Tabuleiro::ler_jogada(int y){
    std::cout << "Insira a coordenada Y (linha) da próxima peça: " << std::endl;
    std::cin >> Y;
};
bool Jogo_De_Tabuleiro::verificar_jogada(){
    if (X>tamanho_tabuleiro[0]||X<1){
        std::cout << "O tabuleiro escolhido tem "<< tamanho_tabuleiro[1] <<" colunas de dimensão. Por favor escolha um número entre 1 e "<< tamanho_tabuleiro[1];
        return true;
    }
    else return false;
};
bool Jogo_De_Tabuleiro::verificar_jogada(int y){
    if (Y>tamanho_tabuleiro[1]||Y<1) {
        std::cout << "O tabuleiro escolhido tem "<< tamanho_tabuleiro[0] <<" linhas de dimensão. Por favor escolha um número entre 1 e "<< tamanho_tabuleiro[0];
        return true;
    }
    else return false;
};
void Jogo_De_Tabuleiro::testar_vitoria(){};
void Jogo_De_Tabuleiro::finalizar_partida() {
    std::cout << "O jogo terminou em um empate.";
}
void Jogo_De_Tabuleiro::finalizar_partida(std::string apelido_jogador) {
    std::cout << "O jogador "<< apelido_jogador <<" ganhou o jogo.";
}
*/

/*
// A função a seguir é para tratamento de erros.
// Não implementei em lugar nenhum ainda, mas pode ser útil, ao fim
bool verificar_tipo(const std::string& entrada, T& valor) {
    std::istringstream stream(entrada);
    stream >> valor;

    // Verifica se houve falha na conversão ou se sobrou algo inesperado na entrada
    if (stream.fail() || !stream.eof()) {
        return false;
    }
    return true;
}
*/



//Funções da classe base Jogo_De_Tabuleiro:
// Funções para o tabuleiro
void Jogo_De_Tabuleiro::definir_tamanho_tabuleiro(int linhas, int colunas){
    this->linhas = linhas;
    this->colunas = colunas;
    tabuleiro.resize(linhas, std::vector<std::string>(colunas, "  "));
}

void Jogo_De_Tabuleiro::inicializar_tabuleiro(){
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), "  ");
    }
}

void Jogo_De_Tabuleiro::imprimir_tabuleiro(){
    std::cout << "   ";
    for (int j = 1; j <= colunas; ++j){
        std::cout << "  " << j;
    }
    std::cout << std::endl;

    for (int i = 0; i < linhas; ++i){
        std::cout << std::setw(2) << i + 1 << " |";
        for (int j = 0; j < colunas; ++j){
            std::cout << tabuleiro[i][j] << "|";
        }
        std::cout << std::endl;
    }
}

bool Jogo_De_Tabuleiro::tabuleiro_cheio(){
    for (const auto& linha : tabuleiro) {
        for (const auto& casa : linha) {
            if (casa == "  ") {
                return false;
            }
        }
    }
    return true;
}

// Funções para finalizar a partida
void Jogo_De_Tabuleiro::finalizar_partida_vencedor(const std::string& nome_vencedor){
    imprimir_tabuleiro();
    std::cout << GREEN << "Parabéns, " << nome_vencedor << "! Você venceu!" << RESET << std::endl;
}

void Jogo_De_Tabuleiro::finalizar_partida_empate(){
    imprimir_tabuleiro();
    std::cout << GREEN << "O jogo terminou em um empate!" << RESET << std::endl;
}

bool Jogo_De_Tabuleiro::testar_empate(const std::string& peca1, const std::string& peca2){
    return (!testar_vitoria(peca1)) && (!testar_vitoria(peca2)) && tabuleiro_cheio();
};

// Funções para tratamento de erros
void Jogo_De_Tabuleiro::imprimir_erro(const std::string& erro){
    std::cout << RED << "ERRO: " << erro << RESET << std::endl;
}

// Função para definição da cor da peça
std::string Jogo_De_Tabuleiro::definir_cor(const std::string& cor_excluida){
    int cor_escolhida;
    do{
        std::cout << "Escolha a cor de suas peças: " << std::endl
                  << RED << "<1> Vermelho " << PECA_VERMELHA << std::endl
                  << GREEN << "<2> Verde " << PECA_VERDE << std::endl
                  << YELLOW << "<3> Amarelo " << PECA_AMARELA << std::endl
                  << BLUE << "<4> Azul " << PECA_AZUL << std::endl
                  << MAGENTA << "<5> Magenta " << PECA_MAGENTA << std::endl
                  << ORANGE << "<6> Laranja " << PECA_LARANJA << std::endl
                  << BLACK << "<7> Preto " << PECA_PRETA << std::endl
                  << WHITE << "<8> Branco " << PECA_BRANCO << RESET << std::endl;
        std::cin >> cor_escolhida;
        
        if (cor_escolhida < 1 || cor_escolhida > 8){
            std::cout << "Por favor, escolha uma cor válida." << std::endl;
        } else{
            switch (cor_escolhida) {
                case 1: if (cor_excluida != PECA_VERMELHA) return PECA_VERMELHA; break;
                case 2: if (cor_excluida != PECA_VERDE) return PECA_VERDE; break;
                case 3: if (cor_excluida != PECA_AMARELA) return PECA_AMARELA; break;
                case 4: if (cor_excluida != PECA_AZUL) return PECA_AZUL; break;
                case 5: if (cor_excluida != PECA_MAGENTA) return PECA_MAGENTA; break;
                case 6: if (cor_excluida != PECA_LARANJA) return PECA_LARANJA; break;
                case 7: if (cor_excluida != PECA_PRETA) return PECA_PRETA; break;
                case 8: if (cor_excluida != PECA_BRANCO) return PECA_BRANCO; break;
            }
            std::cout << "Essa cor já foi escolhida pelo oponente. Escolha outra." << std::endl;
        }
    } while (true);
}


//Funções da classe Lig_4:
Lig_4::Lig_4(){
    int escolha;
    std::cout << "Escolha o tamanho do tabuleiro:" << std::endl
              << "<1> Pequeno (4x5)" << std::endl
              << "<2> Padrão (6x7)" << std::endl
              << "<3> Grande (7x10)" << std::endl;
    std::cin >> escolha;

    switch (escolha){
        case 1:
            definir_tamanho_tabuleiro(4, 5);
            break;
        case 2:
            definir_tamanho_tabuleiro(6, 7);
            break;
        case 3:
            definir_tamanho_tabuleiro(7, 10);
            break;
        default:
            std::cout << "Opção inválida. O tamanho padrão será usado." << std::endl;
            definir_tamanho_tabuleiro(6, 7);
    }
    inicializar_tabuleiro();
}


bool Lig_4::verificar_jogada(int linha,int coluna){
    if (coluna < 1 || coluna > colunas){
        imprimir_erro("Coluna inválida!");
        return false;
    }
    if (linha != 0){ // Para Lig_4, sempre esperamos linha = 0
        imprimir_erro("Linha inválida para este jogo!");
        return false;
    }
    if (tabuleiro[0][coluna - 1].compare("  ") != 0){
        imprimir_erro("Coluna cheia!");
        return false;
    }
    return true;
}


void Lig_4::ler_jogada(const std::string& peca){
    int coluna;
    while (true){
        std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
        std::cin >> coluna;
        if (verificar_jogada(0,coluna)) {
            for (int i = linhas - 1; i >= 0; --i) {
                if (tabuleiro[i][coluna - 1] == "  ") {
                    tabuleiro[i][coluna - 1] = peca;
                    return;
                }
            }
        }
    }
}


bool Lig_4::testar_vitoria(const std::string& peca){
    // Horizontal
    for (int i = 0; i < linhas; ++i){
        for (int j = 0; j <= colunas - 4; ++j){
            if (tabuleiro[i][j].compare(peca) == 0 && tabuleiro[i][j + 1].compare(peca) == 0 &&
                tabuleiro[i][j + 2].compare(peca) == 0 && tabuleiro[i][j + 3].compare(peca) == 0){
                return true;
            }
        }
    }
    // Vertical
    for (int j = 0; j < colunas; ++j){
        for (int i = 0; i <= linhas - 4; ++i){
            if (tabuleiro[i][j].compare(peca) == 0 && tabuleiro[i + 1][j].compare(peca) == 0 &&
                tabuleiro[i + 2][j].compare(peca) == 0 && tabuleiro[i + 3][j].compare(peca) == 0){
                return true;
            }
        }
    }
    // Diagonal (crescente)
    for (int i = 0; i <= linhas - 4; ++i){
        for (int j = 0; j <= colunas - 4; ++j){
            if (tabuleiro[i][j].compare(peca) == 0 && tabuleiro[i + 1][j + 1].compare(peca) == 0 &&
                tabuleiro[i + 2][j + 2].compare(peca) == 0 && tabuleiro[i + 3][j + 3].compare(peca) == 0){
                return true;
            }
        }
    }
    // Diagonal (decrescente)
    for (int i = 3; i < linhas; ++i){
        for (int j = 0; j <= colunas - 4; ++j){
            if (tabuleiro[i][j].compare(peca) == 0 && tabuleiro[i - 1][j + 1].compare(peca) == 0 &&
                tabuleiro[i - 2][j + 2].compare(peca) == 0 && tabuleiro[i - 3][j + 3].compare(peca) == 0){
                return true;
            }
        }
    }
    return false;
}


//Funções da classe Jogo_Da_Velha:
Jogo_Da_Velha::Jogo_Da_Velha(){
    definir_tamanho_tabuleiro(3,3);
    inicializar_tabuleiro();

    int escolha;

    std::cout << "Escolha um formato para as peças:" << std::endl
              << "<1> Padrão" << std::endl
              << "<2> Peças coloridas" << std::endl;
    std::cin >> escolha;

    switch (escolha){
        case 1:
            this->pecas_coloridas = false;
            break;
        case 2:
            this->pecas_coloridas = true;
            break;
        default:
            std::cout << "Opção inválida. O formato padrão será usado." << std::endl;
            this->pecas_coloridas = false;
    }
};


std::string Jogo_Da_Velha::escolher_peca(const std::string& peca_excluida, bool colorido) {
    int peca_escolhida;
    do {
        std::cout << "Escolha a sua peça: " << std::endl
                  << "<1> " << BOLD << PECA_X << RESET << std::endl
                  << "<2> " << BOLD << PECA_O << RESET << std::endl;
        std::cin >> peca_escolhida;

        if (peca_escolhida < 1 || peca_escolhida > 2) {
            std::cout << "Por favor, escolha uma peça válida." << std::endl;
        } else {
            // Peça válida escolhida
            std::string peca = std::string(BOLD) + ((peca_escolhida == 1) ? PECA_X : PECA_O) + RESET;

            if (peca == peca_excluida) {
                std::cout << "Essa peça já foi escolhida pelo oponente. Escolha outra." << std::endl;
            } else {
                // Escolher cor, se necessário
                if (colorido) {
                    return escolher_cor(peca);
                } else {
                    return peca;
                }
            }
        }
    } while (true);
}

std::string Jogo_Da_Velha::escolher_cor(const std::string& peca) {
    int cor_escolhida;
    do {
        std::cout << "Escolha a cor de suas peças: " << std::endl
                  << RED << "<1> Vermelho " << BOLD << peca << RESET << std::endl
                  << GREEN << "<2> Verde " << BOLD << peca << RESET << std::endl
                  << YELLOW << "<3> Amarelo " << BOLD << peca << RESET << std::endl
                  << BLUE << "<4> Azul " << BOLD << peca << RESET << std::endl
                  << MAGENTA << "<5> Magenta " << BOLD << peca << RESET << std::endl
                  << ORANGE << "<6> Laranja " << BOLD << peca << RESET << std::endl
                  << BLACK << "<7> Preto " << BOLD << peca << RESET << std::endl
                  << WHITE << "<8> Branco " << BOLD << peca << RESET << std::endl;
        std::cin >> cor_escolhida;

        if (cor_escolhida < 1 || cor_escolhida > 8) {
            std::cout << "Por favor, escolha uma cor válida." << std::endl;
        } else {
            // Escolher cor com base na entrada
            std::string cor;
            switch (cor_escolhida) {
                case 1: cor = RED; break;
                case 2: cor = GREEN; break;
                case 3: cor = YELLOW; break;
                case 4: cor = BLUE; break;
                case 5: cor = MAGENTA; break;
                case 6: cor = ORANGE; break;
                case 7: cor = BLACK; break;
                case 8: cor = WHITE; break;
            }
            // Retornar peça colorida (cor + peça + RESET)
            return cor + peca + RESET;
        }
    } while (true);
}


bool Jogo_Da_Velha::verificar_jogada(int linha, int coluna){
    if (coluna < 1 || coluna > colunas){
        imprimir_erro("Coluna inválida!");
        return false;
    }
    if (linha < 1 || linha > linhas){
        imprimir_erro("Linha inválida!");
        return false;
    }
    if (tabuleiro[linha - 1][coluna - 1].compare("  ") != 0){
        imprimir_erro("Espaço ocupado!");
        return false;
    }
    return true;
};
void Jogo_Da_Velha::ler_jogada(const std::string& peca){
    int coluna, linha;
    while (true){
        std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
        std::cin >> coluna;
        std::cout << "Escolha uma linha (1-" << linhas << ") para colocar a peça " << peca << ": ";
        std::cin >> linha;
        if (verificar_jogada(linha,coluna)) {
            tabuleiro[linha - 1][coluna - 1] = peca;
            return;
        }
    }
};
bool Jogo_Da_Velha::testar_vitoria(const std::string& peca){
    // Horizontal
    for (int i = 0; i < linhas; ++i){
        if (tabuleiro[i][0].compare(peca) == 0 && tabuleiro[i][1].compare(peca) == 0 &&
            tabuleiro[i][2].compare(peca) == 0){
            return true;
        }
    }
    // Vertical
    for (int j = 0; j < colunas; ++j){
        if (tabuleiro[0][j].compare(peca) == 0 && tabuleiro[1][j].compare(peca) == 0 &&
            tabuleiro[2][j].compare(peca) == 0){
            return true;
        }
    }
    // Diagonal (crescente) - pode apenas na principal, pegando a casa central
    if (tabuleiro[0][2].compare(peca) == 0 && tabuleiro[1][1].compare(peca) == 0 &&
        tabuleiro[2][0].compare(peca) == 0){
        return true;
    }

    // Diagonal (decrescente) - pode apenas na principal, pegando a casa central
    if (tabuleiro[0][0].compare(peca) == 0 && tabuleiro[1][1].compare(peca) == 0 &&
        tabuleiro[2][2].compare(peca) == 0){
        return true;
    }

    return false;
};

//Funções da classe Reversi:
Reversi::Reversi(){
    definir_tamanho_tabuleiro(8,8);
    inicializar_tabuleiro();
};
void Reversi::colocar_pecas_iniciais(std::string jogador1, std::string jogador2){
    this->tabuleiro[3][3] = jogador1;
    this->tabuleiro[4][4] = jogador1;
    this->tabuleiro[4][3] = jogador2;
    this->tabuleiro[3][4] = jogador2;
}
bool Reversi::verificar_jogada(int linha, int coluna){
    if (coluna < 1 || coluna > 8){
        imprimir_erro("Coluna inválida!");
        return false;
    }
    if (linha < 1 || linha > 8){
        imprimir_erro("Linha inválida!");
        return false;
    }
    if (tabuleiro[linha - 1][coluna - 1].compare(PECA_O) != 0){
        imprimir_erro("Movimento inválido!");
        return false;
    }
    return true;
};
void Reversi::ler_jogada(const std::string& peca){
    int coluna, linha;
    while (true){
        std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
        std::cin >> coluna;
        std::cout << "Escolha uma linha (1-" << linhas << ") para colocar a peça " << peca << ": ";
        std::cin >> linha;
            if (verificar_jogada(linha,coluna)) {
                tabuleiro[linha - 1][coluna - 1] = peca;
                Reversi::linha_ultima_jogada = (linha-1);
                Reversi::coluna_ultima_jogada = (coluna-1);
                return;
            }
    }
};
bool Reversi::testar_vitoria(const std::string& peca_1){
    int casas_jogador_1=0;
    int casas_vazias = 0;
    for (const auto& linha : tabuleiro) {
        for (const auto& casa : linha) {
            if (casa == peca_1) {
                casas_jogador_1++;
            }
            if (casa == "  ") {
                casas_vazias++;
            }
        }
    }
    if (casas_jogador_1 > (64-(casas_jogador_1+casas_vazias))) return true;
    else return false;
};
void Reversi::mostrar_posicoes_possiveis(std::string jogador1, std::string jogador2){
    for (int i = 0; i < 8; ++i){ //retira as posições do outro jogador
        for (int j = 0; j < 8; ++j){
            if (tabuleiro[i][j].compare(PECA_O) == 0) {
                tabuleiro[i][j] = "  ";
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
                    if (tabuleiro[i][j+1].compare("  ") == 0) {
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
                    if (tabuleiro[i][j-1].compare("  ") == 0) {
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
                    if (tabuleiro[i+1][j].compare("  ") == 0) {
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
                    if (tabuleiro[i-1][j].compare("  ") == 0) {
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
                    if (tabuleiro[confere_linha_diag-1][confere_coluna_diag+1].compare("  ") == 0) {
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
                    if (tabuleiro[confere_linha_diag-1][confere_coluna_diag-1].compare("  ") == 0) {
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
                    if (tabuleiro[confere_linha_diag+1][confere_coluna_diag-1].compare("  ") == 0) {
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
                    if (tabuleiro[confere_linha_diag+1][confere_coluna_diag+1].compare("  ") == 0) {
                                tabuleiro[confere_linha_diag+1][confere_coluna_diag+1] = PECA_O;
                    }
                }
            }
        }
    }
};
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
}; 


//Funções da classe Tutorial:
void Tutorial::iniciar_tutorial_lig4(){};
void Tutorial::iniciar_tutorial_reversi(){};
void Tutorial::iniciar_tutorial_jogo_da_velha(){};
void Tutorial::imprimir_regras_lig4(){};
void Tutorial::imprimir_regras_reversi(){};
void Tutorial::imprimir_regras_jogo_da_velha(){};