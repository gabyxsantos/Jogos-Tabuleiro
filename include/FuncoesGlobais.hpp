#ifndef FUNCOESGLOBAIS_HPP
#define FUNCOESGLOBAIS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <iomanip>
#include <thread> 
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>

#define RESET   "\033[0m"        // Resetar cor para padrão
#define BOLD    "\033[1m"
#define RED     "\033[91m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define BLUE    "\033[94m"
#define MAGENTA "\033[95m"
#define BLACK   "\033[90m"
#define ORANGE  "\033[38;5;214m"
#define WHITE   "\033[97m"       
#define PECA_VERMELHA "🔴"
#define PECA_VERDE "🟢"     
#define PECA_AMARELA "🟡"   
#define PECA_AZUL "🔵"      
#define PECA_MAGENTA "🟣"   
#define PECA_LARANJA "🟠"   
#define PECA_PRETA "⚫"     
#define PECA_BRANCO "⚪"
#define PECA_X " X"
#define PECA_O " O"
#define VOID "  "    

// Funções para saídas amigáveis
void timer(int tempo);

#endif
