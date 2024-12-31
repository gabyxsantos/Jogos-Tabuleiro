#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "Partida.hpp"

int main() { 

// Teste de implementação para Reversi /////////////////////////////////////////////////////
    Reversi jogo;

    std::string jogador1, jogador2;
    std::string peca1, peca2;

    // Obter os nomes dos jogadores
    std::cout << "Jogador 1, insira seu apelido:" << std::endl;
    std::cin >> jogador1;
    peca1 = jogo.definir_cor(" "); // O primeiro jogador escolhe a cor

    std::cout << "Jogador 2, insira seu apelido:" << std::endl;
    std::cin >> jogador2;
    peca2 = jogo.definir_cor(peca1); // O segundo jogador escolhe a cor diferente do primeiro

    //std::string nome_atual = jogador1;
    //std::string jogador_atual = peca1;

    // Inicializar o tabuleiro
    jogo.inicializar_tabuleiro();
    jogo.colocar_pecas_iniciais(peca1, peca2);

        int i=0;
        while(i < 28){
            jogo.mostrar_posicoes_possiveis(peca1, peca2);
            jogo.imprimir_tabuleiro();
            jogo.ler_jogada(peca1);
            std::cout << "ANTES DE CONVERTER "<< std::flush;
            jogo.converter_pecas(peca1, peca2);
            jogo.mostrar_posicoes_possiveis(peca2, peca1);
            jogo.imprimir_tabuleiro();
            jogo.ler_jogada(peca2);
            jogo.converter_pecas(peca2, peca1);
            i++;
        }
        if(jogo.testar_vitoria(peca1)) std::cout << "O Jogador 1 ganhou!";
        if(jogo.testar_vitoria(peca2)) std::cout << "O Jogador 2 ganhou!";

    return 0;
}
