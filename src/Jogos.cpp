#include "Jogos.hpp"

//Funções da classe Peça:
void Peca::set_peca(){};
void Peca::set_X() {};
void Peca::set_Y() {};
void Peca::get_peca() {
    std::cout << peca;
};
void Peca::get_X() {};
void Peca::get_Y() {};

//Funções da classe base Jogo_De_Tabuleiro:
void Jogo_De_Tabuleiro::imprimir_menu(){
    std::cout << "Para iniciar partida, tecle <I> " << std::endl << "Para ver o tutorial do jogo, tecle <T> " << std::endl;
    };
void Jogo_De_Tabuleiro::inicializar_tabuleiro(){};
void Jogo_De_Tabuleiro::ler_jogada(){
    std::cout << "Insira a coordenada X (coluna) da próxima peça: " << std::endl;
    std::cin >> X;
};
void Jogo_De_Tabuleiro::ler_jogada(int y){
    std::cout << "Insira a coordenada Y (linha) da próxima peça: " << std::endl;
    std::cin >> Y;
};
bool Jogo_De_Tabuleiro::verificar_jogada(){
    if (X>tamanho_tabuleiro[0]||X<1){
        std::cout << "O tabuleiro escolhido tem "<< tamanho_tabuleiro[1] <<" colunas de dimensão. Por favor escolha um número entre 1 e "<< tamanho_tabuleiro[1];
        return true;
    }
    else return false;
};
bool Jogo_De_Tabuleiro::verificar_jogada(int y){
    if (Y>tamanho_tabuleiro[1]||Y<1) {
        std::cout << "O tabuleiro escolhido tem "<< tamanho_tabuleiro[0] <<" linhas de dimensão. Por favor escolha um número entre 1 e "<< tamanho_tabuleiro[0];
        return true;
    }
    else return false;
};
void Jogo_De_Tabuleiro::testar_vitoria(){};
void Jogo_De_Tabuleiro::imprimir_tabuleiro(){};
void Jogo_De_Tabuleiro::finalizar_partida() {
    std::cout << "O jogo terminou em um empate.";
}
void Jogo_De_Tabuleiro::finalizar_partida(std::string apelido_jogador) {
    std::cout << "O jogador "<< apelido_jogador <<" ganhou o jogo.";
}
std::string Jogo_De_Tabuleiro::definir_cor(){
    int cor_escolhida;
    do {
    std::cout << "Escolha a cor de suas peças: "<< std::endl << RED << "<1> Vermelho 🔴" << std::endl << GREEN << "<2> Verde 🟢" << std::endl << YELLOW << "<3> Amarelo 🟡" << std::endl << BLUE <<"<4> Azul 🔵" << std::endl << MAGENTA << "<5> Magenta 🟣" << std::endl << ORANGE << "<6> Laranja 🟠" << std::endl << BLACK << "<7> Preto ⚫" << WHITE << std::endl << "<8> Branco ⚪" << RESET;
    std::cin >> cor_escolhida;
    if (cor_escolhida<1||cor_escolhida>8) std::cout<< "Por favor escolha uma cor válida"<< std::endl;
    else {
        switch (cor_escolhida){
        case 1: {
            return "🔴";
        }
        case 2: {
            return "🟢";
        }
        case 3: {
            return "🟡";
        }
        case 4: {
            return "🔵";
        }
        case 5: {
            return "🟣";
        }
        case 6: {
            return "🟠";
        }
        case 7: {
            return "⚫";
        }
        case 8: {
            return "⚪";
        }
    }}} while (cor_escolhida<1||cor_escolhida>8);
};

/*
//Funções da classe Lig_4:
void Lig_4::inicializar_tabuleiro(){};
void Lig_4::testar_vitoria(){
    int verifica_jogador=0;
    if (numero_de_jogadas < 8) return; 
};
void Lig_4::imprimir_tabuleiro(){};
void Lig_4::finalizar_partida(){};
void Lig_4::definir_tamanho_tabuleiro(){};
std::string Lig_4::definir_cor(){};
*/
//Funções da classe Jogo_Da_Velha:
// Adicionar funções da classe Jogo_Da_Velha;

//Funções da classe Reversi:
void Reversi::mostrar_posicoes_possiveis(){};
void Reversi::converter_pecas(){};

//Funções da classe Tutorial:
void Tutorial::iniciar_tutorial_lig4(){};
void Tutorial::iniciar_tutorial_reversi(){};
void Tutorial::iniciar_tutorial_jogo_da_velha(){};
void Tutorial::imprimir_regras_lig4(){};
void Tutorial::imprimir_regras_reversi(){};
void Tutorial::imprimir_regras_jogo_da_velha(){};
