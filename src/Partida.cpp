#include "Partida.hpp"
#include "Cadastro.hpp"
#include "Jogos.hpp"

void Partida::iniciar_partida(){
    definir_jogadores();
    escolher_jogo();
};

void Partida::definir_jogadores(){

    std::cout << "Jogador 1, insira seu apelido:" << std::endl;
    std::cin >> apelido_jogador_1;
    std::cout << "Jogador 2, insira seu apelido:" << std::endl;
    std::cin >> apelido_jogador_2;
};

void Partida::escolher_jogo(){

    std::cout<< "Qual jogo vocês gostariam de jogar?" << std::endl << "Digite a letra correspondente a sua escolha:" <<std::endl;
    std::cout << "(R) Reversi" << std::endl;
    std::cout << "(L) Lig4" << std::endl;
    std::cout << "(V) Jogo da Velha" << std::endl;
    
    while (std::cin >> nome_do_jogo) {
        switch (nome_do_jogo) {
            case 'R':
            case 'r': 
                jogar_reversi();
                break;

            case 'L':
            case 'l': 
                jogar_lig_4();
                break;

            case 'V':
            case 'v': 
                jogar_reversi();
                break;

            default:
                std::cout << "Parece que você digitou uma opção inválida, tente novamente:" << std::endl;
                continue; 
        }
        break; // Sai do while quando o switch processa um caso válido
    }

   

};

void Partida::jogar_reversi(){

};

void Partida::jogar_jogo_da_velha(){
    Jogo_Da_Velha jogo2;
    std::string peca1, peca2;
    peca1 = jogo2.escolher_peca(" ", jogo2.pecas_coloridas); 
    peca2 = jogo2.escolher_peca(peca1, jogo2.pecas_coloridas);

    std::string nome_atual = apelido_jogador_1;
    std::string jogador_atual = peca1;

    // Inicializar o tabuleiro
    jogo2.inicializar_tabuleiro();

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        jogo2.imprimir_tabuleiro();

        // Informar o turno atual
        std::cout << nome_atual << " (" << jogador_atual << "), é sua vez!" << std::endl;

        // Ler a jogada do jogador atual
        jogo2.ler_jogada(jogador_atual);

        // Verificar vitória
        if (jogo2.testar_vitoria(jogador_atual)) {
            terminou = true;
            break;
        }

        // Verificar empate
        if (jogo2.testar_empate(peca1, peca2)) {
            terminou = true;
            empate = true;
            break;
        }

        // Trocar de turno
        if (jogador_atual == peca1) {
            jogador_atual = peca2;
            nome_atual = apelido_jogador_2;
        } else {
            jogador_atual = peca1;
            nome_atual = apelido_jogador_2;
        }
    }

    // Finalizar a partida
    if (empate) jogo2.finalizar_partida_empate();
    else jogo2.finalizar_partida_vencedor(nome_atual);

};

void Partida::jogar_lig_4(){
    Lig_4 jogo3;
    std::string peca1, peca2;
    Partida aux;

    std::cout<< "Jogador 1,:";
    peca1 = jogo3.definir_cor(" "); // O primeiro jogador escolhe a cor
    std::cout<< "Jogador 2,:";
    peca2 = jogo3.definir_cor(peca1); // O segundo jogador escolhe a cor diferente do primeiro

    jogo3.inicializar_tabuleiro();
    std::string jogador_atual = peca1;
    std::string nome_atual = apelido_jogador_1;

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        jogo3.imprimir_tabuleiro();

        // Informar o turno atual
        std::cout << nome_atual << " (" << jogador_atual << "), é sua vez!" << std::endl;

        // Ler a jogada do jogador atual
        jogo3.ler_jogada(jogador_atual);

        // Verificar vitória
        if (jogo3.testar_vitoria(jogador_atual)) {
            terminou = true;
            break;
        }

        // Verificar empate
        if (jogo3.testar_empate(peca1, peca2)) {
            terminou = true;
            empate = true;
            break;
        }

        // Trocar de turno
        if (jogador_atual == peca1) {
            jogador_atual = peca2;
            nome_atual = apelido_jogador_2;
        } else {
            jogador_atual = peca1;
            nome_atual = apelido_jogador_1;
        }
    }

    // Finalizar a partida
    if (empate) jogo3.finalizar_partida_empate();
    else jogo3.finalizar_partida_vencedor(nome_atual);
    
};

