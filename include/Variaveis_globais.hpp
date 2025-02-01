#ifndef VARIAVEIS_GLOBAIS_HPP
#define VARIAVEIS_GLOBAIS_HPP

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
#include <regex>

/**
 * @file Variaveis_globais.hpp
 * @brief Módulo contendo variáveis globais e funções auxiliares para melhorar a experiência do usuário.
 *
 * @details Este módulo define diversas variáveis globais e funções que visam melhorar a experiência 
 * de uso do sistema, como caracteres Unicode para peças do jogo e a função timer para espaçamento 
 * de saídas no terminal.
 */

// Definições de cores para formatação no terminal
#define RESET      "\033[0m"      /**< Reseta a cor para o padrão */
#define BOLD       "\033[1m"      /**< Aplica negrito ao texto */
#define RED        "\033[91m"     /**< Define a cor vermelha */
#define GREEN      "\033[92m"     /**< Define a cor verde */
#define YELLOW     "\033[93m"     /**< Define a cor amarela */
#define BLUE       "\033[94m"     /**< Define a cor azul */
#define MAGENTA    "\033[95m"     /**< Define a cor magenta */
#define BLACK      "\033[90m"     /**< Define a cor preta */
#define ORANGE     "\033[38;5;214m" /**< Define a cor laranja */
#define WHITE      "\033[97m"     /**< Define a cor branca */

// Definições de emojis representando peças de jogo
#define PECA_VERMELHA   "🔴"  /**< Emoji para a peça vermelha */
#define PECA_VERDE      "🟢"  /**< Emoji para a peça verde */
#define PECA_AMARELA    "🟡"  /**< Emoji para a peça amarela */
#define PECA_AZUL       "🔵"  /**< Emoji para a peça azul */
#define PECA_MAGENTA    "🟣"  /**< Emoji para a peça magenta */
#define PECA_LARANJA    "🟠"  /**< Emoji para a peça laranja */
#define PECA_PRETA      "⚫"  /**< Emoji para a peça preta */
#define PECA_BRANCO     "⚪"  /**< Emoji para a peça branca */
#define PECA_X          " X"  /**< Emoji para a peça X */
#define PECA_O          " O"  /**< Emoji para a peça O */

#define PORTA_AVIOES      "✈️ "  /**< Emoji para o porta-aviões */
#define ENCOURACADO       "🛡️ "  /**< Emoji para o encouraçado */
#define CONTRATORPEDEIRO  "🛶 "  /**< Emoji para o contratorpedeiro */

#define VOID  "  "    /**< Representação de um espaço vazio no tabuleiro */
#define AGUA  " ~ "  /**< Representação de água no tabuleiro */

/**
 * @brief Função que implementa um timer para espaçar impressões no terminal.
 * @param tempo Tempo de espera em segundos.
 */
void timer(int tempo);

#endif