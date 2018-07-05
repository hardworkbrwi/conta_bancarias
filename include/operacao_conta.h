#ifndef OPERACAOCONTA_H
#define OPERACAOCONTA_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
#include <list>
using std::list;
#include <vector>
using std::vector;

#include "lista.h"
#include "data.h"
#include "movimentacao.h"
#include "conta.h"
#include "excecoes.h"

#define TAGCONTA "$$"
#define TAGMOV "->"

//namespace cbancaria{

class OperacaoConta{
    private:
        string conversaoOperacoes( int );
    public:
        static bool ArmazenarContas( vector<Conta> );
        static shared_ptr<Conta> CriarContas( string agencia, string titular, int tipoConta, double limite );
        static bool saque( Conta &, double );
        static bool deposito( Conta &, double );
        static bool transferencia( Conta &, Conta &, double );
        static bool alteraLimite( Conta & );
        static bool alteraTipoConta( Conta & );
        static void exibeSaldo( Conta &conta );
        static void exibeExtrato( Conta&conta, int );

        friend std::ostream& operator<< (std::ostream &o, OperacaoConta const opConta);

};

//}

#endif