#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "data.h"

class Movimentacao{
    private:
        string tipo;
        Data dataTransacao;        

    public:
        Movimentacao( string tipo );
        ~Movimentacao();
/*
        virtual void saque( double ) = 0;
        virtual void transferencia( string, string, double ) = 0;
        virtual void deposito( string, string, double ) = 0;
*/
        friend std::ostream& operator<< (std::ostream &o, Movimentacao const mov);


};

#endif