#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
#include "Cadastro.hpp"


class Arquivo{
    private:
        std::fstream file;
        std::string str;
        CadastroJogadores lista_jogadores;

    public:
        Arquivo();
        void extrair_dados();
        void salvar_dados();
        ~Arquivo(){};

};

#endif