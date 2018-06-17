/**
 * @file	bebida.h
 * @brief	Definição da classe Bebida em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include "produto.h"

using std::string;

/**
* @brief Classe Bebida, derivada de Produto
*/  
class Bebida : public Produto{
    public:
        
        /**
        * @brief Método construtor padrão de Bebida
        */  
        Bebida();

        /**
        * @brief Método construtor parametrizado de Bebida
        * @param int tag - categoria do Produto
        * @param string codigo - Codigo de barras do Produto
        * @param string descricao - Descrição do Produto
        * @param short preco - Preço do Produto
        * @param short teorAlcoolico - Descrição da porcentagem do teor alcoolico da bebida
        */  
        Bebida( int tag, string codigoBarra, string descricao, short preco, short teorAlcoolico );

        /**
        * @brief Interface destrutor de Produto definida para Bebida
        * @detail Método virtual da classe Produto redefinida para um objeto Bebida
        */
        ~Bebida();

    private:
        short teorAlcoolico; /**< define o teor alcoolico para um objeto Bebida */
        
    public:
        // getters

        /**
        * @brief Método de captura do teorAlcoolico
        * @return Retorna a porcentagem do teor alcoolico da bebida
        */
        short getTeorAlcoolico();

        // setters

        /**
        * @brief Método de atribuição de teorAlcoolico
        * @param Recebe string teorAlcoolico
        */
        void setTeorAlcoolico( short teorAlcoolico );

    private:

        /**
        * @brief Método virtual puro print
        * @detail Interface para impressão das informações de Bebida
        * @param ostream & operador de inserção
        * @return Retorna uma instância do operador de inserção
        */
        std::ostream& print( std::ostream &o ) const;
};

#endif