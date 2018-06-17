/**
 * @file	roupa.h
 * @brief	Definição da classe Roupa em C++
 * @author	Bruno César L. Silva
 * @since	10/05/2018
 * @date	14/05/2018
 */

#ifndef ROUPA_H
#define ROUPA_H

#include "produto.h"

using std::string;

/**
* @brief Classe Roupa, derivada de Produto
*/
class Roupa : public Produto{
    public:
        /**
        * @brief Método construtor padrão de Roupa
        */  
        Roupa();

        /**
        * @brief Método construtor parametrizado de Roupa
        * @param int tag - categoria do Produto
        * @param string codigo - Codigo de barras do Produto
        * @param string descricao - Descrição do Produto
        * @param short preco - Preço do Produto
        * @param string marca - Recebe a marca da roupa
        * @param string sexo - Define a categoria da roupa em relação a sexo
        * @param string tamanho - Define o tamanho da roupa
        */  
        Roupa( int tag, string codigoBarra, string descricao, short preco, 
                string marca, string sexo, string tamanho );

        /**
        * @brief Interface destrutor de Produto definida para Roupa
        * @detail Método virtual da classe Produto redefinida para um objeto Roupa
        */
        ~Roupa();

    private:
        string marca; /**< define a marca para um objeto Roupa */
        string sexo; /**< define a categoria para um objeto Roupa */
        string tamanho; /**< define o tamanho para um objeto Roupa */
        
    public:
        // getters

        /**
        * @brief Método de captura de marca
        * @return Retorna a marca do produto
        */
        string getMarca();

        /**
        * @brief Método de captura de sexo
        * @return Retorna a categoria sexo da Roupa
        */
        string getSexo();

        /**
        * @brief Método de captura de tamanho
        * @return Retorna o tamanho da roupa
        */
        string getTamanho();

        // setters

        /**
        * @brief Método de atribuição de marca
        * @param Recebe string marca
        */
        void setMarca( string marca );

        /**
        * @brief Método de atribuição de categoria sexo
        * @param Recebe string sexo
        */
        void setSexo( string sexo );

        /**
        * @brief Método de atribuição de tamanho
        * @param Recebe string tamanho
        */
        void setTamanho( string tamanho );

    private:

        /**
        * @brief Método virtual puro print
        * @detail Interface para impressão das informações de Roupa
        * @param ostream & operador de inserção
        * @return Retorna uma instância do operador de inserção
        */
        std::ostream& print( std::ostream &o ) const;
};

#endif