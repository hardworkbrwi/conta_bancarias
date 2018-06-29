#ifndef OPERACAOCONTA_H
#define OPERACAOCONTA_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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
        static bool alteraLimite( Conta & );
        static bool alteraTipoConta( Conta & );

        friend std::ostream& operator<< (std::ostream &o, OperacaoConta const opConta);

};

#endif