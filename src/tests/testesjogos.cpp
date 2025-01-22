#include "doctest.h"
#include "Jogos/Jogos.hpp"
#include "Jogos/Jogo_da_velha.hpp"

//Testes para a Classe Jogo_De_Tabuleiro

TEST_CASE("Teste para a função tabuleiro_cheio()"){ /* Optamos por testar essa função de Jogos utilizando a classe Jogo_da_Velha,
que é relativamente a mais simples dos Jogos*/

    Jogo_Da_Velha jogo1; /* Na inicialização de Jogo_Da_Velha é sempre pedido ao usuário se quer preças padrão ou coloridas,
                        então isso será pedido 2 vezes nesse test_case, uma vez que criamos 2 objetos da classe Jogo_da_Velha*/
    Jogo_Da_Velha jogo2;
    
    jogo2.set_tabuleiro({
        {"X", "O", "X"},
        {"O", "X", "O"},
        {"X", "O", "X"}
    });

    CHECK(jogo1.tabuleiro_cheio()==false); // Tabuleiro vazio para jogo1
    CHECK(jogo2.tabuleiro_cheio()==true); 

}

TEST_CASE("Teste para a função testar_vitoria() e testar_empate() em Jogo_Da_Velha"){

    Jogo_Da_Velha jogo; /* Na inicialização de Jogo_Da_Velha é sempre pedido ao usuário se quer preças padrão ou coloridas,
                        então isso será pedido 1 vezes nesse test_case, uma vez que criamos 1 objeto da classe Jogo_da_Velha*/
    
    jogo.set_tabuleiro({
        {"X", "O", "X"},
        {"O", "X", "O"},
        {"X", "O", "X"}
    });

    CHECK(jogo.testar_vitoria("X")==true); 
    CHECK(jogo.testar_vitoria("O")==false);
    CHECK(jogo.testar_empate("X", "O")==false);


}

