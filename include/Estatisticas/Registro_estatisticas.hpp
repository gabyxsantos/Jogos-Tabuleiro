#ifndef REGISTRO_ESTATISTICAS_H
#define REGISTRO_ESTATISTICAS_H

#include "Estatisticas/Estatisticas.hpp"

class Registro_Estatisticas{
    private:
    std::list<Estatisticas> estatisticas_por_usuario;
    
    public:
    void buscar_usuario();
};

#endif