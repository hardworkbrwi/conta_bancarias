#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
 
#include "data.h"
/*
#include "lista.h"
#include "conta.h"
#include "excecoes.h"
 */

//namespace cbancaria{

class Movimentacao{
    private:
        string tipo;
        string origem;
        double valor;
        shared_ptr<Data> dataTransacao;
       
    public:
        Movimentacao();
        Movimentacao( Movimentacao& );
        ~Movimentacao();

        string getTipo();
        void setTipo( string );
        string getOrigem();
        void setOrigem( string );
        double getValor();
        void setValor( double );
        shared_ptr<Data> getData();
        void setData( shared_ptr<Data> );
        
        friend std::ostream& operator<< (std::ostream &o, Movimentacao const mov);
};

//}
#endif