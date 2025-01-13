#include "Estatisticas/Estatisticas.hpp"

Estatisticas::Estatisticas() { 
    atualizar_ranking(); //garante que ao inicializar o vector estará limpo e atualizado
}

void Estatisticas::atualizar_ranking() {
    std::list<Jogador*> lista_auxiliar = acessar_jogadores.get_jogadores(); 
    
    // Limpar o vetor antes de preenchê-lo novamente
    ranking_jogadores.clear();
    ranking_jogadores.assign(std::make_move_iterator(std::begin(lista_auxiliar)), 
                             std::make_move_iterator(std::end(lista_auxiliar)));
}

void Estatisticas::estatisticas_jogos(){ //main chama apenas essa função e o jogador opta pelo que preferir:
    Validacao validar_entrada_ranking;
    
    std::cout << "Querido jogador, você optou por ver as estatisticas do jogo." << std::endl 
              << "Visando atender melhor seu pedido, por favor selecione mais especificamente o que gostaria de ver"  
              << "(tecle o número correspondente a sua escolha)" << std::endl;

    std::cout << "(1) Para listar todos os jogadores e seus dados" << std::endl 
              << "(2) Para ver o ranking geral (todos os jogos)." << std::endl
              << "(3) Para acessar o ranking do jogo Reversi." << std::endl
              << "(4) Para acessar o ranking do jogo Lig4." <<  std::endl
              << "(5) Para acessar o ranking do Jogo da Velha." << std::endl;

    int escolha;
    std::cin >> escolha;

    while (true) {
        switch (escolha) {
            case '1':
                listar_jogadores();
                break;

            case '2':
                ranking_geral();
                break;

            case '3':
                ranking_reversi();
                break;

            case '4':
                ranking_lig4();
                break;
            
            case '5':
                ranking_jogovelha();
                break;

            default:
                validar_entrada_ranking.imprimir_erro("Parece que você digitou uma opção inválida, tente novamente:");
                continue; 
        }
        break; // Sai do while quando o switch processa um caso válido
    }

};

void Estatisticas::listar_jogadores(){
    
    for (const auto& jogador : acessar_jogadores.get_jogadores()) {
            std::cout << "Jogador: " << jogador->get_apelido() << " " << jogador->get_nome() << std::endl;

            std::cout << "Vitorias totais: " << jogador->get_vitorias_totais() << " "
                      << "Derrotas totais: " << jogador->get_derrotas_totais() << " "
                      << "Empates totais: " << jogador->get_empates_totais() << std::endl;

            std::cout << "Reversi V: " << jogador->get_Reversi().vitorias
                << " D: " << jogador->get_Reversi().derrotas
                << "E: " << jogador->get_Reversi().empates
                << "P: " << jogador->get_Reversi().pontos_por_jogo << std::endl;

            std::cout << "Lig4 V:" << jogador->get_Lig4().vitorias
                << " D:" << jogador->get_Lig4().derrotas 
                << "E: " << jogador->get_Lig4().empates
                << "P: " << jogador->get_Lig4().pontos_por_jogo << std::endl;

            std::cout << "Velha V:" << jogador->get_JogoVelha().vitorias
                << " D:" << jogador->get_JogoVelha().derrotas
                << "E: " << jogador->get_JogoVelha().empates
                << "P: " << jogador->get_JogoVelha().pontos_por_jogo << std::endl;

            std::cout << std::endl; 
        }
};


void Estatisticas::ranking_geral(){
    atualizar_ranking();

    std::sort(ranking_jogadores.begin(), ranking_jogadores.end(), [](Jogador* a, Jogador* b) {
        if(a->get_pontos_totais() != b->get_pontos_totais()){ //se os pontos sao !=, ordena por eles
             return  a->get_pontos_totais() > b->get_pontos_totais();
        }
        else { //se forem igauis, vai pros proximos requisitos:

            if(a->get_vitorias_totais() != b->get_vitorias_totais()){ //se o num vitorias for diferente usa isso:
                    return a->get_vitorias_totais() > b->get_vitorias_totais();
            }
            else{ //se o num de vitorias for igual, prossegue

                if(a->get_derrotas_totais() != b->get_derrotas_totais()){ //olha qm tem neos derrotas
                    return a->get_derrotas_totais() < b->get_derrotas_totais();
                }
                else{// por fim, caso precise, recorremos a ordem alfabética
                    return a->get_nome() < b->get_nome();
                }
            }
        }
    });

    imprimir_ranking(ranking_jogadores);
    
}


