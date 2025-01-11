#include "Estatisticas/Estatisticas.hpp"

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

            std::cout << std::endl; // Separador entre os registros
        }
};

void Estatisticas::ranking(){
    
};

void Estatisticas::ranking_geral(){
     std::list<Jogador*> lista_auxiliar = acessar_jogadores.get_jogadores(); 
     //agr, para facilitar a ordenação, vamos transformar de list pra vector
     std::vector<Jogador*> vetor_jogadores{ std::make_move_iterator(std::begin(lista_auxiliar)), std::make_move_iterator(std::end(lista_auxiliar)) };

    std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), [](Jogador* a, Jogador* b) {
        return  a->get_pontos_totais() > b->get_pontos_totais(); // Ordem decrescente
    });
}


void Estatisticas::ranking_reversi(){
   
};

void Estatisticas::ranking_lig4(){
    
};

void Estatisticas::ranking_jogovelha(){
    
};


