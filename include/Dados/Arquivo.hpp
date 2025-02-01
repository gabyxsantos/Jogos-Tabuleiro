#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "Cadastro/Cadastro.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"
#include <fstream>
#include <string>

/**
 * @class Arquivo
 * @brief Classe responsável por gerenciar operações de leitura e escrita em arquivos.
 *
 * @details A classe permite a leitura e gravação de dados dos jogadores em arquivos, utilizando a classe 
 * CadastroJogadores para manipulação e armazenamento dos dados. Ela é capaz de extrair informações de um 
 * arquivo para atualizar a lista de jogadores e também de salvar essas informações de volta no arquivo 
 * após atualizações. A classe oferece métodos para definir a lista de jogadores a ser manipulada e recuperar 
 * esses dados, garantindo persistência dos jogadores e seus dados relacionados. Aqui, é interessante citar que 
 * tinhámos uma escolha a ser feita: sempre abrir o arquivo e manipular os dados dentro do próprio arquivo 
 * toda vez que o sistema era executado ou manipular uma lista e, na finalização do sistema, adicionar os dados
 * à memória permanente (arquivo). Escolhemos pela segunda opção, de maneira que apenas abrimos o arquivo para 
 * recolher os dados e adicionar a lista, que irá ser manipulada durante a execução do sistema e, por fim, 
 * apenas modificamos o arquivo adicionando/removendo os dados de acordo com a lista. Isso evita operações 
 * repetidas e desnecessárias de leitura e escrita no arquivo durante a execução do sistema, melhorando a performance 
 * e mantendo os dados de maneira mais eficiente.
 */

class Arquivo {
    private:
        /**
         * @brief Objeto de manipulação de arquivos.
         */
        std::fstream file;

        /**
         * @brief String auxiliar para manipulação de dados durante a leitura e escrita.
         */
        std::string str;

        /**
         * @brief Objeto para acessar a lista de jogadores cadastrados.
         */
        CadastroJogadores lista_jogadores;

    public:
        /**
         * @brief Construtor da classe Arquivo.
         */
        Arquivo();

        /**
         * @brief Extrai os dados dos jogadores do arquivo.
         */
        void extrair_dados();

        /**
         * @brief Salva os dados dos jogadores no arquivo.
         */
        void salvar_dados();

        /**
         * @brief Define a lista de jogadores a ser manipulada.
         * @param acesso Referência para um objeto CadastroJogadores que contém os jogadores.
         */
        void set_lista_jogadores(CadastroJogadores &acesso);

        /**
         * @brief Retorna a lista de jogadores cadastrados.
         * @return Objeto CadastroJogadores com os jogadores cadastrados.
         */
        CadastroJogadores get_lista_jogadores();

        /**
         * @brief Destrutor da classe Arquivo.
         */
        ~Arquivo(){};
};

#endif