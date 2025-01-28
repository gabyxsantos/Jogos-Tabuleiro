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
    
    void Batalha_Naval::set_pontos(int pontos_jogada){
        pontos_oponente += pontos_jogada;
    }

    int Batalha_Naval::get_pontos(){
        return pontos_oponente;
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
        if (tabuleiro[linha-1][coluna-1].compare(PECA_X) == 0){
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
        validar_entrada_batalha_naval.pedir_usuario(coordenada_Y); 
    if (coordenada_Y < 1 || coordenada_Y > linhas){
        validar_entrada_batalha_naval.imprimir_erro("Linha inválida!");
    }
    } while (coordenada_Y < 1 || coordenada_Y > colunas);
    do {
    std::cout << "Informe a coordenada X (coluna) do centro do Navio: ";
        validar_entrada_batalha_naval.pedir_usuario(coordenada_X);
    if (coordenada_X < 1 || coordenada_X > colunas){
        validar_entrada_batalha_naval.imprimir_erro("Coluna inválida!");
    }
    } while (coordenada_X < 1 || coordenada_X > colunas);
    do {
    std::cout << "Informe a orientação do Navio <H> Horizontal  <V> Vertical: ";
    validar_entrada_batalha_naval.pedir_usuario(orientacao);
    if (orientacao != 'V' && orientacao != 'v' && orientacao != 'H' && orientacao != 'h'){
        validar_entrada_batalha_naval.imprimir_erro("Orientação inválida!");
    }
    } while (orientacao != 'V' && orientacao != 'v' && orientacao != 'H' && orientacao != 'h');

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

    void Batalha_Naval::ler_jogada(const std::string& peca){
        int coluna, linha;
        while (true){
            std::cout << "Escolha uma coluna (1-" << colunas << ") para atacar: ";
            validar_entrada_batalha_naval.pedir_usuario(coluna);
            std::cout << "Escolha uma linha (1-" << linhas << ") para atacar: ";
            validar_entrada_batalha_naval.pedir_usuario(linha);
            if (verificar_jogada(linha,coluna)) {
                    if (tabuleiro[linha-1][coluna-1].compare(AGUA) == 0){
                        tabuleiro[linha-1][coluna-1] = PECA_X;
                        std::cout << "Você não acertou nenhum navio inimigo!" << std::endl;
                        break;
                    }
                    if (tabuleiro[linha-1][coluna-1].compare(CONTRATORPEDEIRO) == 0){
                        tabuleiro[linha-1][coluna-1] = PECA_X;
                        std::cout << "Você acertou um contratorpedeiro inimigo! +2 pontos" << std::endl;
                        set_pontos(2);
                        break;
                    }
                    if (tabuleiro[linha-1][coluna-1].compare(ENCOURACADO) == 0){
                        tabuleiro[linha-1][coluna-1] = PECA_X;
                        std::cout << "Você acertou um encouraçado inimigo! +5 pontos" << std::endl;
                        set_pontos(5);
                        break;
                    }
                    if (tabuleiro[linha-1][coluna-1].compare(PORTA_AVIOES) == 0){
                        tabuleiro[linha-1][coluna-1] = PECA_X;
                        std::cout << "Você acertou um porta-aviões inimigo! +10 pontos" << std::endl;
                        set_pontos(10);
                        break;
                    }
            }
        }
    }

    std::string Batalha_Naval::comparar_pontuacoes(int pontos_jogador, const std::string& apelido_jogador, const std::string& apelido_adversario){
        if (pontos_jogador > pontos_oponente){
            std::cout << apelido_jogador << " ganhou de " << apelido_adversario << ", por " << pontos_jogador << " pontos, contra " << pontos_oponente << " pontos!" << std::endl;
            return apelido_jogador;
        }
        else if (pontos_jogador < pontos_oponente){
            std::cout << apelido_adversario << " ganhou de " << apelido_jogador << ", por " << pontos_oponente << " pontos, contra " << pontos_jogador << " pontos!" << std::endl;
            return apelido_adversario;
        }
    }

    bool Batalha_Naval::testar_vitoria(const std::string& peca){
        return true;
    }