# Variáveis de Compilação
CC = gcc
CFLAGS = -std=c11 -O3 -Wextra -Wall -I./include
LDFLAGS = -lm

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_NAME = ordenador

# Descoberta Automática de Arquivos
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Regra Principal: Compila o executável
all: $(OBJ_DIR) $(BIN_NAME)

# Linkagem final
$(BIN_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Compilação dos arquivos objeto (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cria o diretório de objetos se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_NAME)

# Executa o experimento e gera o CSV
run: all
	./$(BIN_NAME) > resultados.csv

.PHONY: all clean run