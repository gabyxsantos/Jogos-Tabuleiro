# Variáveis de configuração
CC = g++
CFLAGS = -std=c++11 -Wall
SRC_DIR = src
DIR_JOGOS = Jogos
DIR_ESTATS = Estatisticas
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin


# Arquivos de saída
OBJECTS = $(OBJ_DIR)/FuncoesGlobais.o \
		  $(OBJ_DIR)/Validacao.o \
		  $(OBJ_DIR)/Jogador.o \
		  $(OBJ_DIR)/Cadastro.o \
		  $(OBJ_DIR)/Arquivo.o \
		  $(OBJ_DIR)/Jogos.o \
          $(OBJ_DIR)/Lig_4.o \
          $(OBJ_DIR)/Reversi.o \
          $(OBJ_DIR)/Jogo_da_velha.o \
		  $(OBJ_DIR)/Partida.o \
		  $(OBJ_DIR)/Estatisticas.o \
		  $(OBJ_DIR)/Estatisticas_lig4.o \
		  $(OBJ_DIR)/Estatisticas_reversi.o \
		  $(OBJ_DIR)/Estatisticas_velha.o \
		  $(OBJ_DIR)/RegistroEstatisticas.o \
		  $(OBJ_DIR)/Tutorial.o \
          $(OBJ_DIR)/main.o

INCLUDES = $(INCLUDE_DIR)/FuncoesGlobais.hpp \
		   $(INCLUDE_DIR)/Validacao.hpp \
		   $(INCLUDE_DIR)/Jogador.hpp \
		   $(INCLUDE_DIR)/Cadastro.hpp \
		   $(INCLUDE_DIR)/Arquivo.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp \
		   $(INCLUDE_DIR)/Partida.hpp \
		   $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp \
		   $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_lig4.hpp \
		   $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_reversi.hpp \
		   $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_velha.hpp \
		   $(INCLUDE_DIR)/$(DIR_ESTATS)/RegistroEstatisticas.hpp \
		   $(INCLUDE_DIR)/Tutorial.hpp



# Alvo padrão
all: create_dirs $(BIN_DIR)/main

create_dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Regras de compilação
$(OBJ_DIR)/FuncoesGlobais.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(SRC_DIR)/FuncoesGlobais.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/FuncoesGlobais.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/FuncoesGlobais.o

$(OBJ_DIR)/Validacao.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(SRC_DIR)/Validacao.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Validacao.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Validacao.o

$(OBJ_DIR)/Jogador.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/Jogador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogador.o

$(OBJ_DIR)/Cadastro.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Cadastro.hpp $(SRC_DIR)/Cadastro.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Cadastro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Cadastro.o

$(OBJ_DIR)/Arquivo.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/Arquivo.hpp $(SRC_DIR)/Arquivo.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Arquivo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Arquivo.o

$(OBJ_DIR)/Jogos.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogos.o

$(OBJ_DIR)/Lig_4.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Lig_4.o

$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

$(OBJ_DIR)/Jogo_da_velha.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogo_da_velha.o

$(OBJ_DIR)/Partida.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/Partida.hpp $(SRC_DIR)/Partida.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Partida.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Partida.o

$(OBJ_DIR)/Estatisticas.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas.o

$(OBJ_DIR)/Estatisticas_lig4.o: $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_lig4.hpp $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_lig4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas_lig4.o

$(OBJ_DIR)/Estatisticas_reversi.o: $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_reversi.hpp $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas_reversi.o

$(OBJ_DIR)/Estatisticas_velha.o: $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas_velha.hpp $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_velha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_ESTATS)/Estatisticas_velha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas_velha.o

$(OBJ_DIR)/RegistroEstatisticas.o: $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/RegistroEstatisticas.hpp $(SRC_DIR)/$(DIR_ESTATS)/RegistroEstatisticas.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_ESTATS)/RegistroEstatisticas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/RegistroEstatisticas.o

$(OBJ_DIR)/Tutorial.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/Tutorial.hpp $(SRC_DIR)/Tutorial.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Tutorial.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Tutorial.o

$(OBJ_DIR)/main.o: $(INCLUDES) $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

# Linkagem do executável
$(BIN_DIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN_DIR)/main

# Limpeza dos arquivos gerados
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o
