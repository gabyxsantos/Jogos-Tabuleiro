#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Cadastro/Cadastro.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

class Arquivo{
    private:
        std::fstream file;
        std::string str;
        CadastroJogadores lista_jogadores;

    public:
        Arquivo();
        void extrair_dados();
        void salvar_dados();
        void set_lista_jogadores(CadastroJogadores &acesso);
        CadastroJogadores get_lista_jogadores();
        ~Arquivo(){};

};

#endif