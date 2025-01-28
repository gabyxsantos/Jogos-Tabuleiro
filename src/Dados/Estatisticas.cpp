#include "Dados/Estatisticas.hpp"

Estatisticas::Estatisticas(CadastroJogadores& buscador) 
    : acessar_jogadores(buscador) {
    atualizar_ranking(); //garante que ao inicializar o vector estará limpo e atualizado
}

void Estatisticas::atualizar_ranking() {
    std::list<Jogador*> lista_auxiliar = acessar_jogadores.Jogadores; 
    // Limpar o vetor antes de preenchê-lo novamente
    ranking_jogadores.clear();
    ranking_jogadores.assign(std::make_move_iterator(std::begin(lista_auxiliar)), 
                             std::make_move_iterator(std::end(lista_auxiliar)));
}

void Estatisticas::estatisticas_jogos(){ 
    if(acessar_jogadores.lista_vazia()){
        throw std::runtime_error("Erro: Não há jogadores cadastrados no sistema.");
    }
    Validacao validar_entrada_ranking;
    
    std::cout << "Querido jogador, você optou por ver as estatisticas do jogo." << std::endl 
              << "Visando atender melhor seu pedido, por favor selecione mais especificamente o que gostaria de ver"  
              << "(tecle o número correspondente a sua escolha)" << std::endl;

    std::cout << "(1) Para ver o ranking geral (todos os jogos)." << std::endl
              << "(2) Para acessar o ranking do jogo Reversi." << std::endl
              << "(3) Para acessar o ranking do jogo Lig4." <<  std::endl
              << "(4) Para acessar o ranking do Jogo da Velha." << std::endl
              << "(5) Para acessar o ranking da Batalha Naval." << std::endl;
              

    int escolha;
    validar_entrada_ranking.pedir_usuario(escolha);

    if (escolha>4 || escolha<1){
        throw std::out_of_range("Erro: A escolha feita foi fora do intervalo permitido (1 a 4).");
    }

    while (true) {
        switch (escolha) {
            case 1:
                std::cout << std::endl;
                ranking_geral();
                break;

            case 2:
                std::cout << std::endl;
                ranking_reversi();
                break;

            case 3:
                std::cout << std::endl;
                ranking_lig4();
                break;

            case 4:
                std::cout << std::endl;
                ranking_jogovelha();
                break;
            case 5:
                std::cout << std::endl;
                ranking_batalhanaval();
                break;
            
        }
        break; // Sai do while quando o switch processa um caso válido
    }
};

void Estatisticas::listar_jogadores(){

    if (acessar_jogadores.lista_vazia()){
        throw std::runtime_error("Erro: Não há jogadores cadastrados no sistema.");
    
    }
    
    for (const auto& jogador : acessar_jogadores.Jogadores) {
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "JOGADOR: " << jogador->get_apelido() << std::setw(10) << jogador->get_nome() << std::endl;

        std::cout << "VT: " << jogador->get_vitorias_totais()
                << std::setw(2) << " DT: " << jogador->get_derrotas_totais()
                << std::setw(2) << " ET: " << jogador->get_empates_totais()
                << std::setw(2) << " PT: " << jogador->get_pontos_totais() << std::endl << std::endl;
        
        std::cout << std::setw(10) << "REVERSI - " << std::setw(2) << " V: " << jogador->get_Reversi().vitorias
            << std::setw(5) << " D: " << jogador->get_Reversi().derrotas
            << std::setw(5) << " E: " << jogador->get_Reversi().empates
            << std::setw(5) << " P: " << jogador->get_Reversi().pontos_por_jogo << std::endl;

        std::cout << std::setw(10) << "LIG4 - " << std::setw(2) << " V: " <<  jogador->get_Lig4().vitorias 
            << std::setw(5) << " D: " << jogador->get_Lig4().derrotas 
            << std::setw(5) << " E: " << jogador->get_Lig4().empates 
            << std::setw(5) << " P: " << jogador->get_Lig4().pontos_por_jogo << std::endl;

        std::cout << std::setw(10) << "VELHA - " << std::setw(2) << " V: " << jogador->get_JogoVelha().vitorias
            << std::setw(5) << " D: " << jogador->get_JogoVelha().derrotas
            << std::setw(5) << " E: " << jogador->get_JogoVelha().empates
            << std::setw(5) << " P: " << jogador->get_JogoVelha().pontos_por_jogo << std::endl;
        
        std::cout << std::setw(10) << "BATALHA NAVAL - " << std::setw(2) << " V: " << jogador->get_BatalhaNaval().vitorias
            << std::setw(5) << " D: " << jogador->get_BatalhaNaval().derrotas
            << std::setw(5) << " E: " << jogador->get_BatalhaNaval().empates
            << std::setw(5) << " P: " << jogador->get_BatalhaNaval().pontos_por_jogo << std::endl << std::endl;
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
    std::cout << BOLD << "Ranking Geral: " << RESET << std::endl;
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
    std::cout << BOLD << "Ranking do Reversi: " << RESET << std::endl;
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
    std::cout << BOLD << "Ranking do Lig4: " << RESET << std::endl;
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
    std::cout << BOLD << "Ranking do Jogo da Velha: " << RESET << std::endl;
    imprimir_ranking(ranking_jogadores);
};

void Estatisticas::ranking_batalhanaval(){
    atualizar_ranking();

    std::sort(ranking_jogadores.begin(), ranking_jogadores.end(), [](Jogador* a, Jogador* b) {
    
        if(a->get_BatalhaNaval().pontos_por_jogo != b->get_BatalhaNaval().pontos_por_jogo){ 
             return  a->get_BatalhaNaval().pontos_por_jogo > b->get_BatalhaNaval().pontos_por_jogo;
        }
        else { 

            if(a->get_BatalhaNaval().vitorias != b->get_BatalhaNaval().vitorias){ 
                    return a->get_BatalhaNaval().vitorias > b->get_BatalhaNaval().vitorias;
            }
            else{ 

                if(a->get_BatalhaNaval().derrotas != b->get_BatalhaNaval().derrotas){ //olha qm tem neos derrotas
                    return a->get_BatalhaNaval().derrotas < b->get_BatalhaNaval().derrotas;
                }
                else{// por fim, caso precise, recorremos a ordem alfabética
                    return a->get_nome() < b->get_nome();
                }
            }
        }
    });

    std::cout << BOLD << "Ranking da Batalha Naval: " << RESET << std::endl;
    imprimir_ranking(ranking_jogadores);
}
void Estatisticas::imprimir_ranking(std::vector<Jogador *> vetor_jogadores)
{
    int posicao = 1;
    for(auto jogador: vetor_jogadores){
        std::cout << BOLD << posicao << ". " << RESET << jogador->get_apelido() << std::endl;
        posicao ++;
    }
    std::cout << std::endl;
};

Estatisticas::~Estatisticas() {
    ranking_jogadores.clear(); 
}

