#include "Cadastro.hpp"

//Funções da classe Jogador:
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
    };
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
    void Registro_jogadores::ordenar_jogadores_nome(){ // Ordenar por nome
        Registro_jogadores::Jogadores.sort([](Jogador& a, Jogador& b) {
            std::string nome_a=a.get_nome();
            std::string nome_b=b.get_nome();
            std::transform(nome_a.begin(), nome_a.end(), nome_a.begin(), ::tolower);
            std::transform(nome_b.begin(), nome_b.end(), nome_b.begin(), ::tolower);
            return nome_a < nome_b;
        });
    };
    void Registro_jogadores::ordenar_jogadores_apelido(){ // Ordenar por apelido
        Registro_jogadores::Jogadores.sort([](Jogador& a, Jogador& b) {
            std::string apelido_a=a.get_apelido();
            std::string apelido_b=b.get_apelido();
            std::transform(apelido_a.begin(), apelido_a.end(), apelido_a.begin(), ::tolower);
            std::transform(apelido_b.begin(), apelido_b.end(), apelido_b.begin(), ::tolower);
            return apelido_a < apelido_b;
        });
    };
    std::list<Jogador>::iterator Registro_jogadores::buscar_jogador(std::string& apelido){
        for (auto it = Jogadores.begin(); it != Jogadores.end(); ++it) {
        if (it->get_apelido() == apelido) {
            return it;
        }
    }
    return Jogadores.end();
    };
    bool Registro_jogadores::adicionar_jogador(Jogador jogador_novo, std::string apelido){
        if (Registro_jogadores::buscar_jogador(apelido)== Jogadores.end()) {
            Registro_jogadores::Jogadores.push_back(jogador_novo);
            return false;
        }
        else {
            std::cout << "Já existe um jogador cadastrado com esse apelido!";
            return true;
        }
    };
    void Registro_jogadores::remover_jogador(std::string& apelido){
        if (Registro_jogadores::buscar_jogador(apelido)== Jogadores.end()) std::cout << "Jogador não encontrado!";
        else Jogadores.erase(Registro_jogadores::buscar_jogador(apelido));
    };
    void Registro_jogadores::mostrar_jogadores(){
        for (auto i : Jogadores) {
        std::cout << i.get_nome() << std::endl << i.get_apelido() << std::endl;
    }
    };
