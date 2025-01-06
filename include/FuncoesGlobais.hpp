#ifndef FUNCOESGLOBAIS_HPP
#define FUNCOESGLOBAIS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <iomanip>
#include <thread> 
#include <chrono>
#include <cctype>

#define RESET   "\033[0m"        // Resetar cor para padrão
#define BOLD    "\033[1m"
#define RED     "\033[91m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[94m"
#define MAGENTA "\033[95m"
#define BLACK   "\033[90m"
#define ORANGE  "\033[38;5;214m"
#define WHITE   "\033[97m"       
#define PECA_VERMELHA "🔴"
#define PECA_VERDE "🟢"     
#define PECA_AMARELA "🟡"   
#define PECA_AZUL "🔵"      
#define PECA_MAGENTA "🟣"   
#define PECA_LARANJA "🟠"   
#define PECA_PRETA "⚫"     
#define PECA_BRANCO "⚪"
#define PECA_X " X"
#define PECA_O " O"
#define VOID "  "    

// Funções para tratamento de erros
void imprimir_erro(const std::string& erro);

//funcao para limpar o estado de erro e descartar a entrada invalida
void limpar_entrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validar_char(char& valor);
bool validar_string(const std::string& valor);

// Funções templadas para entrada de dados
template <typename T>
bool validar_entrada(T& valor) {
    if (std::cin >> valor) {
        return true; // Entrada válida
    }
    
    limpar_entrada();
    return false; // Entrada inválida
}

template <>
bool validar_entrada(char& valor) {
    if (std::cin >> valor) {
        if (validar_char(valor)) {
            return true; // Validação de char passou
        }
    }
    
    limpar_entrada();
    return false; // Entrada inválida
}

template <>
bool validar_entrada(std::string& valor) {
    if (std::cin >> valor) {
        if (validar_string(valor)) {
            return true; // Validação de string passou
        }
    }
    // Limpa o estado de erro e descarta a entrada inválida
    limpar_entrada();
    return false; // Entrada inválida
}


template <typename T>
void pedir_usuario(T& valor) {
    while (!validar_entrada(valor)) {
        imprimir_erro("Entrada inválida. Insira no formato correto!");
    }
}
// Funções para saídas amigáveis
void timer(int tempo);

#endif
