#ifndef VALIDACAO_HPP
#define VALIDACAO_HPP

#include "Variaveis_globais.hpp"

/**
 * @class Validacao
 * @brief Classe responsável pela validação das entradas do usuário.
 *
 * @details Essa classe existe para que os possíveis erros de entrada que possam vir a ser 
 * cometidos pelos usuários sejam tratados corretamente, com mensagens claras e específicas, ao invés de mensagens 
 * do sistema como Segmentation Fault e, em seguida, o encerramento da execução do
 * programa. Durante o processo, pensamos em adicionar as funções como métodos globais, sem classe, porém,
 * dessa forma, o código perderia um pouco a característica de encapsulamento e organização.  
 * Optamos, então, por criar uma classe específica para lidar com esses erros de maneira mais controlada,  
 * permitindo uma melhor manutenção e possíveis expansões futuras.  
 * Além disso, essa abordagem possibilita um código mais limpo e intuitivo, melhorando a experiência do  
 * desenvolvedor ao lidar com erros de entrada do usuário. Por fim, é perceptível a definição de alguns métodos
 * no arquivo .hpp. Essas funções são definidas no cabeçalho porque a função `validar_entrada` é templada, o que exige
 * que sua definição esteja visível no momento da compilação para que o compilador possa instanciar diferentes
 * tipos conforme necessário. Além disso, a função sobrecarregada para `char` é declarada como `inline`, o que
 * permite que o compilador substitua diretamente sua chamada, otimizando o desempenho e evitando múltiplas
 * definições durante a vinculação. Dessa forma, ambas as funções podem ser utilizadas corretamente em diferentes
 * partes do código sem a necessidade de uma definição separada em um arquivo `.cpp`.
 * Acreditamos fortemente que, a partir dessa classe e também dos outros métodos de tratamento de exceções 
 * implementados ao longo do código, fomos capazes de ter sucesso em deixar nossa aplicação robusta, pelo menos
 * no que tange às entradas de usuários.
 */
class Validacao {
    private:
        /**
         * @brief Função para limpar o estado de erro e descartar a entrada inválida.
         */
        void limpar_entrada();
    
    public:
        /**
         * @brief Valida se o caractere fornecido é válido.
         * @param valor O caractere a ser validado.
         * @return true se o caractere for válido, caso contrário false.
         */
        bool validar_char(char& valor);

        /**
         * @brief Valida se a string fornecida é válida.
         * @param valor A string a ser validada.
         * @return true se a string for válida, caso contrário false.
         */
        bool validar_string(const std::string& valor);

        /**
         * @brief Função templada para validar a entrada de dados.
         * @tparam T Tipo de dado a ser validado.
         * @param valor Referência para a variável que armazenará o valor inserido.
         * @return true se a entrada for válida, false caso contrário.
         */
        template <typename T>
        inline bool validar_entrada(T& valor) {
            if (std::cin >> valor) {
                return true; // Entrada válida
            }
            Validacao::limpar_entrada();
            return false; // Entrada inválida
        }

        /**
         * @brief Valida a entrada de um caractere.
         * @param valor O caractere a ser validado.
         * @return true se a entrada for válida, false caso contrário.
         */
        inline bool validar_entrada(char& valor) {
            if (std::cin >> valor) {
                if (Validacao::validar_char(valor)) {
                    return true; // Entrada passou em validação de char 
                }
            }
            Validacao::limpar_entrada();
            return false; // Entrada inválida
        }

        /**
         * @brief Valida a entrada de uma string.
         * @param valor A string a ser validada.
         * @return true se a entrada for válida, false caso contrário.
         */
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
        
        /**
         * @brief Imprime uma mensagem de erro.
         * @param erro A mensagem de erro a ser exibida.
         */
        void imprimir_erro(const std::string& erro);

        /**
         * @brief Solicita ao usuário uma entrada válida.
         * @tparam T Tipo de dado a ser inserido.
         * @param valor Referência para a variável que armazenará a entrada.
         *
         * @details Continua pedindo ao usuário uma entrada até que a validação seja bem-sucedida.
         */
        template <typename T>
        void pedir_usuario(T& valor) {
            while (!validar_entrada(valor)) {
                imprimir_erro("Entrada inválida. Insira no formato correto!");
            }
        }
};

#endif

