#include "Partida.hpp"
#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "FuncoesGlobais.hpp"


void Partida::iniciar_partida(){
    definir_jogadores();
    escolher_jogo();
};

void Partida::definir_jogadores(){

    std::cout << "Jogador 1, insira seu apelido:" << std::endl;
    pedir_usuario(apelido_jogador_1); //será que set_apelido() também seria adequado nessa situação?
    std::cout << "Jogador 2, insira seu apelido:" << std::endl;
    pedir_usuario(apelido_jogador_2);
};

void Partida::escolher_jogo(){

    std::cout<< "Qual jogo vocês gostariam de jogar?" << std::endl << "Digite a letra correspondente a sua escolha:" <<std::endl;
    std::cout << "(R) Reversi" << std::endl;
    std::cout << "(L) Lig4" << std::endl;
    std::cout << "(V) Jogo da Velha" << std::endl;
    
    while (true) {
        pedir_usuario(nome_do_jogo);
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
                jogar_jogo_da_velha();
                break;

            default:
                imprimir_erro("Parece que você digitou uma opção inválida, tente novamente:");
                continue; 
        }
        break; // Sai do while quando o switch processa um caso válido
    }

   

};

void Partida::jogar_reversi(){
    Reversi jogo1;
    RegistroJogadores vencedor;
    RegistroJogadores perdedor;


    timer(1800);
    std::cout << "Vamos jogar Reversi!" << std::endl;
    timer(1800);

    std::string jogador1, jogador2;
    std::string peca1, peca2;

    jogo1.definir_filler(VOID);

    std::cout << apelido_jogador_1 << ":" << std::endl;
    peca1 = jogo1.definir_cor(" "); // O primeiro jogador escolhe a cor
    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_1 << std::endl << "Peça: " << peca1 << std::endl;
    timer(1800);

    std::cout << apelido_jogador_2 << ":" << std::endl;
    peca2 = jogo1.definir_cor(peca1); // O segundo jogador escolhe a cor diferente do primeiro
    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_2 << std::endl << "Peça: " << peca2 << std::endl;
    timer(1800);

    // Inicializar o tabuleiro
    jogo1.inicializar_tabuleiro();
    jogo1.colocar_pecas_iniciais(peca1, peca2);

    int i=0;
    while(i < 30){

        timer(1800);
        std::cout << apelido_jogador_1 << " (" << peca1 << "), é sua vez!" << std::endl;
        jogo1.mostrar_posicoes_possiveis(peca1, peca2);
        jogo1.imprimir_tabuleiro();
        jogo1.ler_jogada(peca1);
        jogo1.converter_pecas(peca1, peca2);

        timer(1800);
        std::cout << apelido_jogador_2 << " (" << peca2 << "), é sua vez!" << std::endl;
        jogo1.mostrar_posicoes_possiveis(peca2, peca1);
        jogo1.imprimir_tabuleiro();
        jogo1.ler_jogada(peca2);
        jogo1.converter_pecas(peca2, peca1);

        i++;
    }

    timer(1800);
    if(jogo1.testar_vitoria(peca1)){
        jogo1.imprimir_tabuleiro();
        timer(1800);
        std::cout << apelido_jogador_1 << " ganhou!" << std::endl;
        jogo1.atualizar_placar(apelido_jogador_1, apelido_jogador_2, "Reversi");
    
    }

    if(jogo1.testar_vitoria(peca2)){
        jogo1.imprimir_tabuleiro();
        timer(1800); 
        std::cout << apelido_jogador_2 << " ganhou!" << std::endl;
        jogo1.atualizar_placar(apelido_jogador_2, apelido_jogador_1, "Reversi");
    }

};

void Partida::jogar_jogo_da_velha(){
    Jogo_Da_Velha jogo2;
    
    timer(1800);
    std::cout << "Vamos jogar Jogo da Velha!" << std::endl;
    timer(1800);

    std::string peca1, peca2;

    jogo2.definir_filler(VOID);

    std::cout << apelido_jogador_1 << ":" << std::endl; 
    peca1 = jogo2.escolher_peca(" ", jogo2.pecas_coloridas);

    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_1 << std::endl << "Peça: " << peca1 << std::endl;
    timer(1800);

    std::cout << apelido_jogador_2 << ":" << std::endl; 
    peca2 = jogo2.escolher_peca(peca1, jogo2.pecas_coloridas);

    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_2 << std::endl << "Peça: " << peca2 << std::endl;
    timer(1800);

    std::string nome_atual = apelido_jogador_1;
    std::string jogador_atual = peca1;

    // Inicializar o tabuleiro
    jogo2.inicializar_tabuleiro();

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        timer(1800);
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
            nome_atual = apelido_jogador_1;
        }
    }

    // Finalizar a partida
    timer(1800);
    if (empate) {
        jogo2.finalizar_partida_empate();
        
    }
    else {
        jogo2.finalizar_partida_vencedor(nome_atual);
        
        if(nome_atual.compare(apelido_jogador_1) == 0){
            jogo2.atualizar_placar(apelido_jogador_1, apelido_jogador_2, "JogoVelha");
        }
         else{
            jogo2.atualizar_placar(apelido_jogador_2, apelido_jogador_1, "JogoVelha");
        }
    }

    

};

void Partida::jogar_lig_4(){
    Lig_4 jogo3;

    timer(1800);
    std::cout << "Vamos jogar Lig 4!" << std::endl;
    timer(1800);

    std::string peca1, peca2;
    Partida aux;

    jogo3.definir_filler(PECA_BRANCO);

    std::cout << apelido_jogador_1 << ":" << std::endl;
    peca1 = jogo3.escolher_peca(" "); // O primeiro jogador escolhe a cor
    
    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_1 << std::endl << "Peça: " << peca1 << std::endl;
    timer(1800);

    std::cout << apelido_jogador_2 << ":" << std::endl;
    peca2 = jogo3.escolher_peca(peca1); // O segundo jogador escolhe a cor diferente do primeiro

    timer(1800);
    std::cout << "Jogador: " << apelido_jogador_2 << std::endl << "Peça: " << peca2 << std::endl;
    timer(1800);

    jogo3.inicializar_tabuleiro();
    std::string jogador_atual = peca1;
    std::string nome_atual = apelido_jogador_1;

    bool terminou = false;
    bool empate = false;
    while (!terminou) {
        timer(1800);
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
    timer(1800);
    if (empate) {
        jogo3.finalizar_partida_empate();
    }
    else {
        jogo3.finalizar_partida_vencedor(nome_atual);
        
        if(nome_atual.compare(apelido_jogador_1) == 0){
            jogo3.atualizar_placar(apelido_jogador_1, apelido_jogador_2, "Lig4");
        }
         else{
            jogo3.atualizar_placar(apelido_jogador_2, apelido_jogador_1, "Lig4");
        }
        
    }
    
    
};

