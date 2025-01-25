#include "FuncoesGlobais.hpp"


// Funções para saídas amigáveis
    void timer(int tempo){
        std::cout << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(tempo));
    }


