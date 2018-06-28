# Makefile for "laboratório Conta Corrente e Bibliotecas"
# Created by Bruno César 15/06/2018
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
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
PROG = $(BIN)/debitoconta

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -ansi -I$(INC)

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

all: diretorios linux

diretorios:
	$(MKDIR_P) $(DIR_CRT)

#libs .a e .so para gerar bibliotecas para o linux mathbasic.a mathbasic.so prog_estatico prog_dinamico
linux: cbancaria.a cbancaria.so lojinha.a lojinha.so loja_virtual_estatico loja_virtual_dinamico

windows: #libs .lib e .dll para gerar bibliotecas do windows

# LINUX

data.a: $(SRC)/data.cpp $(INC)/data.h
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $(OBJ)data.o
	$(AR) rsc $(LIB)/$@ $(OBJ)/data.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"
	@echo ""

data.so: $(SRC)/data.cpp $(INC)/data.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/data.cpp -o $(OBJ)data.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/data.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"
	@echo ""

cbancaria.a: $(SRC)/conta.cpp $(INC)/conta.h
	$(CC) $(CPPFLAGS) -c $(SRC)/conta.cpp -o $(OBJ)/conta.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/data.o $(OBJ)/conta.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"

cbancaria.so: $(SRC)/conta.cpp $(SRC)/data.cpp $(INC)/conta.h $(INC)/data.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/data.cpp -o $(OBJ)/data.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/conta.cpp -o $(OBJ)/conta.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/data.o $(OBJ)/conta.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"

lojinha.a: $(SRC)/produto.cpp $(SRC)/fruta.cpp $(INC)/produto.h $(INC)/fruta.h
	$(CC) $(CPPFLAGS) -c $(SRC)/fruta.cpp -o $(OBJ)/fruta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/produto.cpp -o $(OBJ)/produto.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/produto.o $(OBJ)/fruta.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"

lojinha.so: $(SRC)/produto.cpp $(SRC)/fruta.cpp $(INC)/produto.h $(INC)/fruta.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/fruta.cpp -o $(OBJ)/fruta.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/produto.cpp -o $(OBJ)/produto.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/produto.o $(OBJ)/fruta.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"

loja_virtual_estatico:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/cbancaria.a $(LIB)/lojinha.a -o $(BIN)/$@

prog_dinamico:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/cbancaria.so $(LIB)/lojinha.so -o $(BIN)/$@

#########

# WINDOWS

mathbasic.lib: $(SRC)/mathbasic.cpp $(INC)/mathbasic.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mathbasic.cpp -o $(OBJ)/mathbasic.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/mathbasic.o
	@echo "+++ [Biblioteca estática criada em $(LIB)/$@] +++"

mathbasic.dll: $(SRC)/mathbasic.cpp $(INC)/mathbasic.h
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mathbasic.cpp -o $(OBJ)/mathbasic.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(OBJ)/mathbasic.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++"

prog_estatico.exe:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/mathbasic.a -o $(BIN)/$@

prog_dinamico.exe:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(LIB)/mathbasic.so -o $(BIN)/$@

########

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	@echo "Removendo arquivos objetos e executáveis contidos nas pastas ./build e ./bin, respectivamente... "
	$(RM) $(BIN)/* $(OBJ)/*
