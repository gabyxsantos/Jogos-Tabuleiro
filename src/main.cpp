#include "Cadastro/Cadastro.hpp"
#include "Dados/Arquivo.hpp"
#include "Dados/Estatisticas.hpp"
#include "Jogos/Jogos.hpp"
#include "Jogos/Tutorial.hpp"
#include "Partida/Partida.hpp"
#include "Partida/Jogador.hpp"
#include "Validacao.hpp"
#include "Variaveis_globais.hpp"

Validacao validar_entrada_main;

int main() { 
    
    std::cout << "É hora de jogar!" << std::endl;

    Arquivo arq;
    try{
        arq.extrair_dados(); 
    }
    catch(std:: exception& e){
        validar_entrada_main.imprimir_erro("Exceção capturada: ");
        validar_entrada_main.imprimir_erro("Exceção capturada: ");
        std::cerr << e.what() << std::endl;
        std::cout<<"O arquivo não foi encontrado, nem foi possível criá-lo."<<std::endl;
    }
      //para começar devemos chamar o arquivo e extrair_dados()
    CadastroJogadores acesso =  arq.get_lista_jogadores();
    
    std::cout<<"Digite algum dos seguintes comandos:"<<std::endl
    <<"'CJ': Cadastrar um novo jogador."<<std::endl
    <<"'RJ': Remover um jogador existente."<<std::endl
    <<"'LJ': Listar todos os jogadores cadastrados e seus dados."<<std::endl
    <<"'EP': Executar uma partida entre jogadores."<<std::endl
    <<"'VE': Visualizar estatísticas relacionadas aos jogos."<<std::endl
    <<"'VT': Visualizar um tutorial explicativo sobre o sistema e os jogos."<<std::endl
    <<"'FS': Finalizar o sistema."<<std::endl;

    std::string entrada; 
    std::cin >> entrada;
    
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
            while(acesso.adicionar_jogador(jogador_cadastrar, apelido_cadastrar)){
                jogador_cadastrar->set_apelido();
                apelido_cadastrar.clear();
                apelido_cadastrar = jogador_cadastrar->get_apelido();
            }
            std::cout << jogador_cadastrar->get_nome() << " foi cadastrado com sucesso!" << std::endl;
        }

        else if (entrada == "RJ") { // Remoção de um jogador
            std::cout << "Caso queira cancelar o processo, insira CP." << std::endl
              << "Adicione o apelido do jogador que deseja remover: ";
    
            std::string jogador_remover;
            while (true) {
                try {
                    validar_entrada_main.pedir_usuario(jogador_remover); // Solicita o apelido do jogador
                    if (jogador_remover == "CP") {
                        std::cout << "Processo de remoção cancelado." << std::endl;
                        break; 
                    }
                    if (acesso.remover_jogador(jogador_remover)) {
                        std::cout << jogador_remover << " foi removido com sucesso!" << std::endl << std::endl;
                        break; 
                    }
                } 
                catch (const std::runtime_error& e) {
                    validar_entrada_main.imprimir_erro("Exceção capturada: ");
                    std::cerr << e.what() << std::endl;
                    break; // Sai do loop se a lista estiver vazia
                }
                catch (const std::invalid_argument& e) {
                    validar_entrada_main.imprimir_erro("Exceção capturada: ");
                    std::cerr << e.what() << std::endl;
                    std::cout << "Tente novamente. Insira o apelido do jogador que deseja remover: ";
                } 
            }
        }



        else if(entrada=="LJ"){ //Lista todos os jogadores

           try{
                est.listar_jogadores();
           }
           catch (const std::runtime_error& e) {
                validar_entrada_main.imprimir_erro("Exceção capturada: ");
                std::cerr << e.what() << std::endl << std::endl;
            }
        }

        else if(entrada=="EP"){ 

            try {
                jogos.iniciar_partida();
            } 
            catch (const std::runtime_error& e) {
                validar_entrada_main.imprimir_erro("Exceção capturada: ");
                std::cerr << e.what() << std::endl << std::endl;
                
            }

        }

        else if(entrada=="VE"){

            try{
                est.estatisticas_jogos(); // se o jogador quiser ver as estatisticas do jogo, basta chamar estatisticas_jogos()
            }
            catch(const std::out_of_range& e){
                validar_entrada_main.imprimir_erro("Exceção capturada: ");
                std::cerr << e.what() << std::endl;
                std::cout<<"Você pode escolher outra atividade (M para ver menu) ou 'VE' novamente, inserindo posteriormente um número dentro do range (1-4)"<<std::endl;

            }
            catch (const std::runtime_error& e) {
                validar_entrada_main.imprimir_erro("Exceção capturada: ");
                std::cerr << e.what() << std::endl << std::endl;
                
            }

        }
        
        else if (entrada == "VT"){

            Tutorial tutorial;

            int entrada_tutorial; 
            while(true){

                //timer(1000);
                timer(1000);
                std::cout << "Escolha uma opção: " << std::endl
                        << "<1> Jogo da velha" << std::endl
                        << "<2> Lig 4" << std::endl
                        << "<3> Reversi" << std:: endl
                        << "<4> Voltar ao menu principal" << std:: endl;
                timer(1000);
                std::cout << "Digite uma das opções: " ;

                validar_entrada_main.pedir_usuario(entrada_tutorial);
                if (entrada_tutorial < 1 || entrada_tutorial > 4){
                    validar_entrada_main.imprimir_erro("Por favor, escolha uma opção válida.");
                }else if (entrada_tutorial == 4) break;
                else{
                    tutorial.iniciar_tutorial(entrada_tutorial);
                    
                }
            }
        }

        else if (entrada == "M"){
            
            timer(1000);
            std::cout<<"Menu de comandos:"<<std::endl
                <<"'CJ': Cadastrar um novo jogador."<<std::endl
                <<"'RJ': Remover um jogador existente."<<std::endl
                <<"'LJ': Listar todos os jogadores cadastrados e seus dados."<<std::endl
                <<"'EP': Executar uma partida entre jogadores."<<std::endl
                <<"'VE': Visualizar estatísticas relacionadas aos jogos."<<std::endl
                <<"'VT': Visualizar um tutorial explicativo sobre o sistema e os jogos."<<std::endl
                <<"'FS': Finalizar o sistema."<<std::endl;
            timer(1000);
        }

        else{ //Caso em que o usuário não digite nenhuma das opções acima
            validar_entrada_main.imprimir_erro("Parece que você digitou uma opção inválida, tente novamente: ");
        }
        
        std::cout<<"Processo finalizado. Agora você pode iniciar um novo processo no sistema!"<<
        std::endl<< "Para imprimir o menu principal novamente, digite M."<<
        std::endl<< "Digite seu novo comando: ";
        std::cin>>entrada; //Pedindo uma nova entrada para o usuário

    }
    
    std::cout<<"O sistema foi finalizado sem erros!"<<std::endl;

    arq.set_lista_jogadores(acesso); // quando a partidar acabar devemos chamar salvar_dados()

    return 0;
}