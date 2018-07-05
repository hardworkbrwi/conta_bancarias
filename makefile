# Makefile for "Projeto da disciplinina de LP1"
# Created by Bruno César
# 			 
# Data: 4/07/2018
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos (include), executáveis (build), bibliotecas (lib), etc.
# Cada elemento é alocado em uma pasta especifica, organizando melhor o codigo fonte.
#
# Algumas variáveis são usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Gerador de blibliotecas
# estáticas
AR = ar

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
LIB = ./lib
DOC = ./doc

# Criando estruturas de diretórios
MKDIR_P = mkdir -p

# Todos os diretórios da aplicação
DIR_CRT = $(BIN) $(OBJ) $(DOC) $(LIB)

# Define o nome do binario/executavel final
PROG = $(BIN)/cbancaria

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS = $(OBJ)/data.o $(OBJ)/movimentacao.o $(OBJ)/conta.o $(OBJ)/operacao_conta.o $(OBJ)/homolog.o

all: diretorios $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

diretorios:
	$(MKDIR_P) $(DIR_CRT)

$(OBJ)/data.o: $(SRC)/data.cpp $(INC)/data.h
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $@

$(OBJ)/movimentacao.o: $(SRC)/movimentacao.cpp $(INC)/movimentacao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/movimentacao.cpp -o $@

$(OBJ)/conta.o: $(SRC)/conta.cpp $(INC)/conta.h
	$(CC) $(CPPFLAGS) -c $(SRC)/conta.cpp -o $@

$(OBJ)/operacao_conta.o: $(SRC)/operacao_conta.cpp $(INC)/operacao_conta.h
	$(CC) $(CPPFLAGS) -c $(SRC)/operacao_conta.cpp -o $@

$(OBJ)/homolog.o: $(OBJ)/data.o $(OBJ)/movimentacao.o $(OBJ)/conta.o $(OBJ)/operacao_conta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/homolog.cpp -o $@

#########

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	@echo "Removendo arquivos objetos e executáveis contidos nas pastas ./build e ./bin, respectivamente... "
	$(RM) $(BIN)/* $(OBJ)/*
