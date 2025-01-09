#include "Jogos/Lig_4.hpp"

Validacao validar_entrada_lig4;

//Funções da classe Lig_4:
    Lig_4::Lig_4(){
        int escolha;
        std::cout << "Escolha o tamanho do tabuleiro:" << std::endl
                << "<1> Pequeno (4x5)" << std::endl
                << "<2> Padrão (6x7)" << std::endl
                << "<3> Grande (7x10)" << std::endl;
        validar_entrada_lig4.pedir_usuario(escolha);

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
                validar_entrada_lig4.imprimir_erro("Opção inválida. O tamanho padrão será usado.");
                definir_tamanho_tabuleiro(6, 7);
        }
        inicializar_tabuleiro();
    }

    std::string Lig_4::escolher_peca(const std::string& peca_excluida){
        std::cout << "Para esse jogo, por favor, não escolha a peça branca!" << std::endl;
        do{
            std::string peca = definir_cor(peca_excluida);
            if (peca.compare(PECA_BRANCO) == 0){
                validar_entrada_lig4.imprimir_erro("Para esse jogo, você não pode escolher a peça branca. Escolha uma peça válida");
            }
            else{
                return peca;
            }
        }while(true);
    }


    bool Lig_4::verificar_jogada(int linha,int coluna){
        if (coluna < 1 || coluna > colunas){
            validar_entrada_lig4.imprimir_erro("Coluna inválida!");
            return false;
        }
        if (linha != 0){ // Para Lig_4, sempre esperamos linha = 0
            validar_entrada_lig4.imprimir_erro("Linha inválida para este jogo!");
            return false;
        }
        if (tabuleiro[0][coluna - 1].compare(filler) != 0){
            validar_entrada_lig4.imprimir_erro("Coluna cheia!");
            return false;
        }
        return true;
    }


    void Lig_4::ler_jogada(const std::string& peca){
        int coluna;
        while (true){
            std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
            validar_entrada_lig4.pedir_usuario(coluna);
            if (verificar_jogada(0,coluna)) {
                for (int i = linhas - 1; i >= 0; --i) {
                    if (tabuleiro[i][coluna - 1].compare(filler) == 0) {
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

