#include "Cadastro/Cadastro.hpp"
 
std::list<Jogador*> CadastroJogadores::Jogadores;
Validacao validar_entradas_cadastro;

    CadastroJogadores::CadastroJogadores(){};

    void CadastroJogadores::ordenar_jogadores_nome(){ // Ordenar por nome
        CadastroJogadores::Jogadores.sort([](Jogador* a, Jogador* b) {
            std::string nome_a=a->get_nome();
            std::string nome_b=b->get_nome();
            std::transform(nome_a.begin(), nome_a.end(), nome_a.begin(), ::tolower);
            std::transform(nome_b.begin(), nome_b.end(), nome_b.begin(), ::tolower);
            return nome_a < nome_b;
        });
    }
    void CadastroJogadores::ordenar_jogadores_apelido(){ // Ordenar por apelido
        CadastroJogadores::Jogadores.sort([](Jogador* a, Jogador* b) {
            std::string apelido_a=a->get_apelido();
            std::string apelido_b=b->get_apelido();
            std::transform(apelido_a.begin(), apelido_a.end(), apelido_a.begin(), ::tolower);
            std::transform(apelido_b.begin(), apelido_b.end(), apelido_b.begin(), ::tolower);
            return apelido_a < apelido_b;

        });
    }


    std::list<Jogador*>::iterator CadastroJogadores::buscar_jogador(const std::string& apelido){
        std::list<Jogador*>::iterator it; //definindo um iterator que vai caminhar pela list
        for ( it = Jogadores.begin(); it != Jogadores.end(); ++it) {
            if ((*it)->get_apelido() == apelido) {
                return (it);
            }
        }
        return Jogadores.end();
    }

    bool CadastroJogadores::adicionar_jogador(Jogador* jogador_novo, std::string& apelido){
        if (buscar_jogador(apelido)== Jogadores.end()) {
            Jogadores.push_back(jogador_novo);
            return false;
        }
        else {
            validar_entradas_cadastro.imprimir_erro("Já existe um jogador cadastrado com esse apelido!");
            return true;
        }
    }

    bool CadastroJogadores::remover_jogador(std::string& apelido){
        auto it = buscar_jogador(apelido);
        if (it== Jogadores.end()) {
            return true;
        }
        else {
            CadastroJogadores::Jogadores.erase(it);
            return false;
        }
    }
    
    bool CadastroJogadores::lista_vazia() const {
        return Jogadores.empty();
    }

    CadastroJogadores::~CadastroJogadores(){
        for (auto& jogador : Jogadores) {
            delete jogador;
        }
        Jogadores.clear();

    };
