#include "Cadastro.hpp"
#include "Jogos.hpp"
#include "Partida.hpp"
#include "FuncoesGlobais.hpp"
#include <fstream>
#include <sstream>

int main() { 
    Partida teste;
    teste.iniciar_partida();
    RegistroJogadores lista_jogadores;

    std::fstream file;
    std::string str;
    file.open("JogosTabuleiro.txt", std::fstream::in);
    

    if(file.is_open()){ //caso o arquivo ja exista
        
        std::string nome, apelido, auxstr; ///se der errado a leitura voltar aqui
        int vitorias_jogo, derrotas_jogo, vitorias_totais, derrotas_totais;

        while(!file.eof()){

            file >> auxstr >> apelido >> nome >> auxstr >> vitorias_totais >> auxstr >> derrotas_totais;
            Jogador* jogador = new Jogador(nome, apelido); 
            jogador->set_vitorias_totais(vitorias_totais);
            jogador->set_derrotas_totais(derrotas_totais);

            for (int i = 0; i < 3; i++) {
                file >> auxstr >> auxstr >> vitorias_jogo >> auxstr >> derrotas_jogo;
                if (i == 0) {
                    jogador->set_Reversi(vitorias_jogo, derrotas_jogo);
                } 
                else if (i == 1) {
                    jogador->set_Lig4(vitorias_jogo, derrotas_jogo);
                } 
                else if (i == 2) {
                    jogador->set_JogoVelha(vitorias_jogo, derrotas_jogo);
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


   











    //depois que a partida se finalizar, vamos salvar tudo no arquivo:
     lista_jogadores.salvar_em_arquivo("JogosTabuleiro.txt");
    return 0;
}
