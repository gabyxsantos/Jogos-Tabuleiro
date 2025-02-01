#ifndef CADASTRO_H
#define CADASTRO_H

#include "Partida/Jogador.hpp"
#include "Variaveis_globais.hpp"
#include "Validacao.hpp"

/**
 * @class CadastroJogadores
 * @brief Classe responsável por gerenciar o cadastro de jogadores.
 *
 * @details A classe CadastroJogadores gerencia o cadastro de jogadores em um sistema 
 * de jogos. Ela utiliza uma lista estática de ponteiros para objetos da classe Jogador, 
 * que armazena os jogadores cadastrados. A classe oferece funcionalidades para adicionar, 
 * remover, e buscar jogadores, além de permitir a ordenação dos jogadores por 
 * nome ou apelido. A estrutura de dados utilizada para armazenar os jogadores é 
 * uma lista encadeada, o que facilita a inserção e remoção de jogadores. 
 * A classe também verifica se a lista de 
 * jogadores está vazia através do método lista_vazia, o que pode ser útil para 
 * saber se há jogadores no sistema ou se a lista precisa ser preenchida. O gerenciamento 
 * da lista é centralizado, ou seja, toda a manipulação de jogadores 
 * (adição, remoção, busca) é feita diretamente através dessa classe. Isso garante que a 
 * lógica do sistema de cadastro esteja bem encapsulada e que as operações com a lista de 
 * jogadores sejam feitas de maneira controlada. Quando o sistema é finalizado, 
 * as alterações feitas nos jogadores cadastrados podem ser extraídas e gravadas 
 * em um arquivo, permitindo persistir os dados para futuras execuções do programa. 
 * A lista de jogadores pode ser manipulada durante a execução do sistema, e as 
 * operações de adicionar ou remover jogadores atualizam automaticamente o estado dessa lista.
 */
class CadastroJogadores {
    public:
        /**
         * @brief Lista estática que armazena os jogadores cadastrados.
         */
        static std::list<Jogador*> Jogadores;

        /**
         * @brief Construtor da classe CadastroJogadores.
         */
        CadastroJogadores();

        /**
         * @brief Ordena os jogadores por nome.
         */
        void ordenar_jogadores_nome();
        
        /**
         * @brief Ordena os jogadores por apelido.
         */
        void ordenar_jogadores_apelido();
        
        /**
         * @brief Busca um jogador pelo apelido.
         * @param apelido Apelido do jogador a ser buscado.
         * @return Iterador apontando para o jogador encontrado ou para o final da lista caso não exista.
         */
        std::list<Jogador*>::iterator buscar_jogador(const std::string& apelido);

        /**
         * @brief Adiciona um novo jogador ao cadastro.
         * @param jogador_novo Ponteiro para o novo jogador a ser adicionado.
         * @param apelido Apelido do jogador.
         * @return true se o jogador foi adicionado com sucesso, false caso contrário.
         */
        bool adicionar_jogador(Jogador* jogador_novo, std::string& apelido);

        /**
         * @brief Remove um jogador do cadastro pelo apelido.
         * @param apelido Apelido do jogador a ser removido.
         * @return true se o jogador foi removido com sucesso, false caso contrário.
         */
        bool remover_jogador(std::string& apelido);

        /**
         * @brief Verifica se a lista de jogadores está vazia.
         * @return true se a lista estiver vazia, false caso contrário.
         */
        bool lista_vazia() const;
        
        /**
         * @brief Destrutor da classe CadastroJogadores.
         */
        ~CadastroJogadores();
};

#endif