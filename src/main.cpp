#include "Cadastro.hpp"
#include "Jogos/Jogos.hpp"
#include "Partida.hpp"
#include "Jogador.hpp"
#include "FuncoesGlobais.hpp"
#include "Estatisticas/Estatisticas.hpp"
#include <fstream>
#include <sstream>

int main() { 

    std::cout << "É hora de jogar!" << std::endl;
    Estatisticas est;
    CadastroJogadores jogador;
    Jogador *j1 = new Jogador("gabrielly", "gaby");
    jogador.adicionar_jogador(j1, "gaby");
    est.listar_jogadores(); 

    
    return 0;
}