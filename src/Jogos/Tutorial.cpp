#include "Jogos/Tutorial.hpp"


Validacao validar_entrada_tutorial;

void Tutorial::mostrar_opcoes_tutorial(){
    timer(1000);
    std::cout << "Escolha uma opção: " << std::endl
                << "<1> Ler regras do jogo" << std::endl
                << "<2> Simular jogo" << std::endl
                << "<3> Apresentar tutorial completo" << std:: endl
                << "<4> Voltar" << std:: endl;
    timer(1000);
    std::cout << "Digite uma das opções: ";
}


void Tutorial::iniciar_tutorial(int opcao_jogo){
    
    if (opcao_jogo == 1){ 
        timer(1000);
        timer(1000);
        std::cout << "Iniciar Tutorial: Jogo da velha";

        int entrada_tutorial_velha; 
        while(true){
            mostrar_opcoes_tutorial();
            validar_entrada_tutorial.pedir_usuario(entrada_tutorial_velha);
            if (entrada_tutorial_velha < 1 || entrada_tutorial_velha > 4){
                validar_entrada_tutorial.imprimir_erro("Por favor, escolha uma opção válida.");
            }else if (entrada_tutorial_velha == 4) break;
            else{
                switch(entrada_tutorial_velha){
                    case 1: imprimir_regras_jogo_da_velha(); break;
                    case 2: iniciar_tutorial_jogo_da_velha(); break;
                    case 3: 
                        std::cout << "Apresentando tutorial completo: regras e simulação"<< std::endl;
                        imprimir_regras_jogo_da_velha(); iniciar_tutorial_jogo_da_velha(); break;
                }
                
            }
        }
    }

    else if (opcao_jogo == 2){ 
        timer(1000);
        timer(1000);
        std::cout << "Iniciar Tutorial: Lig 4";

        int entrada_tutorial_lig4; 
        while(true){
            mostrar_opcoes_tutorial();
            validar_entrada_tutorial.pedir_usuario(entrada_tutorial_lig4);
            if (entrada_tutorial_lig4 < 1 || entrada_tutorial_lig4 > 4){
                validar_entrada_tutorial.imprimir_erro("Por favor, escolha uma opção válida.");
            }else if (entrada_tutorial_lig4 == 4) break;
            else{
                switch(entrada_tutorial_lig4){
                    case 1: imprimir_regras_lig4(); break;
                    case 2: iniciar_tutorial_lig4(); break;
                    case 3: 
                        std::cout << "Apresentando tutorial completo: regras e simulação"<< std::endl;
                        imprimir_regras_lig4(); iniciar_tutorial_lig4(); break;
                }
                
            }
        }
    }

    else if (opcao_jogo == 3){ 
        timer(1000);
        timer(1000);
        std::cout << "Iniciar Tutorial: Reversi";

        int entrada_tutorial_reversi; 
        while(true){
            mostrar_opcoes_tutorial();
            validar_entrada_tutorial.pedir_usuario(entrada_tutorial_reversi);
            if (entrada_tutorial_reversi < 1 || entrada_tutorial_reversi > 4){
                validar_entrada_tutorial.imprimir_erro("Por favor, escolha uma opção válida.");
            }else if (entrada_tutorial_reversi == 4) break;
            else{
                switch(entrada_tutorial_reversi){
                    case 1: imprimir_regras_reversi(); break;
                    case 2: iniciar_tutorial_reversi(); break;
                    case 3: 
                        std::cout << "Apresentando tutorial completo: regras e simulação"<< std::endl;
                        imprimir_regras_reversi(); iniciar_tutorial_reversi(); break;
                }
                
            }
        }
    }

    else if (opcao_jogo == 4){ 
        timer(1000);
        timer(1000);
        std::cout << "Iniciar Tutorial: Batalha Naval";

        int entrada_tutorial_bat; 
        while(true){
            mostrar_opcoes_tutorial();
            validar_entrada_tutorial.pedir_usuario(entrada_tutorial_bat);
            if (entrada_tutorial_bat < 1 || entrada_tutorial_bat > 4){
                validar_entrada_tutorial.imprimir_erro("Por favor, escolha uma opção válida.");
            }else if (entrada_tutorial_bat == 4) break;
            else{
                switch(entrada_tutorial_bat){
                    case 1: imprimir_regras_batalha_naval(); break;
                    case 2: std::cout << "Para a Batalha Naval, não temos simulação disponível!"<< std::endl; break;
                    case 3: 
                        std::cout << "Apresentando tutorial completo: regras"<< std::endl;
                        imprimir_regras_batalha_naval(); 
                        std::cout << "Para a Batalha Naval, não temos simulação disponível!"<< std::endl;
                        break;
                }
                
            }
        }
    }

    else validar_entrada_tutorial.imprimir_erro("Erro interno! Parâmetro de função incorreto! Função: iniciar_tutorial.");
}

