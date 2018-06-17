#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "data.h"
#include "lista.h"
#include "conta.h"

class Movimentacao{
    private:
        int tipo;
        double valor;  
        Data dataTransacao;
        /* 
        void saque( Conta& );
        void deposito( Conta& );
 */
    public:
        Movimentacao( int tipo, double valor );
        Movimentacao( Movimentacao& );
        ~Movimentacao();

        //string operacao( Conta& conta, int tipo );

        
        //void transferencia( Conta&, string, string, double );

        int getTipo();
        double getValor();
        Data getData();
        

        friend std::ostream& operator<< (std::ostream &o, Movimentacao const mov);


};

#endif