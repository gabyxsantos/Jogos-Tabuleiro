#ifndef REGISTRO_ESTATISTICAS_H
#define REGISTRO_ESTATISTICAS_H

#include "Estatisticas/Estatisticas.hpp"

class RegistroEstatisticas{
    private:
    std::list<Estatisticas> estatisticas_por_usuario;
    
    public:
    void buscar_usuario();
    //ranking geral
    //ranking por jogo
    //jogo mais escolhido

};

#endif