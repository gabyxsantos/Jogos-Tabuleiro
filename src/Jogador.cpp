#include "Jogador.hpp"

//Funções da classe Jogador:

    Jogador::Jogador(std::string nome, std::string apelido){
        this->nome = nome;
        this->apelido = apelido;
    }

    void Jogador::set_nome(){
        std::string verificador;
        std::cin.ignore();
        do {
        std::cout << "Informe o nome do jogador: ";
        std::getline (std::cin, verificador);
        if (verificador.length()<1 || verificador.length()>100) std::cout << "O nome deve conter pelo menos 1 caracter e no máximo 100 caracteres" << std::endl;
        if (verificador.find(' ')!= std::string::npos) std::cout << "O nome deve conter apenas uma palavra, sem espaços" << std::endl; //O nome é completo ou só o primeiro nome? no enunciado só fala que apelido deve ser único..
        if (verificador.length()>=1 && verificador.length()<=100 && verificador.find(' ')== std::string::npos) Jogador::nome = verificador;
        } while (Jogador::nome != verificador);
    }

    void Jogador::set_apelido(){
        std::string verificador;
        std::cout << "Informe o apelido do jogador: ";
        do {
        std::getline (std::cin, verificador);
        if (verificador.length()<1 || verificador.length()>10) std::cout << "O apelido deve conter pelo menos 1 caracter e no máximo 10 caracteres" << std::endl;
        if (verificador.find(' ')!= std::string::npos) std::cout << "O apelido deve conter apenas uma palavra, sem espaços" << std::endl; 
        if (isalpha(verificador[0])==0) std::cout << "O primeiro caractere do apelido não pode ser um dígito ou caracter especial" << std::endl;
        if (isalpha(verificador[0])!=0 && verificador.length()>=1 && verificador.length()<=10 && verificador.find(' ')== std::string::npos) {
            Jogador::apelido = verificador;
        }
        } while (Jogador::apelido != verificador);
    }


    void Jogador::set_vitorias_totais(){
        this->vitorias_totais++;
    }

    void Jogador::set_derrotas_totais(){
        this->derrotas_totais++;
    }

    void Jogador::set_empates_totais(){
        this->empates_totais++;
    }

    void Jogador::set_vitorias_totais(int n){
        this->vitorias_totais = n;
    }

    void Jogador::set_derrotas_totais(int n){
        this->derrotas_totais = n;
    }

    void Jogador::set_empates_totais(int n){
        this->empates_totais = n;
    }

    void Jogador::set_Reversi(bool valor){
        if (valor) {
            this->Reversi.vitorias ++;
        } 
        else {
            this->Reversi.derrotas ++;
        }
    }

    void Jogador::set_Lig4(bool valor){
        if (valor) {
            this->Lig4.vitorias ++;
        } 
        else {
            this->Lig4.derrotas ++;
        }
    }

    void Jogador::set_JogoVelha(bool valor){
        if (valor) {
            this->JogoVelha.vitorias ++;
        } 
        else {
            this->JogoVelha.derrotas ++;
        }
    }


    void Jogador::set_Reversi(int vitorias, int derrotas, int empates){
        this->Reversi.vitorias = vitorias;
        this->Reversi.derrotas = derrotas;
        this->Reversi.empates = empates;
    }

    void Jogador::set_Lig4(int vitorias, int derrotas, int empates){
        this->Lig4.vitorias = vitorias;
        this->Lig4.derrotas = derrotas;
        this->Lig4.empates = empates;
    }

    void Jogador::set_JogoVelha(int vitorias, int derrotas, int empates){
        this->JogoVelha.vitorias = vitorias;
        this->JogoVelha.derrotas = derrotas;
        this->JogoVelha.empates = empates;
    }


    std::string Jogador::get_nome(){
        return Jogador::nome;
    }

    std::string Jogador::get_apelido(){
        return Jogador::apelido;
    }

    int Jogador::get_vitorias_totais(){
        return Jogador::vitorias_totais;
    }

    int Jogador::get_derrotas_totais(){
        return Jogador::derrotas_totais;
    }

     int Jogador::get_empates_totais(){
        return Jogador::empates_totais;
    }

    Placar Jogador::get_Reversi(){
        return Jogador::Reversi;
    }

    Placar Jogador::get_Lig4(){
        return Jogador::Lig4;
    }

    Placar Jogador::get_JogoVelha(){
        return Jogador::JogoVelha;
    }

