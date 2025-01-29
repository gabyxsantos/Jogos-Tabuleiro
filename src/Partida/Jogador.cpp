#include "Partida/Jogador.hpp"

Validacao validar_entradas_jogador;
//Funções da classe Jogador:

    Jogador::Jogador(std::string nome, std::string apelido){
        this->nome = nome;
        this->apelido = apelido;
    }

    Jogador::Jogador(){
        this->nome="";
        this->apelido="";
    }

    Jogador::~Jogador() {
        // Limpar ou resetar os objetos de Placar
        this->Reversi = Placar(); // Reseta o placar de Reversi para o estado padrão
        this->Lig4 = Placar();    // Reseta o placar de Lig4 para o estado padrão
        this->JogoVelha = Placar(); // Reseta o placar de Jogo da Velha para o estado padrão

        // Zerando outras estatísticas
        this->vitorias_totais = 0;
        this->derrotas_totais = 0;
        this->empates_totais = 0;
        this->pontos_totais = 0;
    }


    void Jogador::set_nome() {
        std::string verificador;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
        do {
            std::cout << "Informe o nome do jogador: ";
            std::getline(std::cin, verificador);

            // Se a entrada estiver vazia, limpa o estado do buffer
            if (verificador.empty()) {
                validar_entradas_jogador.imprimir_erro("O nome não pode estar vazio.");
                continue; // Recomeça o loop sem validar outras condições
            }
            // Validações
            if (verificador.length() < 1 || verificador.length() > 10) {
                validar_entradas_jogador.imprimir_erro("O nome deve conter pelo menos 1 caractere e no máximo 10 caracteres.");
            } else if (verificador.find(' ') != std::string::npos) {
                validar_entradas_jogador.imprimir_erro("O nome deve conter apenas uma palavra, sem espaços.");
            } else if (!std::all_of(verificador.begin(), verificador.end(), isalpha)) {
                validar_entradas_jogador.imprimir_erro("O nome deve conter apenas letras (sem números ou caracteres especiais).");
            } else {
                // Nome válido
                Jogador::nome = verificador;
                break;
            }

        } while (true);
    }

    void Jogador::set_apelido() {
        std::string verificador;
        do {
            std::cout << "Informe o apelido do jogador: ";
            std::getline(std::cin, verificador);
            // Se a entrada estiver vazia, limpa o estado do buffer
            if (verificador.empty()) {
                validar_entradas_jogador.imprimir_erro("O apelido não pode estar vazio.");
                continue; // Recomeça o loop sem validar outras condições
            }
            // Validações
            if (verificador.length() < 1 || verificador.length() > 10) {
                validar_entradas_jogador.imprimir_erro("O apelido deve conter pelo menos 1 caractere e no máximo 10 caracteres.");
            } 
            else if (verificador.find(' ') != std::string::npos) {
                validar_entradas_jogador.imprimir_erro("O apelido deve conter apenas uma palavra, sem espaços.");
            } 
            else if (!std::all_of(verificador.begin(), verificador.end(), isalpha)) {
                validar_entradas_jogador.imprimir_erro("O apelido deve conter apenas letras (sem números ou caracteres especiais).");
            } 
            else if (verificador.compare("CP") == 0){
                validar_entradas_jogador.imprimir_erro( "Por excessões do sistema, para garantir um funcionamento correto, o apelido não pode ser CP.");
            }
            else {
                // Apelido válido
                Jogador::apelido = verificador;
                break;
            }

        } while (true);
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

    void Jogador::set_pontos_totais(int n){
        this->pontos_totais = n;
    };

//como melhorar essa logica dos empates??
    void Jogador::set_Lig4(){
        this->Lig4.empates++;
        
    };

    void Jogador::set_JogoVelha(){
        this->JogoVelha.empates++;
        
    };

    void Jogador::set_BatalhaNaval(){
        this->BatalhaNaval.empates++;
    }

    void Jogador::set_pontos_totais(bool valor)
    {
        if (valor) {
            this->pontos_totais +=3;
        } 
        else {
            this->pontos_totais +=1;
        }
    }

    void Jogador::set_Reversi(bool valor){
        if (valor) {
            this->Reversi.vitorias ++; //add vitoria no jogo
            this->Reversi.pontos_por_jogo += 3; //add pontos da vitoria
            set_pontos_totais(true); //add pontuaçao geral
            set_vitorias_totais(); //add vitoria geral
        } 
        else {
            this->Reversi.derrotas ++;
            set_derrotas_totais();
        }
    }

    void Jogador::set_Lig4(bool valor){
        if (valor) {
            this->Lig4.vitorias ++;
            this->Lig4.pontos_por_jogo += 3;
            set_pontos_totais(true);
            set_vitorias_totais();
        } 
        else {
            this->Lig4.derrotas ++;
            set_derrotas_totais();
        }
    }

    void Jogador::set_JogoVelha(bool valor){
        if (valor) {
            this->JogoVelha.vitorias ++;
            this->JogoVelha.pontos_por_jogo += 3;
            set_pontos_totais(true);
            set_vitorias_totais();
        } 
        else {
            this->JogoVelha.derrotas ++;
            set_derrotas_totais();
        }
    }

    void Jogador::set_BatalhaNaval(bool valor){
        if (valor) {
            this->BatalhaNaval.vitorias ++;
            this->BatalhaNaval.pontos_por_jogo += 3;
            set_pontos_totais(true);
            set_vitorias_totais();
        } 
        else {
            this->BatalhaNaval.derrotas ++;
            set_derrotas_totais();
        }
    }

    void Jogador::set_Reversi(int vitorias, int derrotas, int empates, int pontos){
        this->Reversi.vitorias = vitorias;
        this->Reversi.derrotas = derrotas;
        this->Reversi.empates = empates;
        this->Reversi.pontos_por_jogo = pontos;
    }

    void Jogador::set_Lig4(int vitorias, int derrotas, int empates, int pontos){
        this->Lig4.vitorias = vitorias;
        this->Lig4.derrotas = derrotas;
        this->Lig4.empates = empates;
        this->Lig4.pontos_por_jogo = pontos;
    }

    void Jogador::set_JogoVelha(int vitorias, int derrotas, int empates, int pontos){
        this->JogoVelha.vitorias = vitorias;
        this->JogoVelha.derrotas = derrotas;
        this->JogoVelha.empates = empates;
        this->JogoVelha.pontos_por_jogo = pontos;
    }

    void Jogador::set_BatalhaNaval(int vitorias, int derrotas, int empates, int pontos){
        this->BatalhaNaval.vitorias = vitorias;
        this->BatalhaNaval.derrotas = derrotas;
        this->BatalhaNaval.empates = empates;
        this->BatalhaNaval.pontos_por_jogo = pontos;
    }

    std::string Jogador::get_nome()
    {
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

    int Jogador::get_pontos_totais(){
        return Jogador::pontos_totais;
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

    Placar Jogador::get_BatalhaNaval(){
        return Jogador::BatalhaNaval;
    }