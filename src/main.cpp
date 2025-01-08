#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "Partida.hpp"
#include "FuncoesGlobais.hpp"
#include <fstream>
#include <sstream>

int main() { 

    RegistroJogadores lista_jogadores;

    std::fstream file;
    std::string str;
    file.open("JogosTabuleiro.txt", std::fstream::in);
    

    if(file.is_open()){ //caso o arquivo ja exista
        
        std::string nome, apelido, auxstr; ///se der errado a leitura voltar aqui
        int vitorias_jogo, derrotas_jogo, empates_jogo, vitorias_totais, derrotas_totais, empates_totais;

        while(!file.eof()){

            file >> auxstr >> apelido >> nome >> auxstr >> vitorias_totais >> auxstr >> derrotas_totais >> auxstr >> empates_totais;
            Jogador* jogador = new Jogador(nome, apelido); 
            jogador->set_vitorias_totais(vitorias_totais);
            jogador->set_derrotas_totais(derrotas_totais);
            jogador->set_empates_totais(empates_totais);

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

    //com o arquivo criado, basta exucutar os comandos da partida:

    std::cout << "É hora de jogar!" << std::endl;














    //depois que a partida se finalizar, vamos salvar tudo no arquivo:
    file.clear();
    file.open("JogosTabuleiro.txt", std::fstream::in);

        if (!file.is_open()) {
            std::cout << "Erro ao abrir o arquivo para salvar os jogadores!" << std::endl;
            return 1;
        }

        if (lista_jogadores.lista_vazia()) {
            std::cout << "Aviso: Nenhum jogador na lista para salvar!" << std::endl;
            return 1;
        }

        for (const auto& jogador : lista_jogadores.get_jogadores()) {
            file << "Jogador: " << jogador->get_apelido() << " " << jogador->get_nome();
            file << "VT:" << jogador->get_vitorias_totais() << " "
                << "DT:" << jogador->get_derrotas_totais() << " "
                << "ET:" << jogador->get_empates_totais() << std::endl;

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

    return 0;
}