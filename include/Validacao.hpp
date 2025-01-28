#ifndef VALIDACAO_HPP
#define VALIDACAO_HPP

#include "Variaveis_globais.hpp"

class Validacao{
    private:
        
        //funcao para limpar o estado de erro e descartar a entrada invalida
        void limpar_entrada();
    
    public:
        bool validar_char(char& valor);
        bool validar_string(const std::string& valor);

        // Funções templadas para entrada de dados
        template <typename T>
        inline bool validar_entrada(T& valor) { //usando inline para evitar múltiplas definições ao incluir o hpp em diferentes arquivos cpp
            if (std::cin >> valor) {
                return true; // Entrada válida
            }
            
            Validacao::limpar_entrada();
            return false; // Entrada inválida
        }

        inline bool validar_entrada(char& valor) {
            if (std::cin >> valor) {
                if (Validacao::validar_char(valor)) {
                    return true; // Entrada passou em validação de char 
                }
            }
            
            Validacao::limpar_entrada();
            return false; // Entrada inválida
        }

        inline bool validar_entrada(std::string& valor) {
            if (std::cin >> valor) {
                if (Validacao::validar_string(valor)) {
                    return true; // Entrada passou em validação de string
                }
            }
            // Limpa o estado de erro e descarta a entrada inválida
            Validacao::limpar_entrada();
            return false; // Entrada inválida
        }
        
        void imprimir_erro(const std::string& erro);

        template <typename T>
        void pedir_usuario(T& valor) {
            while (!validar_entrada(valor)) {
                imprimir_erro("Entrada inválida. Insira no formato correto!");
            }
        }
    
};


#endif
