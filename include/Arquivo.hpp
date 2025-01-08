#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "Cadastro.hpp"
#include "FuncoesGlobais.hpp"
#include <fstream>
#include <sstream>

class Arquivo{
    private:
        std::fstream file;
        std::string str;
        RegistroJogadores lista_jogadores;

    public:
        Arquivo();
        void extrair_dados();
        void salvar_dados();
        ~Arquivo(){

        };

};

#endif