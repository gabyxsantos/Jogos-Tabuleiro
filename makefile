# Variáveis de configuração
CC = g++
CFLAGS = -std=c++11 -Wall
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Alvo padrão
all: $(BIN_DIR)/main

# Regras de compilação
$(OBJ_DIR)/Cadastro.o: $(INCLUDE_DIR)/Cadastro.hpp $(SRC_DIR)/Cadastro.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Cadastro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Cadastro.o

$(OBJ_DIR)/Jogos.o: $(INCLUDE_DIR)/Jogos.hpp $(SRC_DIR)/Jogos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogos.o

$(OBJ_DIR)/Partida.o: $(INCLUDE_DIR)/Partida.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Cadastro.hpp $(SRC_DIR)/Partida.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Partida.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Partida.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Cadastro.hpp $(INCLUDE_DIR)/Jogos.hpp $(INCLUDE_DIR)/Partida.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

# Linkagem do executável
$(BIN_DIR)/main: $(OBJ_DIR)/main.o $(OBJ_DIR)/Cadastro.o $(OBJ_DIR)/Jogos.o $(OBJ_DIR)/Partida.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/Cadastro.o $(OBJ_DIR)/Jogos.o $(OBJ_DIR)/Partida.o -o $(BIN_DIR)/main

# Limpeza dos arquivos gerados
clean:
	rm -f $(BIN_DIR)/main $(OBJ_DIR)/*.o