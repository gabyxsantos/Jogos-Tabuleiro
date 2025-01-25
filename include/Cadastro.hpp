#ifndef CADASTRO_H
#define CADASTRO_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
#include "Jogador.hpp"

class CadastroJogadores{

    public: 
    static std::list<Jogador*> Jogadores;

    CadastroJogadores();

    void ordenar_jogadores_nome();

    void ordenar_jogadores_apelido(); 
    std::list<Jogador*>::iterator buscar_jogador(const std::string& apelido);
    bool adicionar_jogador(Jogador* jogador_novo, std::string& apelido);
    bool remover_jogador(std::string& apelido);

    //std::list<Jogador*> get_jogadores();
    
    //metodos para acessar os dados pelo main e salvar no arquivo
    bool lista_vazia() const;
    //const std::list<Jogador*>& get_jogadores() const;
    
    ~CadastroJogadores();
};


#endif