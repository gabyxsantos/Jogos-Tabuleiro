#include "Tutorial.hpp"

// TUTORIAL LIG4: 
//funcao auxiliar para simular o tutorial de lig4
void simular_lig4(){
    Lig_4 rodada_tutorial;
    std::string jogador1 = "Jogador 1"; 
    std::string jogador2 = "Jogador 2"; 
    std::string cor1, cor2; 
    std::string peca1, peca2; 
    bool jogo_ativo = true;
    int turno = 0; 

    //definir cores 
    cor1 = rodada_tutorial.definir_cor("");
    cor2 = rodada_tutorial.definir_cor("cor1"); 
    peca1 = (cor1 == PECA_VERMELHA) ? PECA_VERMELHA : PECA_AMARELA; 
    peca2 = (cor2 == PECA_VERMELHA) ? PECA_VERMELHA : PECA_AMARELA;

    while (jogo_ativo) {
        rodada_tutorial.imprimir_tabuleiro(); 

        if (turno % 2 == 0) {
            std::cout << jogador1 << " (" << peca1 << ") é a sua vez!" << std::endl;
            rodada_tutorial.ler_jogada(peca1); 
            if(rodada_tutorial.testar_vitoria(peca1)) {
                rodada_tutorial.finalizar_partida_vencedor(jogador1);
                break;
            }
        }  else {
            std::cout << jogador2 << " (" << peca2 << ") é a sua vez!" << std::endl;
            rodada_tutorial.ler_jogada(peca2);
            if (rodada_tutorial.testar_vitoria(peca2)) {
                rodada_tutorial.finalizar_partida_vencedor(jogador2);
                break;
            }
        }

        if (rodada_tutorial.tabuleiro_cheio()) {
            rodada_tutorial.finalizar_partida_empate();
            break;
        }

        turno++;

    }
} 

//imprime as regras do jogo lig4
void Tutorial::imprimir_regras_lig4() {
    std::cout << "Regras do Lig4:"<< std::endl;
    std::cout << "1. O objetivo do jogo é alinhar 4 peças consecutivas na horizontal, vertical ou diagonal." << std::endl;
    std::cout << "2. Jogadores se alternam para colocar suas peças em uma das colunas do tabuleiro." << std::endl;
    std::cout << "3. A primeira pessoa a alinhar 4 peças vence." << std::endl;
    timer(5000);
}

//tutorial para o jogo lig4
void Tutorial::iniciar_tutorial_lig4() {
    Lig_4 lig4;
    lig4.definir_tamanho_tabuleiro(6,7);
    lig4.inicializar_tabuleiro();

    std::cout << "Iniciando o tutorial do Lig 4..." << std::endl;
    std::cout << "O jogador 1 usará a peça vermelha (🔴) e o jogador 2  usará a peça amarela (🟡)"<<std::endl;

    std::cout << std::endl << "Jogador 1 insere peça na coluna 3..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🔴", 3);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 1..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🟡", 1);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 4..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🔴", 4);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 7..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🟡", 7);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 5..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🔴", 5);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 2 insere peça na coluna 2..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🟡", 2);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 insere peça na coluna 6..." << std::endl;
    timer(2000);
    simular_lig4(lig4, "🔴", 6);
    lig4.imprimir_tabuleiro();

    std::cout << std::endl << "Jogador 1 (🔴) venceu ao conectar 4 peças na horizontal na linha 2!" << std::endl;

    std::cout << std::endl << "Tutorial finalizado! Pressione Enter para encerrar..." << std::endl;
    std::cin.ignore();
}
// TUTORIAL JOGO DA VELHA: