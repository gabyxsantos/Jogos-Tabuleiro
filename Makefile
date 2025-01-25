# Variáveis de configuração
CC = g++
CFLAGS = -std=c++11 -Wall
SRC_DIR = src
DIR_CADASTRO = Cadastro
DIR_DADOS = Dados
DIR_ESTATS = Estatisticas
DIR_JOGOS = Jogos
DIR_PARTIDA = Partidas
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

$(OBJ_DIR)/Jogador.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(SRC_DIR)/Partidas/Jogador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Partidas/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogador.o

$(OBJ_DIR)/Cadastro.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Jogador.hpp $(INCLUDE_DIR)/Cadastro.hpp $(SRC_DIR)/Cadastro/Cadastro.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Cadastro/Cadastro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Cadastro.o

$(OBJ_DIR)/Arquivo.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/Arquivo.hpp $(SRC_DIR)/Dados/Arquivo.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Dados/Arquivo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Arquivo.o

$(OBJ_DIR)/Jogos.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogos.o

$(OBJ_DIR)/Lig_4.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Lig_4.o

$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

$(OBJ_DIR)/Jogo_da_velha.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogo_da_velha.o

$(OBJ_DIR)/Partida.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/Partida.hpp $(SRC_DIR)/Partidas/Partida.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Partidas/Partida.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Partida.o

$(OBJ_DIR)/Estatisticas.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/$(DIR_ESTATS)/Estatisticas.hpp $(SRC_DIR)/$(DIR_DADOS)/Estatisticas.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_DADOS)/Estatisticas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas.o

$(OBJ_DIR)/Tutorial.o: $(INCLUDE_DIR)/FuncoesGlobais.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/Tutorial.hpp $(SRC_DIR)/Jogos/Tutorial.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogos/Tutorial.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Tutorial.o

$(OBJ_DIR)/main.o: $(INCLUDES) $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

# Linkagem do executável
$(BIN_DIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN_DIR)/main

# Limpeza dos arquivos gerados
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o
