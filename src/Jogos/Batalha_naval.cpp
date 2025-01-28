#include "Jogos/Batalha_naval.hpp"

Validacao validar_entrada_batalha_naval;

//Funções da classe Batalha Naval:
    Batalha_Naval::Batalha_Naval(){
        definir_tamanho_tabuleiro(20,20);
        inicializar_tabuleiro();
    }

    Batalha_Naval::~Batalha_Naval() {
        tabuleiro.clear(); // Libera o conteúdo do vetor
    }
    
    void Batalha_Naval::imprimir_tabuleiro(){
        std::cout << VOID;
        for (int j = 1; j <= 10; ++j){
            std::cout << "   " << j ; //Como o tabuleiro de batalha naval é maior, foi necessário modificar a impressão para a melhor experiência do usuário
        }
        for (int j = 11; j <= colunas; ++j){
            std::cout << "  " << j ;
        }
        std::cout << std::endl;

        for (int i = 0; i < linhas; ++i){
            std::cout << std::setw(2) << i + 1 << " |";
            for (int j = 0; j < colunas; ++j){
                std::cout << tabuleiro[i][j] << "|";
            }
            std::cout << std::endl;
        }
    };

    void Batalha_Naval::posicionar_navios(){
        std::cout << "Você possui 3 contratorpedeiros (3 casas), 2 encouraçados (5 casas) e 1 porta-aviões (7 casas) para posicionar." << std::endl;
        for(int i=1; i<4; i++){
            do{
        std::cout << "Escolha a posição do seu " << i << "° contratorpedeiro: " << CONTRATORPEDEIRO << std::endl;
            } while (!ler_posicao_inicial(CONTRATORPEDEIRO));
        }
        for(int i=1; i<3; i++){
            do{
        std::cout << "Escolha a posição do seu " << i << "° encouraçado: " << ENCOURACADO << std::endl;
            } while (!ler_posicao_inicial(ENCOURACADO));
        }
        do {
        std::cout << "Escolha a posição do seu porta-aviões: " << PORTA_AVIOES << std::endl;
        } while (!ler_posicao_inicial(PORTA_AVIOES));
    }

    bool Batalha_Naval::verificar_jogada(int linha,int coluna){
        if (coluna < 1 || coluna > colunas){
            validar_entrada_batalha_naval.imprimir_erro("Coluna inválida!");
            return false;
        }
        if (linha < 1 || linha > linhas){ 
            validar_entrada_batalha_naval.imprimir_erro("Linha inválida!");
            return false;
        }
        if (tabuleiro[linha][coluna].compare(PECA_X) == 0){
            validar_entrada_batalha_naval.imprimir_erro("Você já atacou essa posição!");
            return false;
        }
        return true;
    }

    bool Batalha_Naval::ler_posicao_inicial(const std::string& peca) {
    int coordenada_X=0, coordenada_Y=0, contador_X, contador_Y;
    contador_X=0; contador_Y=0;
    char orientacao;
    do {
    std::cout << "Informe a coordenada Y (linha) do centro do Navio : ";
        std::cin >> coordenada_Y;
    if (coordenada_Y < 1 || coordenada_Y > linhas){
        validar_entrada_batalha_naval.imprimir_erro("Linha inválida!");
    }
    } while (coordenada_Y < 1 || coordenada_Y > colunas);
    do {
    std::cout << "Informe a coordenada X (coluna) do centro do Navio: ";
        std::cin >> coordenada_X;
    if (coordenada_X < 1 || coordenada_X > colunas){
        validar_entrada_batalha_naval.imprimir_erro("Coluna inválida!");
    }
    } while (coordenada_X < 1 || coordenada_X > colunas);
    std::cout << "Informe a orientação do Navio <H> Horizontal  <V> Vertical: ";
    std::cin >> orientacao;

    // Verificar se a posição é válida de acordo com o navio
        if (peca==CONTRATORPEDEIRO){
    switch (orientacao){
    case 'v':
    case 'V': {
        if (coordenada_Y < 2 || coordenada_Y > 19){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_Y=coordenada_Y-2; contador_Y<=coordenada_Y; contador_Y++) tabuleiro [contador_Y][coordenada_X-1]= CONTRATORPEDEIRO;
        break;
    }
    case 'h':
    case 'H': {
        if (coordenada_X < 2 || coordenada_X > 19){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_X=coordenada_X-2; contador_X<=coordenada_X; contador_X++) tabuleiro [coordenada_Y-1][contador_X]= CONTRATORPEDEIRO;
    break;
            }
        }
    };
        if (peca==ENCOURACADO){
    switch (orientacao){
    case 'v':
    case 'V': {
        if (coordenada_Y < 3 || coordenada_Y > 18){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_Y=coordenada_Y - 3; contador_Y<=coordenada_Y+1; contador_Y++) tabuleiro [contador_Y][coordenada_X-1]= ENCOURACADO;
    break;
        }
    case 'h':
    case 'H': {
        if (coordenada_X < 3 || coordenada_X > 18){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_X=coordenada_X - 3; contador_X<=coordenada_X+1; contador_X++) tabuleiro [coordenada_Y-1][contador_X]= ENCOURACADO;
    break;
        }
    }
};
        if (peca==PORTA_AVIOES){
    switch (orientacao){
    case 'v':
    case 'V': {
        if (coordenada_Y < 4 || coordenada_Y > 17){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_Y=coordenada_Y - 4; contador_Y<=coordenada_Y+2; contador_Y++) tabuleiro [contador_Y][coordenada_X-1]= PORTA_AVIOES;
    break;
        };
    case 'h':
    case 'H': {
        if (coordenada_X < 4 || coordenada_X > 17){
            validar_entrada_batalha_naval.imprimir_erro("Posição inválida!");
            return false;
        }
        for (contador_X=coordenada_X - 4; contador_X<=coordenada_X+2; contador_X++) tabuleiro [coordenada_Y-1][contador_X]= PORTA_AVIOES;
    break;
        }
    }
}; 
return true;
    };
    /*bool Batalha_Naval::testar_vitoria(const std::string& peca){
        for (int i = 0; i < linhas; ++i){
            for (int j = 0; j <= colunas - 4; ++j){
                if (tabuleiro[i][j].compare(peca) == 0 && tabuleiro[i][j + 1].compare(peca) == 0 &&
                    tabuleiro[i][j + 2].compare(peca) == 0 && tabuleiro[i][j + 3].compare(peca) == 0){
                    return true;
                }
            }
        };
        return false;
    };*/

    bool Batalha_Naval::testar_vitoria(const std::string& peca){
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

    void Batalha_Naval::ler_jogada(const std::string& peca){
        int coluna;
        while (true){
            std::cout << "Escolha uma coluna (1-" << colunas << ") para colocar a peça " << peca << ": ";
            validar_entrada_batalha_naval.pedir_usuario(coluna);
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
    /*bool Batalha_Naval::verificar_jogada(int linha,int coluna){
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


    void Batalha_Naval::ler_jogada(const std::string& peca){
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


    bool Batalha_Naval::testar_vitoria(const std::string& peca){
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
    
    void Batalha_Naval::auxiliar_tutorial(const std::string& peca, int coluna) { // Função auxiliar para simular Lig4
        for (int i = linhas - 1; i >= 0; --i) {
            tabuleiro[i][coluna - 1] = peca;
            std::cout << "Peça " << peca << " foi inserida na coluna " << coluna << "." << std::endl;
            return;
        }
    }*/