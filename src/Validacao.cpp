#include "Validacao.hpp"
#include "FuncoesGlobais.hpp"

// Funções para tratamento de erros
void Validacao::imprimir_erro(const std::string& erro){
    std::cout << RED << "ERRO: " << erro << RESET << std::endl;
}

void Validacao::limpar_entrada() { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool Validacao::validar_char(char& valor){
    return std::isalpha(valor); //Funcao retorna true se for uma letra
}

bool Validacao::validar_string(const std::string& valor) {
    for (char c : valor) {
        if (!std::isalpha(c) && !std::isspace(c)) {
            return false; // Caracter inválido encontrado e a função retorna false
        }
    }
    return true;
}





