#include "FuncoesGlobais.hpp"

// Funções para tratamento de erros
    void imprimir_erro(const std::string& erro){
        std::cout << RED << "ERRO: " << erro << RESET << std::endl;
    }
    
// Funções para saídas amigáveis
    void timer(int tempo){
        std::cout << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
    }


bool validar_char(char& valor){
    return std::isalpha(valor); //Funcao retorna true se for uma letra
}

bool validar_string(const std::string& valor) {
    for (char c : valor) {
        if (!std::isalpha(c) && !std::isspace(c)) {
            return false; // Caracter inválido encontrado e a função retorna false
        }
    }
    return true;
}

