#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Partida/Jogador.hpp"
#include "Validacao.hpp"

//Testes para a Classe Jogador

/*OBS:implementamos esses testes visando testar nosso código, porem as entradas deles são passadas dentro do código, 
nao dependendo de usuário. é importante destacar também que os metodos set_Lig4(bool valor) e
 set_JogoVelha(bool valor) funcionam da mesma maneira, portanto não serão testados!*/ 

TEST_CASE("Teste do método Jogador::set_Reversi") {
    Jogador jogador("João", "J");

    SUBCASE("set_Reversi(true) adiciona uma vitória e pontos ao jogador") {
        jogador.set_Reversi(true);

        //verificando os atributos modificados em set_Reversi
        CHECK(jogador.get_Reversi().vitorias == 1);
        CHECK(jogador.get_Reversi().pontos_por_jogo == 3);
        CHECK(jogador.get_pontos_totais() == 3);
        CHECK(jogador.get_vitorias_totais() == 1);
        CHECK(jogador.get_derrotas_totais() == 0);
        CHECK(jogador.get_empates_totais() == 0);
    }

    SUBCASE("set_Reversi(false) adiciona uma derrota ao jogador") {
        jogador.set_Reversi(false);

        CHECK(jogador.get_Reversi().derrotas == 1);
        CHECK(jogador.get_Reversi().pontos_por_jogo == 0); 
        CHECK(jogador.get_pontos_totais() == 0); 
        CHECK(jogador.get_vitorias_totais() == 0);
        CHECK(jogador.get_derrotas_totais() == 1);
        CHECK(jogador.get_empates_totais() == 0);
    }

    SUBCASE("set_Reversi(true) seguido de set_Reversi(false)") {
        jogador.set_Reversi(true);
        jogador.set_Reversi(false);

        CHECK(jogador.get_Reversi().vitorias == 1);
        CHECK(jogador.get_Reversi().derrotas == 1);
        CHECK(jogador.get_Reversi().pontos_por_jogo == 3);
        CHECK(jogador.get_pontos_totais() == 3);
        CHECK(jogador.get_vitorias_totais() == 1);
        CHECK(jogador.get_derrotas_totais() == 1);
        CHECK(jogador.get_empates_totais() == 0);
    }
}

TEST_CASE("Teste do método Jogador::set_Reversi com valores explícitos") {
    Jogador jogador("Maria", "Mari");

    jogador.set_Reversi(2, 8, 1, 9); 

    CHECK(jogador.get_Reversi().vitorias == 2);
    CHECK(jogador.get_Reversi().derrotas == 8);
    CHECK(jogador.get_Reversi().empates == 1);
    CHECK(jogador.get_Reversi().pontos_por_jogo == 9);
}


TEST_CASE("Testes para métodos de configuração de valores totais no jogador") {
    Jogador jogador("Maria", "M");

    SUBCASE("Teste do método set_vitorias_totais(int n)") {
        jogador.set_vitorias_totais(10); 
        CHECK(jogador.get_vitorias_totais() == 10);
    }

    SUBCASE("Teste do método set_derrotas_totais(int n)") {
        jogador.set_derrotas_totais(8); 
        CHECK(jogador.get_derrotas_totais() == 8);
    }

    SUBCASE("Teste do método set_empates_totais(int n)") {
        jogador.set_empates_totais(2);
        CHECK(jogador.get_empates_totais() == 2);
    }

    SUBCASE("Teste do método set_pontos_totais(int n)") {
        jogador.set_pontos_totais(20); 
        CHECK(jogador.get_pontos_totais() == 20);
    }
}