#ifndef CADASTRO_H
#define CADASTRO_H

#include "FuncoesGlobais.hpp"
#include "Validacao.hpp"
#include "Jogador.hpp"

class CadastroJogadores{
    private:
    std::list<Jogador*> Jogadores;

    public: 
    void ordenar_jogadores_nome();

    void ordenar_jogadores_apelido(); 
    std::list<Jogador*>::iterator buscar_jogador(std::string& apelido);
    bool adicionar_jogador(Jogador* jogador_novo, std::string apelido);

    void remover_jogador(std::string& apelido);
    void mostrar_jogadores();

    std::list<Jogador*> get_jogadores();
    
    //metodos para acessar os dados pelo main e salvar no arquivo
    bool lista_vazia() const;
    const std::list<Jogador*>& get_jogadores() const;
    
};


#endif