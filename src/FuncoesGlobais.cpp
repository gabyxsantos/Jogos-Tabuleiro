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