// TUTORIAL BATALHA NAVAL
void Tutorial::imprimir_regras_batalha_naval() {
    std::cout << "Regras da Batalha Naval:" << std::endl;
    std::cout << "1. Os jogadores escolhem o limite de jogadas e cada jogador posiciona seus navios no tabuleiro sem que o adversário veja." << std::endl;
    std::cout << "2. O objetivo é acertar e afundar todos os navios do oponente antes que ele faça o mesmo." << std::endl;
    std::cout << "3. No seu turno, escolha uma coordenada para atacar (linha e colona)." << std::endl;
    std::cout << "4. O sistema irá te informar se o ataque foi um sucesso ou se não acertou nenhum navio." << std::endl;
    std::cout << "5. O jogo termina quando todos os navios de um jogador são afundados ou de acordo com a quantidade de jogadas informadas." << std::endl;
    timer(5000);
}
//TUTORIAL LIG4: 
void Tutorial::imprimir_regras_lig4() {
    std::cout << "Regras do Lig4:"<< std::endl;
    std::cout << "1. O objetivo do jogo é alinhar 4 peças consecutivas na horizontal, vertical ou diagonal." << std::endl;
    std::cout << "2. Jogadores se alternam para colocar suas peças em uma das colunas do tabuleiro." << std::endl;
    std::cout << "3. A primeira pessoa a alinhar 4 peças vence." << std::endl;
    timer(5000);
}
void Tutorial::iniciar_tutorial_lig4() {
    std::cout << "Para que o tutorial funcione corretamente, por favor, insira o tamanho do tabuleiro (6 x 7) do Lig4." << std::endl;
    do {
        Lig_4 lig4;
        
        lig4.definir_filler(VOID);
        lig4.inicializar_tabuleiro();
        if(lig4.get_linhas() != 6 || lig4.get_colunas() != 7){
            std::cout << "Tamanho do tabuleiro inválido. Por favor, insira o tamanho correto (6x7)." << std::endl;
            continue;
        }
        else {

            std::cout << "Iniciando o tutorial do Lig 4..." << std::endl;
            std::cout << "O tutorial a seguir é um exemplo de implementação do jogo Lig4. Todas as informações serão fornecidas"
                    << " pela própria maquina e você não precisa adicionar nada. É um tutorial, então alguns dados serão arbitrariamente" 
                    << " decididos pela máquina (o que não acontece no jogo real)." << std::endl;
            std::cout << "O jogador 1 usará a peça vermelha (" << PECA_VERMELHA << ") e o jogador 2  usará a peça amarela ("<< PECA_AMARELA ")"<<std::endl;
            timer(5000);
            const std::string PECA_1 = " 🔴"; 
            const std::string PECA_2 = " 🟡"; 
            std::cout << std::endl << "Jogador 1 insere peça na coluna 3." << std::endl;
            lig4.auxiliar_tutorial(PECA_1, 3);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 2 insere peça na coluna 1." << std::endl;
            lig4.auxiliar_tutorial(PECA_2, 1);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 1 insere peça na coluna 4." << std::endl;
            lig4.auxiliar_tutorial(PECA_1, 4);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 2 insere peça na coluna 7." << std::endl;
            lig4.auxiliar_tutorial(PECA_2, 7);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 1 insere peça na coluna 5." << std::endl;
            lig4.auxiliar_tutorial(PECA_1, 5);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 2 insere peça na coluna 2." << std::endl;
            lig4.auxiliar_tutorial(PECA_2, 2);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 1 insere peça na coluna 6." << std::endl;
            lig4.auxiliar_tutorial(PECA_1, 6);
            lig4.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 1 (🔴) venceu ao conectar 4 peças na horizontal na linha 2!" << std::endl;
            timer(5000);
            std::cout << std::endl << "Fim do tutorial. Pressione Enter para encerrar..." << std::endl;
            std::cin.ignore();
            break;
        } 
    } while (true);
}
//TUTORIAL JOGO DA VELHA: 
void Tutorial::imprimir_regras_jogo_da_velha() {
    std::cout << "Regras do Jogo da Velha:" << std::endl;
    timer(1000);
    std::cout << "1. O objetivo do jogo é alinhar 3 peças consecutivas na horizontal, vertical ou diagonal." << std::endl;
    timer(1000);
    std::cout << "2. Jogadores se alternam para colocar suas peças em uma das casas do tabuleiro." << std::endl;
    timer(1000);
    std::cout << "3. O primeiro jogador a alinhar 3 peças vence." << std::endl;
    timer(5000);
}
void Tutorial::iniciar_tutorial_jogo_da_velha() {
     std::cout << "Para que o tutorial funcione corretamente, por favor, insira o formato padrão para as peças." << std::endl;
    do{
        Jogo_Da_Velha jogo_da_velha;
        jogo_da_velha.definir_filler(VOID);
        jogo_da_velha.inicializar_tabuleiro();
        if(jogo_da_velha.pecas_coloridas == true) {
            std::cout << "Formato de peças inválido. Por favor, insira um formato válido (Formato padrão)." << std::endl;
            continue;

        } else {
            std::cout << "Iniciando o tutorial do Jogo da Velha..." << std::endl;
            std::cout << "O tutorial a seguir é um exemplo de implementação do Jogo da Velha. Todas as informações serão fornecidas"
                    << " pela própria maquina e você não precisa adicionar nada. É um tutorial, então alguns dados serão arbitrariamente" 
                    << " decididos pela máquina (o que não acontece no jogo real)." << std::endl;
            std::cout << "O jogador 1 usará a peça (X) e o jogador 2  usará a peça (O)"<<std::endl;
            timer(5000);
            std::cout << "Jogador 1 (X) faz sua jogada na posição (1, 1)." << std::endl;
            jogo_da_velha.auxiliar_tutorial(PECA_X, 1, 1);
            jogo_da_velha.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << "Jogador 2 (O) faz sua jogada na posição (1, 2)." << std::endl;
            jogo_da_velha.auxiliar_tutorial(PECA_O, 1, 2);
            jogo_da_velha.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << "Jogador 1 (X) faz sua jogada na posição (2, 2)." << std::endl;
            jogo_da_velha.auxiliar_tutorial(PECA_X, 2, 2);
            jogo_da_velha.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << "Jogador 2 (O) faz sua jogada na posição (1, 3)." << std::endl;
            jogo_da_velha.auxiliar_tutorial(PECA_O, 1, 3);
            jogo_da_velha.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << "Jogador 1 (X) faz sua jogada na posição (3, 3)." << std::endl;
            jogo_da_velha.auxiliar_tutorial(PECA_X, 3, 3);
            jogo_da_velha.imprimir_tabuleiro_tutorial();
            timer(2000);
            std::cout << std::endl << "Jogador 1 (X) venceu o jogo ao completar a diagonal principal!" << std::endl;
            timer(5000);
            std::cout << std::endl << "Fim do tutorial. Pressione Enter para encerrar..." << std::endl;
            std::cin.ignore(); 
            break;
        }
        
    } while (true);
}
//TUTORIAL REVERSI:
void Tutorial::imprimir_regras_reversi() {
    std::cout << "Regras do Reversi:" << std::endl;
    timer(1000);
    std::cout << "1. O objetivo do jogo é ter mais peças de sua cor no tabuleiro ao final da partida." << std::endl;
    timer(1000);
    std::cout << "2. Jogadores se alternam para colocar suas peças em uma das casas vazias do tabuleiro." << std::endl;
    timer(1000);
    std::cout << "3. Ao colocar uma peça, todas as peças do oponente que estiverem entre a peça recém-colocada e outra peça de sua cor são viradas." << std::endl;
    timer(1000);
    std::cout << "4. O jogo termina quando não há mais jogadas possíveis. O jogador com mais peças de sua cor vence." << std::endl;
    timer(5000);
}
void Tutorial::iniciar_tutorial_reversi() {
    Reversi reversi;
    reversi.definir_filler(VOID);
    reversi.definir_tamanho_tabuleiro(8, 8);
    reversi.inicializar_tabuleiro();

    std::cout << "Iniciando o tutorial do Reversi..." << std::endl;
    std::cout << "O tutorial a seguir é um exemplo de implementação do jogo Reversi. Todas as informações serão fornecidas"
              << " pela própria máquina e você não precisa adicionar nada. É um tutorial, então alguns dados serão arbitrariamente"
              << " decididos pela máquina (o que não acontece no jogo real)." << std::endl;
    std::cout << "O jogador 1 usará a peça vermelha (" << PECA_VERMELHA << ") e o jogador 2 usará a peça amarela (" << PECA_AMARELA << ")."
              << std::endl;
    timer(5000);

    const std::string PECA_1 = " 🔴"; 
    const std::string PECA_2 = " 🟡"; 

    // Jogadas válidas com capturas
    std::cout << "Jogador 1 (🔴) faz sua jogada na posição (3, 5)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 3, 5);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 2 (🟡) faz sua jogada na posição (2, 4)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 2, 4);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 1 (🔴) faz sua jogada na posição (4, 5)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 4, 5); 
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 2 (🟡) faz sua jogada na posição (5, 4)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 5, 4);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 1 (🔴) faz sua jogada na posição (3, 3)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 3, 3);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 2 (🟡) faz sua jogada na posição (6, 5)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 6, 5);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 1 (🔴) faz sua jogada na posição (2, 5)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 2, 5);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 2 (🟡) faz sua jogada na posição (5, 3)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 5, 3);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << "Jogador 1 (🔴) faz sua jogada na posição (4, 6)." << std::endl;
    reversi.auxiliar_tutorial(PECA_1, 4, 6);
    reversi.imprimir_tabuleiro_tutorial();
    timer(2000);

    std::cout << std::endl << "Jogador 1 (🔴) domina a maior parte do tabuleiro e vence!" << std::endl;
    timer(5000);
    std::cout << std::endl << "Fim do tutorial. Pressione Enter para encerrar..." << std::endl;
    std::cin.ignore();
}