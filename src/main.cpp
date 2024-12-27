#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "Partida.hpp"

int main() {
    Lig_4 jogo;

    std::string jogador1, jogador2;
    std::string peca1, peca2;

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

    bool venceu = false;
    while (!venceu) {
        jogo.imprimir_tabuleiro();
        std::cout << nome_atual << " (" << jogador_atual << "), é sua vez!" << std::endl;
        jogo.ler_jogada(jogador_atual);

        if (jogo.testar_vitoria(jogador_atual)) {
            venceu = true;
            break;
        }

        // Troca de turno
        if (jogador_atual == peca1) {
            jogador_atual = peca2;
            nome_atual = jogador2;
        } else {
            jogador_atual = peca1;
            nome_atual = jogador1;
        }
    }

    jogo.finalizar_partida(nome_atual);
    return 0;
}
