/**
 * @file	fruta.cpp
 * @brief	Implementação da classe Fruta em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 * 
 * @section DESCRIÇÃO
 *  
 * Implementa a classe Fruta,
 * derivada da classe Produto.
 */

#include <iomanip>
#include "fruta.h"

Fruta::Fruta() {}

Fruta::Fruta( int tag, std::string codigoBarra, std::string descricao, short preco, 
	std::string data, short validade ):
	Produto( tag, codigoBarra, descricao, preco ), data_lote( data ), validade( validade ) {} /**< inicialização da classe base Produto */

Fruta::~Fruta() {}

std::string Fruta::getDataLote() {
	return data_lote;
}

short Fruta::getValidade() {
	return validade;
}

void Fruta::setDataLote( std::string data ) {
	data_lote = data;
}

void Fruta::setValidade( short validade ) {
	this->validade = validade;
}
 
/**
* @brief Método virtual puro print
* @detail Define a interface para impressão das informações de Fruta declaradas pela classe base Produto
* @param ostream & operador de inserção
* @return Retorna uma instância do operador de inserção
*/
std::ostream& Fruta::print( std::ostream &o ) const {
	o << std::setfill (' ') << std::setw (10) << cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << preco << " | "
		<< std::setfill (' ') << std::setw (10) << data_lote << " | " 
		<< std::setfill (' ') << std::setw (3) << validade;
	return o;
}
