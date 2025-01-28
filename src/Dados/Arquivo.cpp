#include "Dados/Arquivo.hpp"

Arquivo::Arquivo(){};

Validacao validar_entradas_arquivo;

void Arquivo::extrair_dados(){
    file.open("DadosJogos/JogosTabuleiro.txt", std::fstream::in);
    
    if(file.is_open()){ //caso o arquivo ja exista
        
        std::string nome, apelido, auxstr; ///se der errado a leitura voltar aqui
        int vitorias_jogo, derrotas_jogo, empates_jogo, pontos_jogo, vitorias_totais, derrotas_totais, empates_totais, pontos_totais;
        //lista_jogadores.limpar_lista(); //garantindo que a lista esteja vazia antes de adicionar os jogadores

        while(true){
            file >>auxstr >> apelido >> nome;
            if (file.eof()) {
                break;
            }
            file >> auxstr >> vitorias_totais >> auxstr >> derrotas_totais >> auxstr >> empates_totais >> auxstr >> pontos_totais;
            Jogador* jogador = new Jogador(nome, apelido); 
            jogador->set_vitorias_totais(vitorias_totais);
            jogador->set_derrotas_totais(derrotas_totais);
            jogador->set_empates_totais(empates_totais);
            jogador->set_pontos_totais(pontos_totais);


            for (int i = 0; i < 4; i++) {
                file >> auxstr >> auxstr >> vitorias_jogo >> auxstr >> derrotas_jogo >> auxstr >> empates_jogo >> auxstr >> pontos_jogo;
                if (i == 0) {
                    jogador->set_Reversi(vitorias_jogo, derrotas_jogo, empates_jogo, pontos_jogo);
                } 
                else if (i == 1) {
                    jogador->set_Lig4(vitorias_jogo, derrotas_jogo, empates_jogo, pontos_jogo);
                } 
                else if (i == 2) {
                    jogador->set_JogoVelha(vitorias_jogo, derrotas_jogo, empates_jogo, pontos_jogo);
                }
                else if (i == 3) {
                    jogador->set_BatalhaNaval(vitorias_jogo, derrotas_jogo, empates_jogo, pontos_jogo);
                }
            }

            if(jogador->get_nome()!=""){
                lista_jogadores.adicionar_jogador(jogador, apelido);
            }


        }
        file.close();
    }
    else{ //caso nao exista, iremos criá-lo

        file.open("DadosJogos/JogosTabuleiro.txt", std::fstream::out);
        file.close();
    }

}


void Arquivo::salvar_dados(){
    file.clear();
    file.open("DadosJogos/JogosTabuleiro.txt", std::fstream::out ); 

        if (!file.is_open()) {
            validar_entradas_arquivo.imprimir_erro("Erro ao abrir o arquivo para salvar os jogadores!");
            return;
        }

        if (lista_jogadores.lista_vazia()) {
            std::cout << "Aviso: Nenhum jogador na lista para salvar!" << std::endl;
            return;
        }

        for (const auto& jogador : lista_jogadores.Jogadores) {
            file << "JOGADOR: " << jogador->get_apelido() << std::setw(10) << jogador->get_nome() << std::endl;

            file << "VT: " << jogador->get_vitorias_totais()
                    << std::setw(2) << " DT: " << jogador->get_derrotas_totais()
                    << std::setw(2) << " ET: " << jogador->get_empates_totais()
                    << std::setw(2) << " PT: " << jogador->get_pontos_totais() << std::endl;
            
            file << "REVERSI" << " V: " << jogador->get_Reversi().vitorias
                << std::setw(5) << " D: " << jogador->get_Reversi().derrotas
                << std::setw(5) << " E: " << jogador->get_Reversi().empates
                << std::setw(5) << " P: " << jogador->get_Reversi().pontos_por_jogo << std::endl;

            file  << "LIG4" << " V: " <<  jogador->get_Lig4().vitorias 
                << std::setw(5) << " D: " << jogador->get_Lig4().derrotas 
                << std::setw(5) << " E: " << jogador->get_Lig4().empates 
                << std::setw(5) << " P: " << jogador->get_Lig4().pontos_por_jogo << std::endl;

            file << "VELHA" << " V: " << jogador->get_JogoVelha().vitorias
                << std::setw(5) << " D: " << jogador->get_JogoVelha().derrotas
                << std::setw(5) << " E: " << jogador->get_JogoVelha().empates
                << std::setw(5) << " P: " << jogador->get_JogoVelha().pontos_por_jogo << std::endl;

            file << "BATALHANAVAL" << " V: " << jogador->get_BatalhaNaval().vitorias
                << std::setw(5) << " D: " << jogador->get_BatalhaNaval().derrotas
                << std::setw(5) << " E: " << jogador->get_BatalhaNaval().empates
                << std::setw(5) << " P: " << jogador->get_BatalhaNaval().pontos_por_jogo << std::endl;
        
        }

        file.close();

}

void Arquivo::set_lista_jogadores(CadastroJogadores &acesso){
    if(acesso.lista_vazia()){
        std::cout << "Aviso: Nenhum jogador na lista para salvar!" << std::endl;
        return;
    }
    this->lista_jogadores = acesso;
    salvar_dados();
}

CadastroJogadores Arquivo::get_lista_jogadores(){
    return this->lista_jogadores;
}
