#include "doctest.h"
#include "Validacao.hpp"

//Testes para a classe Validação

TEST_CASE("Teste validação de char"){
    Validacao val;
    char testing_value1='a';
    char testing_value2='3';

    bool result1 = val.validar_char(testing_value1);
    bool result2 = val.validar_char(testing_value2);

    CHECK(result1 == true);
    CHECK(result2==false);

}

TEST_CASE("Teste validação de string"){
    Validacao val;
    std::string testing_value1="isso eh um teste";
    std::string testing_value2="5";
    std::string testing_value3="!!";
    std::string testing_value4="string";

    bool result1 = val.validar_string(testing_value1);
    bool result2 = val.validar_string(testing_value2);
    bool result3 = val.validar_string(testing_value3);
    bool result4 = val.validar_string(testing_value4);

    CHECK(result1 == true);
    CHECK(result2==false);
    CHECK(result3==false);
    CHECK(result4==true);

}