void Estatisticas::ranking_reversi(){
   atualizar_ranking();
   std::sort(ranking_jogadores.begin(), ranking_jogadores.end(), [](Jogador* a, Jogador* b) {

        if(a->get_Reversi().pontos_por_jogo != b->get_Reversi().pontos_por_jogo){ 
             return  a->get_Reversi().pontos_por_jogo > b->get_Reversi().pontos_por_jogo;
        }
        else { 

            if(a->get_Reversi().vitorias != b->get_Reversi().vitorias){ 
                    return a->get_Reversi().vitorias > b->get_Reversi().vitorias;
            }
            else{ 

                if(a->get_Reversi().derrotas != b->get_Reversi().derrotas){ //olha qm tem neos derrotas
                    return a->get_Reversi().derrotas < b->get_Reversi().derrotas;
                }
                else{// por fim, caso precise, recorremos a ordem alfabética
                    return a->get_nome() < b->get_nome();
                }
            }
        }
    });
   imprimir_ranking(ranking_jogadores);
};

void Estatisticas::ranking_lig4(){
    atualizar_ranking();

    std::sort(ranking_jogadores.begin(), ranking_jogadores.end(), [](Jogador* a, Jogador* b) {
    
        if(a->get_Lig4().pontos_por_jogo != b->get_Lig4().pontos_por_jogo){ 
             return  a->get_Lig4().pontos_por_jogo > b->get_Lig4().pontos_por_jogo;
        }
        else { 

            if(a->get_Lig4().vitorias != b->get_Lig4().vitorias){ 
                    return a->get_Lig4().vitorias > b->get_Lig4().vitorias;
            }
            else{ 

                if(a->get_Lig4().derrotas != b->get_Lig4().derrotas){ //olha qm tem neos derrotas
                    return a->get_Lig4().derrotas < b->get_Lig4().derrotas;
                }
                else{// por fim, caso precise, recorremos a ordem alfabética
                    return a->get_nome() < b->get_nome();
                }
            }
        }
    });

    imprimir_ranking(ranking_jogadores);
};

void Estatisticas::ranking_jogovelha(){
    atualizar_ranking();

     std::sort(ranking_jogadores.begin(), ranking_jogadores.end(), [](Jogador* a, Jogador* b) {
    
        if(a->get_JogoVelha().pontos_por_jogo != b->get_JogoVelha().pontos_por_jogo){ 
             return  a->get_JogoVelha().pontos_por_jogo > b->get_JogoVelha().pontos_por_jogo;
        }
        else { 

            if(a->get_JogoVelha().vitorias != b->get_JogoVelha().vitorias){ 
                    return a->get_JogoVelha().vitorias > b->get_JogoVelha().vitorias;
            }
            else{ 

                if(a->get_JogoVelha().derrotas != b->get_JogoVelha().derrotas){ //olha qm tem neos derrotas
                    return a->get_JogoVelha().derrotas < b->get_JogoVelha().derrotas;
                }
                else{// por fim, caso precise, recorremos a ordem alfabética
                    return a->get_nome() < b->get_nome();
                }
            }
        }
    });

    imprimir_ranking(ranking_jogadores);
};

void Estatisticas::imprimir_ranking(std::vector<Jogador*> vetor_jogadores){
    int posicao = 1;
    for(auto jogador: vetor_jogadores){
        std::cout << posicao << ". " << jogador->get_apelido() << std::endl;
        posicao ++;
    }
};

Estatisticas::~Estatisticas() {
    for (auto jogador : ranking_jogadores) {
        delete jogador; 
    }
    ranking_jogadores.clear(); 
}

