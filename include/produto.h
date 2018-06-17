/**
 * @file	produto.h
 * @brief	Definição da classe Produto em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 */

#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>

class Produto{
public:
	/**
	* @brief Método construtor padrão de produto
	*/  
	Produto();

	/**
	* @brief Método construtor parametrizado de produto
	* @param int tag - categoria do Produto
	* @param string codigo - Codigo de barras do Produto
	* @param string descricao - Descrição do Produto
	* @param short preco - Preço do Produto
	*/  
	Produto( int tag, std::string codigo, std::string descricao, short preco );

	/**
	* @brief Interface destrutor de Produto
	* @detail Método virtual da classe Produto capaz de ser redefinido (sobrecarregado)
	* por suas classes derivadas
	*/
	virtual ~Produto();

protected:
	int tag; /**< define a categoria do produto */
	std::string cod_barras; /**< define o código de barras do produto */
	std::string descricao; /**< define a descrição do produto */
	double preco; /**< define o preço do produto */

public:
	// getters

	/**
	* @brief Método de captura da Tag
	* @return Retorna a tag do produto
	*/
	int getTag();

	/**
	* @brief Método de captura de CodBarras
	* @return Retorna o código de barras do produto
	*/
	std::string getCodBarras();

	/**
	* @brief Método de captura de Descrição
	* @return Retorna a descrição do produto
	*/
	std::string getDescricao();

	/**
	* @brief Método de captura de preço
	* @return Retorna o preço do produto
	*/
	double getPreco();
	// setters

	/**
	* @brief Método de atribuição de CodBarras
	* @param Recebe string codigo
	*/
	void setCodBarras( std::string codigo );

	/**
	* @brief Método de atribuição de Descrição
	* @param Recebe string descricao
	*/
	void setDescricao( std::string descricao );

	/**
	* @brief Método de atribuição de preço
	* @param Recebe double preco
	*/
	void setPreco( double preco );
	//

	/**
	* @brief Sobrecarga do operador de inserção para objeto Produto.
	* @detail imprime na saída padrão as informações do Produto
	* @param ostream &o operador de inserção
	* @param Produto t uma instância de produto
	* @return retorna a instância do operador de inserção
	*/
	friend std::ostream& operator<< ( std::ostream &o, Produto const &t );

	/**
	* @brief Sobrecarga do operador de adição para objeto Produto.
	* @detail imprime na saída padrão a soma dos valores de proeços de dois Produtos
	* @param Produto &a instância de Produto
	* @param Produto &b instância de Produto
	* @return retorna um double resultado da soma dos preços de dois Produtos
	*/
	friend double operator+ ( Produto &a, Produto &b );

	/**
	* @brief Sobrecarga do operador de subtração para objeto Produto.
	* @detail imprime na saída padrão a subtração dos valores  de preços de dois Produtos
	* @param Produto &a instância de Produto
	* @param Produto &b instância de Produto
	* @return retorna um double resultado da subtração dos preços de dois Produtos
	*/
	friend double operator- ( Produto &a, Produto &b );

	/**
	* @brief Sobrecarga do operador de comparação de igualdade para objeto Produto.
	* @detail Compara os códigos de barras de dois produtos a fim de verificar se são iguais
	* @param Produto &a instância de Produto
	* @param Produto &b instância de Produto
	* @return Se os códigos de barras forem iguais retorna true, se não, falso
	*/
	friend bool operator== (Produto &a, Produto &b);

private:

	/**
	* @brief Método virtual puro print
	* @detail Interface para impressão das informações de um Produto
	* @param ostream & operador de inserção
	* @return Retorna uma instância do operador de inserção
	*/
	virtual std::ostream& print( std::ostream& ) const = 0;
};
 
#endif
