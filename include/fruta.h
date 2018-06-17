/**
 * @file	fruta.h
 * @brief	Definição da classe Fruta em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 */

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

/**
* @brief Classe Fruta, derivada de Produto
*/  
class Fruta : public Produto{
public:
	/**
	* @brief Método construtor padrão de Fruta
	*/  
	Fruta();

	/**
	* @brief Método construtor parametrizado de Fruta
	* @param int tag - categoria do Produto
	* @param string codigo - Codigo de barras do Produto
	* @param string descricao - Descrição do Produto
	* @param short preco - Preço do Produto
	* @param string data - Define a data do lote da fruta
	* @param short validade - Define os dias para vencimento a partir da data do lote
	*/  
	Fruta( int tag, std::string codigo, std::string descricao, short preco, 
			std::string data, short validade );
	
	/**
	* @brief Interface destrutor de Produto definida para Fruta
	* @detail Método virtual da classe Produto redefinida para um objeto Fruta
	*/
	~Fruta();

private:
	std::string data_lote; /**< define a data_lote para um objeto Fruta */
	short validade; /**< define a validade para um objeto Bebida */

public:
	// getters

	/**
	* @brief Método de captura de data_lote
	* @return Retorna a data de lote do produto
	*/
	std::string getDataLote();

	/**
	* @brief Método de captura de validade
	* @return Retorna a validade
	*/
	short getValidade();
	// setters

	/**
	* @brief Método de atribuição de data_lote
	* @param Recebe string data
	*/
	void setDataLote( std::string data );

	/**
	* @brief Método de atribuição de validade
	* @param Recebe string validade
	*/
	void setValidade( short validade );
	
private:
	/**
	* @brief Método virtual puro print
	* @detail Interface para impressão das informações de Fruta
	* @param ostream & operador de inserção
	* @return Retorna uma instância do operador de inserção
	*/
	std::ostream& print( std::ostream &o ) const;
};

#endif