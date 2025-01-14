#include "Arquivo.hpp"

void Arquivo::extrair_dados(){
    file.open("JogosTabuleiro.txt", std::fstream::in);
    
    if(file.is_open()){ //caso o arquivo ja exista
        
        std::string nome, apelido, auxstr; ///se der errado a leitura voltar aqui
        int pontos, vitorias_jogo, derrotas_jogo, empates_jogo, vitorias_totais, derrotas_totais, empates_totais;

        while(!file.eof()){

            file >> auxstr >> apelido >> nome ;
            file >> auxstr >> vitorias_totais >> auxstr 
            >> derrotas_totais >> auxstr >> empates_totais;
            file >> auxstr >> pontos;

            Jogador* jogador = new Jogador(nome, apelido); 
            jogador->set_vitorias_totais(vitorias_totais);
            jogador->set_derrotas_totais(derrotas_totais);
            jogador->set_empates_totais(empates_totais);
            jogador->set_pontos_totais(pontos);

            for (int i = 0; i < 3; i++) {
                file >> auxstr >> auxstr >> vitorias_jogo >> auxstr >> derrotas_jogo >> auxstr >> empates_jogo;
                if (i == 0) {
                    jogador->set_Reversi(vitorias_jogo, derrotas_jogo, empates_jogo);
                } 
                else if (i == 1) {
                    jogador->set_Lig4(vitorias_jogo, derrotas_jogo, empates_jogo);
                } 
                else if (i == 2) {
                    jogador->set_JogoVelha(vitorias_jogo, derrotas_jogo, empates_jogo);
                }
            }

            lista_jogadores.adicionar_jogador(jogador, apelido);

        }
        file.close();
    }
    else{ //caso nao exista, iremos criá-lo

        file.open("JogosTabuleiro.txt", std::fstream::out);
        file.close();
    }

}


void Arquivo::salvar_dados(){
    file.clear();
    file.open("JogosTabuleiro.txt", std::fstream::in);

        if (!file.is_open()) {
            std::cout << "Erro ao abrir o arquivo para salvar os jogadores!" << std::endl;
            return;
        }

        if (lista_jogadores.lista_vazia()) {
            std::cout << "Aviso: Nenhum jogador na lista para salvar!" << std::endl;
            return;
        }

        for (const auto& jogador : lista_jogadores.get_jogadores()) {
            file << "Jogador: " << jogador->get_apelido() << " " << jogador->get_nome() << std::endl;;
            file << "VT:" << jogador->get_vitorias_totais() << " "
                << "DT:" << jogador->get_derrotas_totais() << " "
                << "ET:" << jogador->get_empates_totais() << std::endl;
            file << "Pontos: " << jogador->get_pontos_totais() << std::endl;

            file << "Reversi V:" << jogador->get_Reversi().vitorias
                << " D:" << jogador->get_Reversi().derrotas << std::endl;
               

            file << "Lig4 V:" << jogador->get_Lig4().vitorias
                << " D:" << jogador->get_Lig4().derrotas
                << " E:" << jogador->get_Lig4().empates << std::endl;

            file << "Velha V:" << jogador->get_JogoVelha().vitorias
                << " D:" << jogador->get_JogoVelha().derrotas
                << " E:" << jogador->get_JogoVelha().empates << std::endl;

            file << std::endl; // Separador entre os registros
        }

        file.close();

}