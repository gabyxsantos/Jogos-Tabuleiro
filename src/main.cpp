#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "Partida.hpp"

int main() {
    
    /*
    // Teste de implementação para Lig 4
    Lig_4 jogo;

    std::string jogador1, jogador2;
    std::string peca1, peca2;

    // Obter os nomes dos jogadores
    std::cout << "Jogador 1, insira seu apelido:" << std::endl;
    std::cin >> jogador1;
    peca1 = jogo.definir_cor(" "); // O primeiro jogador escolhe a cor

    std::cout << "Jogador 2, insira seu apelido:" << std::endl;
    std::cin >> jogador2;
    peca2 = jogo.definir_cor(peca1); // O segundo jogador escolhe a cor diferente do primeiro

    std::string nome_atual = jogador1;
    std::string jogador_atual = peca1;

    // Inicializar o tabuleiro
    jogo.inicializar_tabuleiro();

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        jogo.imprimir_tabuleiro();

        // Informar o turno atual
        std::cout << nome_atual << " (" << jogador_atual << "), é sua vez!" << std::endl;

        // Ler a jogada do jogador atual
        jogo.ler_jogada(jogador_atual);

        // Verificar vitória
        if (jogo.testar_vitoria(jogador_atual)) {
            terminou = true;
            break;
        }

        // Verificar empate
        if (jogo.testar_empate(peca1, peca2)) {
            terminou = true;
            empate = true;
            break;
        }

        // Trocar de turno
        if (jogador_atual == peca1) {
            jogador_atual = peca2;
            nome_atual = jogador2;
        } else {
            jogador_atual = peca1;
            nome_atual = jogador1;
        }
    }

    // Finalizar a partida
    if (empate) jogo.finalizar_partida_empate();
    else jogo.finalizar_partida_vencedor(nome_atual);
    */

    /*
    // Teste de implementação para Jogo da Velha
    Jogo_Da_Velha jogo;

    std::string jogador1, jogador2;
    std::string peca1, peca2;

    // Obter os nomes dos jogadores
    std::cout << "Jogador 1, insira seu apelido:" << std::endl;
    std::cin >> jogador1;
    peca1 = jogo.escolher_peca(" ", jogo.pecas_coloridas); 

    std::cout << "Jogador 2, insira seu apelido:" << std::endl;
    std::cin >> jogador2;
    peca2 = jogo.escolher_peca(peca1, jogo.pecas_coloridas);

    std::string nome_atual = jogador1;
    std::string jogador_atual = peca1;

    // Inicializar o tabuleiro
    jogo.inicializar_tabuleiro();

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        jogo.imprimir_tabuleiro();

        // Informar o turno atual
        std::cout << nome_atual << " (" << jogador_atual << "), é sua vez!" << std::endl;

        // Ler a jogada do jogador atual
        jogo.ler_jogada(jogador_atual);

        // Verificar vitória
        if (jogo.testar_vitoria(jogador_atual)) {
            terminou = true;
            break;
        }

        // Verificar empate
        if (jogo.testar_empate(peca1, peca2)) {
            terminou = true;
            empate = true;
            break;
        }

        // Trocar de turno
        if (jogador_atual == peca1) {
            jogador_atual = peca2;
            nome_atual = jogador2;
        } else {
            jogador_atual = peca1;
            nome_atual = jogador1;
        }
    }

    // Finalizar a partida
    if (empate) jogo.finalizar_partida_empate();
    else jogo.finalizar_partida_vencedor(nome_atual);
    */


    return 0;
}
