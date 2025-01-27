# Variáveis de configuração
CC = g++
CFLAGS = -std=c++11 -Wall
SRC_DIR = src
DIR_CADASTRO = Cadastro
DIR_DADOS = Dados
DIR_JOGOS = Jogos
DIR_PARTIDA = Partida
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin


# Arquivos de saída
OBJECTS = $(OBJ_DIR)/Variaveis_globais.o \
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

INCLUDES = $(INCLUDE_DIR)/Variaveis_globais.hpp \
		   $(INCLUDE_DIR)/Validacao.hpp \
		   $(INCLUDE_DIR)/$(DIR_PARTIDA)/Jogador.hpp \
		   $(INCLUDE_DIR)/$(DIR_CADASTRO)/Cadastro.hpp \
		   $(INCLUDE_DIR)/$(DIR_DADOS)/Arquivo.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp \
		   $(INCLUDE_DIR)/$(DIR_JOGOS)/Tutorial.hpp \
		   $(INCLUDE_DIR)/$(DIR_PARTIDA)/Partida.hpp \
		   $(INCLUDE_DIR)/$(DIR_DADOS)/Estatisticas.hpp \



# Alvo padrão
all: create_dirs $(BIN_DIR)/main

create_dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Regras de compilação
$(OBJ_DIR)/Cadastro.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_PARTIDA)/Jogador.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_PARTIDA)/Jogador.hpp $(INCLUDE_DIR)/$(DIR_CADASTRO)/Cadastro.hpp $(SRC_DIR)/$(DIR_CADASTRO)/Cadastro.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_CADASTRO)/Cadastro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Cadastro.o

$(OBJ_DIR)/Arquivo.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_CADASTRO)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_DADOS)/Arquivo.hpp $(SRC_DIR)/$(DIR_DADOS)/Arquivo.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_DADOS)/Arquivo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Arquivo.o

$(OBJ_DIR)/Estatisticas.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/$(DIR_DADOS)/Estatisticas.hpp $(SRC_DIR)/$(DIR_DADOS)/Estatisticas.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_DADOS)/Estatisticas.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Estatisticas.o

$(OBJ_DIR)/Jogos.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_CADASTRO)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogos.o

$(OBJ_DIR)/Lig_4.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Lig_4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Lig_4.o

$(OBJ_DIR)/Reversi.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Reversi.o

$(OBJ_DIR)/Jogo_da_velha.o: $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Jogo_da_velha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogo_da_velha.o

$(OBJ_DIR)/Tutorial.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Tutorial.hpp $(SRC_DIR)/$(DIR_JOGOS)/Tutorial.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_JOGOS)/Tutorial.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Tutorial.o

$(OBJ_DIR)/Jogador.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_PARTIDA)/Jogador.hpp $(SRC_DIR)/$(DIR_PARTIDA)/Jogador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_PARTIDA)/Jogador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogador.o

$(OBJ_DIR)/Partida.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(INCLUDE_DIR)/$(DIR_CADASTRO)/Cadastro.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogos.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Lig_4.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Reversi.hpp $(INCLUDE_DIR)/$(DIR_JOGOS)/Jogo_da_velha.hpp $(INCLUDE_DIR)/$(DIR_PARTIDA)/Partida.hpp $(SRC_DIR)/$(DIR_PARTIDA)/Partida.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$(DIR_PARTIDA)/Partida.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Partida.o

$(OBJ_DIR)/Variaveis_globais.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(SRC_DIR)/Variaveis_globais.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Variaveis_globais.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Variaveis_globais.o

$(OBJ_DIR)/Validacao.o: $(INCLUDE_DIR)/Variaveis_globais.hpp $(INCLUDE_DIR)/Validacao.hpp $(SRC_DIR)/Validacao.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Validacao.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Validacao.o

$(OBJ_DIR)/main.o: $(INCLUDES) $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

# Linkagem do executável
$(BIN_DIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN_DIR)/main

# Parte de TESTES
TEST_SOURCES = $(wildcard $(SRC_DIR)/tests/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/tests/%.o: $(SRC_DIR)/tests/%.cpp
	$(CC) $(CFLAGS) -c $< -Iinclude -o $@

$(BIN_DIR)/tests: $(TEST_OBJECTS) $(OBJ_DIR)/Variaveis_globais.o $(OBJ_DIR)/Validacao.o $(OBJ_DIR)/Jogador.o $(OBJ_DIR)/Cadastro.o $(OBJ_DIR)/Arquivo.o $(OBJ_DIR)/Jogos.o $(OBJ_DIR)/Lig_4.o $(OBJ_DIR)/Reversi.o $(OBJ_DIR)/Jogo_da_velha.o $(OBJ_DIR)/Partida.o $(OBJ_DIR)/Estatisticas.o $(OBJ_DIR)/Tutorial.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/tests

testes: $(BIN_DIR)/tests
	./$(BIN_DIR)/tests

# Limpeza
clean:
	rm -f $(BIN_DIR)/main $(BIN_DIR)/tests $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o