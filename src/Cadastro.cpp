#include "Cadastro.hpp"

//Funções da classe Jogador:
    void Jogador::set_nome(int numero_jogador){
        std::string verificador;
        std::cout << "Informe o nome do jogador " << numero_jogador << ":";
        std::getline (std::cin, verificador);
        if (verificador.length()<1 || verificador.length()>100) std::cout << "O nome deve conter pelo menos 1 caracter e no máximo 100 caracteres";
        if (verificador.find(' ')!= std::string::npos) std::cout << "O nome deve conter apenas uma palavra, sem espaços"; //O nome é completo ou só o primeiro nome? no enunciado só fala que apelido deve ser único..
        if (verificador.length()>=1 && verificador.length()<=100 && verificador.find(' ')== std::string::npos) Jogador::nome = verificador;
    };
    void Jogador::set_apelido(int numero_jogador){
        std::string verificador;
        std::cout << "Informe o apelido do jogador " << numero_jogador << ":";
        std::getline (std::cin, verificador);
        if (verificador.length()<1 || verificador.length()>10) std::cout << "O apelido deve conter pelo menos 1 caracter e no máximo 10 caracteres";
        if (verificador.find(' ')!= std::string::npos) std::cout << "O apelido deve conter apenas uma palavra, sem espaços"; 
        if (isalpha(verificador[0])!=0) std::cout << "O primeiro caractere do apelido não pode ser um dígito ou caracter especial";
        if (isalpha(verificador[0])==0 && verificador.length()>=1 && verificador.length()<=10 && verificador.find(' ')== std::string::npos) Jogador::apelido = verificador;
    };
    void Jogador::adicionar_vitoria(){
        this->numero_vitorias++;
    };
    void Jogador::adicionar_derrota(){
        this->numero_derrotas++;
    };
    std::string Jogador::get_nome(){
        return Jogador::nome;
    };
    std::string Jogador::get_apelido(){
        return Jogador::apelido;
    };
    int Jogador::get_vitorias(){
        return Jogador::numero_vitorias;
    };
    int Jogador::get_derrotas(){
        return Jogador::numero_derrotas;
    };
 
//Funções da classe Registro_jogadores
    void Registro_jogadores::ordenar_jogadores(){};
    void Registro_jogadores::ordenar_jogadores(){};
    std::string Registro_jogadores::buscar_jogador(){};
    void Registro_jogadores::adicionar_jogador(){};
    void Registro_jogadores::remover_jogador(){};
