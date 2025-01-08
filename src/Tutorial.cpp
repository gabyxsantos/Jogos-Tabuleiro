#include "Tutorial.hpp"


// TUTORIAL LIG4: 

// Imprime as regras do jogo lig4
void Tutorial::imprimir_regras_lig4() {
    std::cout << "Regras do Lig4:"<< std::endl;
    std::cout << "1. O objetivo do jogo é alinhar 4 peças consecutivas na horizontal, vertical ou diagonal." << std::endl;
    std::cout << "2. Jogadores se alternam para colocar suas peças em uma das colunas do tabuleiro." << std::endl;
    std::cout << "3. A primeira pessoa a alinhar 4 peças vence." << std::endl;
    timer(5000);
}

// Funcao auxiliar para simular o tutorial de lig4
void Tutorial::simular_lig4(Lig_4& jogo, const std::string& peca, int coluna){
    
    for (int i = jogo.get_linhas() - 1; i >= 0; --i) {
        if (jogo.get_tabuleiro()[i][coluna - 1].compare(jogo.get_filler()) == 0) {
            jogo.get_tabuleiro()[i][coluna - 1] = peca;
            return;
        }
    }
} 

// Tutorial para o jogo lig4
void Tutorial::iniciar_tutorial_lig4() {
    Lig_4 lig4;
    lig4.definir_tamanho_tabuleiro(6,7);
    lig4.inicializar_tabuleiro();

    std::cout << "Iniciando o tutorial do Lig 4..." << std::endl;
    std::cout << "O tutorial a seguir é um exemplo de implementação do jogo Lig4. Todas as informações serão fornecidas"
              << " pela própria maquina e você não precisa adicionar nada. É um tutorial, então alguns dados serão arbitrariamente" 
              << " decididos pela máquina (o que não acontece no jogo real)." << std::endl;
    std::cout << "O jogador 1 usará a peça vermelha (" << PECA_VERMELHA << ") e o jogador 2  usará a peça amarela ("<< PECA_AMARELA ")"<<std::endl;

    std::cout << std::endl << "Jogador 1 insere peça na coluna 3..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_VERMELHA, 3);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 1..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_AMARELA, 1);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 4..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_VERMELHA, 4);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 7..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_AMARELA, 7);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 5..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_VERMELHA, 5);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 2..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_AMARELA, 2);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 6..." << std::endl;
    timer(2000);
    simular_lig4(lig4, PECA_VERMELHA, 6);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 ("<< PECA_VERMELHA <<") venceu ao conectar 4 peças na horizontal na linha 2!" << std::endl;

    std::cout << std::endl << "Tutorial finalizado! Pressione Enter para encerrar..." << std::endl;
    std::cin.ignore();
}

// TUTORIAL REVERSI:
void Tutorial::imprimir_regras_reversi() {
    // Implementação vazia
}

void Tutorial::simular_reversi() {
    // Implementação vazia
}

void Tutorial::iniciar_tutorial_reversi() {
    // Implementação vazia
}

// TUTORIAL JOGO DA VELHA:
void Tutorial::simular_jogo_da_velha() {
    // Implementação vazia
}

void Tutorial::iniciar_tutorial_jogo_da_velha() {
    // Implementação vazia
}

void Tutorial::imprimir_regras_jogo_da_velha() {
    // Implementação vazia
}

