/**
 * @file	produto.cpp
 * @brief	Implementação da classe Produto em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 * 
 * @section DESCRIÇÃO
 *  
 * Implementa a classe Produto genêrica,
 * base para todos os produtos da aplicação.
 */

#include <iostream>
#include "produto.h"

Produto::Produto(){}

Produto::~Produto(){}

Produto::Produto( int tag, std::string codigo, std::string descricao, short preco ):
	tag( tag ), cod_barras( codigo ), descricao( descricao ), preco( preco ) {}

int Produto::getTag(){
	return tag;
}

std::string Produto::getCodBarras() {
	return cod_barras;
}
	
std::string Produto::getDescricao() {
	return descricao;
}

double Produto::getPreco() {
	return preco;
}
	
void Produto::setCodBarras( std::string codigo ) {
	cod_barras = codigo;
}

void Produto::setDescricao( std::string descricao ) {
	this->descricao = descricao;
}

void Produto::setPreco( double preco ) {
	this->preco = preco;
}

double operator+ ( Produto &a, Produto &b ){
	return a.getPreco() + b.getPreco();
}

double operator- ( Produto &a, Produto &b ){
	return a.getPreco() - b.getPreco();
}

bool operator== (Produto &a, Produto &b){
	if( a.getCodBarras() == b.getCodBarras() )
		return true;
	
	return false;
}

std::ostream& operator<< (std::ostream &o, Produto const &p) {
	return p.print(o);
}
