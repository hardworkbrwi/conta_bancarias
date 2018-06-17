/**
 * @file	bebida.cpp
 * @brief	Implementação da classe Bebida em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 * 
 * @section DESCRIÇÃO
 *  
 * Implementa a classe Bebida,
 * derivada da classe Produto.
 */

#include <iomanip>
#include <istream>
#include <sstream>

#include "bebida.h"


Bebida::Bebida() {}

Bebida::Bebida( int tag, string codigoBarra, string descricao, short preco, 
	short teorAlcoolico ):
	Produto( tag, codigoBarra, descricao, preco ), /**< inicialização da classe base Produto */
	teorAlcoolico( teorAlcoolico ) {}

Bebida::~Bebida() {}

/*
string
Bebida::getTeorAlcoolico() {
    std::stringstream teor;
    teor << teorAlcoolico;
	return  teor.str() + " %";
}
*/

short Bebida::getTeorAlcoolico() {
	return teorAlcoolico;
}

void Bebida::setTeorAlcoolico( short teorAlcoolico ) {
	this->teorAlcoolico = teorAlcoolico;
}

/**
* @brief Método virtual puro print
* @detail Define a interface para impressão das informações de Bebida declaradas pela classe base Produto
* @param ostream & operador de inserção
* @return Retorna uma instância do operador de inserção
*/
std::ostream& Bebida::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << preco << " | "
		<< std::setfill (' ') << std::setw (10) << teorAlcoolico << " %";//getTeorAlcoolico();
	return o;
}
