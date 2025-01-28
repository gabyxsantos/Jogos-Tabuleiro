#include "Jogos/Jogo_da_velha.hpp"

Validacao validar_entrada_velha;

//Funções da classe Jogo_Da_Velha:
    Jogo_Da_Velha::Jogo_Da_Velha(){
        definir_tamanho_tabuleiro(3,3);
        inicializar_tabuleiro();

        int escolha;

        std::cout << "Escolha um formato para as peças:" << std::endl
                << "<1> Padrão" << std::endl
                << "<2> Peças coloridas" << std::endl;
        validar_entrada_velha.pedir_usuario(escolha);

        switch (escolha){
            case 1:
                this->pecas_coloridas = false;
                break;
            case 2:
                this->pecas_coloridas = true;
                break;
            default:
                validar_entrada_velha.imprimir_erro("Opção inválida. O formato padrão será usado.");
                this->pecas_coloridas = false;
        }
    }

    Jogo_Da_Velha::~Jogo_Da_Velha() {
        tabuleiro.clear();
    }


    std::string Jogo_Da_Velha::escolher_peca(const std::string& peca_oponente, bool colorido) {
        int peca_escolhida;
        std::string peca_excluida = remover_cor(peca_oponente);
        do {
            std::cout << "Escolha a sua peça: " << std::endl
                    << "<1> " << BOLD << PECA_X << RESET << std::endl
                    << "<2> " << BOLD << PECA_O << RESET << std::endl;
            validar_entrada_velha.pedir_usuario(peca_escolhida);

            if (peca_escolhida < 1 || peca_escolhida > 2) {
                validar_entrada_velha.imprimir_erro("Por favor, escolha uma peça válida.");
            } else {
                // Peça válida escolhida
                std::string peca = (peca_escolhida == 1) ? PECA_X : PECA_O;

                if (peca == peca_excluida) {
                    validar_entrada_velha.imprimir_erro("Essa peça já foi escolhida pelo oponente. Escolha outra.");
                } else {
                    // Escolher cor, se necessário
                    if (colorido) {
                        return escolher_cor(peca);
                    } else {
                        return std::string(BOLD) + peca + RESET;
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
            validar_entrada_velha.pedir_usuario(cor_escolhida);

            if (cor_escolhida < 1 || cor_escolhida > 8) {
                validar_entrada_velha.imprimir_erro("Por favor, escolha uma cor válida.");
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
            validar_entrada_velha.imprimir_erro("Coluna inválida!");
            return false;
        }
        if (linha < 1 || linha > linhas){
            validar_entrada_velha.imprimir_erro("Linha inválida!");
            return false;
        }
        if (tabuleiro[linha - 1][coluna - 1].compare(filler) != 0){
            validar_entrada_velha.imprimir_erro("Espaço ocupado!");
            return false;
        }
        return true;
    }
    void Jogo_Da_Velha::ler_jogada(const std::string& peca){
        int coluna, linha;
        while (true){
            std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
            validar_entrada_velha.pedir_usuario(coluna);
            std::cout << "Escolha uma linha (1-" << linhas << ") para colocar a peça " << peca << ": ";
            validar_entrada_velha.pedir_usuario(linha);
            if (verificar_jogada(linha,coluna)) {
                tabuleiro[linha - 1][coluna - 1] = peca;
                return;
            }
        }
    }
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
    }

    void Jogo_Da_Velha::auxiliar_tutorial(const std::string& peca, int linha, int coluna) {
        tabuleiro[linha - 1][coluna - 1] = peca;
        std::cout << "Peça " << peca << " foi inserida na posição (" << linha << ", " << coluna << ")." << std::endl;
    }