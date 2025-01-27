#include "doctest.h"
#include "Cadastro/Cadastro.hpp"
#include "Validacao.hpp"
#include "Partida/Jogador.hpp"

//Testes para a Classe CadastroJogadores

TEST_CASE("Teste para as funções adicionar_jogador() e remover_jogador()"){
    CadastroJogadores buscador;
    Jogador *jogador1=new Jogador("Carolina", "Carol");
    std::string apelido="Carol";

    bool result1= buscador.adicionar_jogador(jogador1, apelido);
    CHECK(result1==false);

    bool result2= buscador.adicionar_jogador(jogador1, apelido);
    CHECK(result2==true); // Deve imprimir "Já existe um jogador cadastrado com esse apelido!"

    bool result3=buscador.remover_jogador(apelido);
    CHECK(result3==true);

    CHECK_THROWS_AS(buscador.remover_jogador(apelido), std::exception);

}