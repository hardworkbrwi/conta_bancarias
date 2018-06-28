#ifndef OPERACAOCONTA_H
#define OPERACAOCONTA_H

//#include <iostream>


#include "data.h"
#include "movimentacao.h"
#include "conta.h"
#include "excecoes.h"

class OperacaoConta{
    private:
        string conversaoOperacoes( int );
    public:
        static bool saque( Conta &, double );
        static bool deposito( Conta &, double );
        static bool transferencia( Conta &, Conta &, double );
        static bool alteraLimite( Conta &, double );
        static bool alteraTipoConta( Conta & );

        friend std::ostream& operator<< (std::ostream &o, OperacaoConta const opConta);

};

#endif