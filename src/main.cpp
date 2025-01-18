#include "Cadastro.hpp"
#include "Jogos/Jogos.hpp"
#include "Partida.hpp"
#include "Jogador.hpp"
#include "Arquivo.hpp"
#include "Validacao.hpp"
#include "Tutorial.hpp"
#include "FuncoesGlobais.hpp"
#include "Estatisticas/Estatisticas.hpp"

Validacao validar_entrada_main;

int main() { 
    
    std::cout << "É hora de jogar!" << std::endl;

    Arquivo arq;
    arq.extrair_dados();   //para começar devemos chamar o arquivo e extrair_dados()
    
    std::cout<<"Digite algum dos seguintes comandos:"<<std::endl
    <<"'CJ': Cadastrar um novo jogador."<<std::endl
    <<"'RJ': Remover um jogador existente."<<std::endl
    <<"'LJ': Listar todos os jogadores cadastrados e seus dados."<<std::endl
    <<"'EP': Executar uma partida entre jogadores."<<std::endl
    <<"'VE': Visualizar estatísticas relacionadas aos jogos."<<std::endl
    <<"'VT': Visualizar um tutorial explicativo sobre o sistema e os jogos."<<std::endl
    <<"'FS': Finalizar o sistema."<<std::endl;

    std::string entrada;
    std::cin>>entrada;

    CadastroJogadores acesso;
    Estatisticas est(acesso);
    Partida jogos(acesso);
    std::string jogador_remover="";
    std::string apelido_cadastrar="";

    //While loop para as entradas
    while(entrada!="FS"){

        if (entrada=="CJ"){ //Cadastro de um novo jogador
            
            Jogador *jogador_cadastrar=new Jogador();
            jogador_cadastrar->set_nome();
            jogador_cadastrar->set_apelido();
            std::string apelido_cadastrar = jogador_cadastrar->get_apelido();
            acesso.adicionar_jogador(jogador_cadastrar, apelido_cadastrar);
            
        }

        else if(entrada=="RJ"){ //Remoção de um jogador
            
            validar_entrada_main.pedir_usuario(jogador_remover);
            acesso.remover_jogador(jogador_remover); 

        }

        else if(entrada=="LJ"){ //Lista todos os jogadores

            est.atualizar_acesso(acesso);
           try{
                est.listar_jogadores();
           }
           catch (const std::runtime_error& e) {
                std::cerr << "Exceção capturada: " << e.what() << std::endl;
                
            }

        }

        else if(entrada=="VE"){
            est.atualizar_acesso(acesso);

            try{
                est.estatisticas_jogos(); // se o jogador quiser ver as estatisticas do jogo, basta chamar estatisticas_jogos()
            }
            catch(const std::out_of_range& e){
                std::cerr << "Exceção capturada: " << e.what() << std::endl;
                std::cout<<"Você pode escolher outra atividade ou 'VE' novamente, inserindo posteriormente um número dentro do range (1-5)"<<std::endl;

            }
            catch (const std::runtime_error& e) {
                std::cerr << "Exceção capturada: " << e.what() << std::endl;
                
            }

        }
        
        else if(entrada=="EP"){ 
            jogos.atualizar_acesso(acesso);

            try {
                jogos.iniciar_partida();
            } 
            catch (const std::runtime_error& e) {
                std::cerr << "Exceção capturada: " << e.what() << std::endl;
                
            }

        }

        /*else if(entrada=="T"){  }
        
        */

        else{ //Caso em que o usuário não digite nenhuma das opções acima
            validar_entrada_main.imprimir_erro("Parece que você digitou uma opção inválida, tente novamente: ");
        }
        
        jogador_remover.clear();
        apelido_cadastrar.clear();
        std::cout<<"Digite outro comando: ";
        std::cin>>entrada; //Pedindo uma nova entrada para o usuário

    }
    
    std::cout<<"O sistema foi finalizado sem erros!"<<std::endl;

    arq.salvar_dados();  // quando a partidar acabar devemos chamar salvar_dados()
   
    return 0;
}