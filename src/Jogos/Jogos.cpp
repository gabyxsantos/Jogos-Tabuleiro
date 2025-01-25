#include "Jogos/Jogos.hpp"

Validacao validar_entrada_jogos;

//Funções da classe base Jogo_De_Tabuleiro:
    // Funções para o tabuleiro
    void Jogo_De_Tabuleiro::definir_filler(std::string filler){
        this->filler = filler;
    }
    
    void Jogo_De_Tabuleiro::definir_tamanho_tabuleiro(int linhas, int colunas){
        this->linhas = linhas;
        this->colunas = colunas;
        tabuleiro.resize(linhas, std::vector<std::string>(colunas, filler));
    }

    void Jogo_De_Tabuleiro::inicializar_tabuleiro(){
        for (auto& linha : tabuleiro) {
            std::fill(linha.begin(), linha.end(), filler);
        }
    }

    void Jogo_De_Tabuleiro::imprimir_tabuleiro(){
        std::cout << VOID;
        for (int j = 1; j <= colunas; ++j){
            std::cout << VOID << j;
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
                if (casa.compare(filler) == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Remove códigos ANSI da string
    std::string Jogo_De_Tabuleiro::remover_cor(const std::string& texto){
        // Expressão regular para capturar códigos de controle ANSI (que dão cor)
        std::regex ansi_regex("\\x1B\\[[0-9;]*[A-Za-z]");
        return std::regex_replace(texto, ansi_regex, "");
    }

    // Getters
    std::string Jogo_De_Tabuleiro::get_filler(){
        return Jogo_De_Tabuleiro::filler;
    }
    int Jogo_De_Tabuleiro::get_linhas(){
        return Jogo_De_Tabuleiro::linhas;
    }
    int Jogo_De_Tabuleiro::get_colunas(){
        return Jogo_De_Tabuleiro::colunas;
    }
    std::vector<std::vector<std::string>> Jogo_De_Tabuleiro::get_tabuleiro(){
        return Jogo_De_Tabuleiro::tabuleiro;
    }
    
    //Setters
    void Jogo_De_Tabuleiro::set_tabuleiro(std::vector<std::vector<std::string>> tabuleiro){
        this->tabuleiro = tabuleiro;
    }

    // Funções para finalizar a partida
    void Jogo_De_Tabuleiro::finalizar_partida_vencedor(const std::string& nome_vencedor){
        imprimir_tabuleiro();
        timer(1800);
        std::cout << GREEN << "Parabéns, " << nome_vencedor << "! Você venceu!" << RESET << std::endl;
    }

    void Jogo_De_Tabuleiro::finalizar_partida_empate(){
        imprimir_tabuleiro();
        timer(1800);
        std::cout << GREEN << "O jogo terminou em um empate!" << RESET << std::endl;
    }

    bool Jogo_De_Tabuleiro::testar_empate(const std::string& peca1, const std::string& peca2){
        return (!testar_vitoria(peca1)) && (!testar_vitoria(peca2)) && tabuleiro_cheio();
    }
    
    //Metodo para atualizar o placar:
    void Jogo_De_Tabuleiro::atualizar_placar(std::string apelido_vencedor, std::string apelido_perdedor, std::string jogo, CadastroJogadores& buscador){

        auto it = buscador.buscar_jogador(apelido_vencedor);
        auto it2 = buscador.buscar_jogador(apelido_perdedor);

        if(jogo.compare("Reversi") == 0){
            (*it)->set_Reversi(true);
            (*it2)->set_Reversi(false);
        }

        else if(jogo.compare("Lig4") == 0){
            (*it)->set_Lig4(true);
            (*it2)->set_Lig4(false);
        }

        else if (jogo.compare("JogoVelha") == 0){
            (*it)->set_JogoVelha(true);
            (*it2)->set_JogoVelha(false);
        }

    }

    void Jogo_De_Tabuleiro::atualizar_placar_empate(std::string j1, std::string j2, std::string jogo, CadastroJogadores &buscador){
            
        auto it = buscador.buscar_jogador(j1);
        (*it)->set_empates_totais();
        (*it)->set_pontos_totais(false);
        auto it2 = buscador.buscar_jogador(j2);
        (*it2)->set_empates_totais();
        (*it2)->set_pontos_totais(false);

        if(jogo.compare("Lig4") == 0){
            (*it)->set_Lig4();
            (*it2)->set_Lig4();
        }
        else if (jogo.compare("JogoVelha") == 0){
            (*it)->set_JogoVelha();
            (*it2)->set_JogoVelha();
        }
    };

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
            validar_entrada_jogos.pedir_usuario(cor_escolhida);
            
            if (cor_escolhida < 1 || cor_escolhida > 8){
                validar_entrada_jogos.imprimir_erro("Por favor, escolha uma cor válida.");
            } else{
                switch (cor_escolhida) {
                    case 1: if (cor_excluida.compare(PECA_VERMELHA) != 0) return PECA_VERMELHA; break;
                    case 2: if (cor_excluida.compare(PECA_VERDE) != 0) return PECA_VERDE; break;
                    case 3: if (cor_excluida.compare(PECA_AMARELA) != 0) return PECA_AMARELA; break;
                    case 4: if (cor_excluida.compare(PECA_AZUL) != 0) return PECA_AZUL; break;
                    case 5: if (cor_excluida.compare(PECA_MAGENTA) != 0) return PECA_MAGENTA; break;
                    case 6: if (cor_excluida.compare(PECA_LARANJA) != 0) return PECA_LARANJA; break;
                    case 7: if (cor_excluida.compare(PECA_PRETA) != 0) return PECA_PRETA; break;
                    case 8: if (cor_excluida.compare(PECA_BRANCO) != 0) return PECA_BRANCO; break;
                }
                validar_entrada_jogos.imprimir_erro("Essa cor já foi escolhida pelo oponente. Escolha outra.");
            }
        } while (true);
    }