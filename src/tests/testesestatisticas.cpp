#include "doctest.h"
#include "Dados/Estatisticas.hpp"
#include "Validacao.hpp"
#include "Cadastro/Cadastro.hpp"
#include "Partida/Jogador.hpp"

//Testes para a Classe Estatisticas

TEST_CASE("Teste para os métodos listar_jogadores()"){
    CadastroJogadores buscador;
    Estatisticas est(buscador);
    CHECK_THROWS_AS(est.listar_jogadores(), std::runtime_error); /*Verificando se esse método lançam 
                                                                exceções no caso de um buscador vazio*/

}
