#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
#include "Cadastro/Cadastro.hpp"


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