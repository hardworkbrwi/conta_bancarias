#include <iostream>
using std::cout;
using std::endl;

#include "conta.h"
#include "movimentacao.h"

//g++ -Wall -ansi -std=c++11 -I ./include -o homolog ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/homolog.cpp

int Conta::contDeConta = 0;

int main(){
    //Movimentacao m( "Saque" );
    Conta c("1", "Conta Corrente", "Bruno", 5000);

    cout << c.getAgencia() << endl;
    cout << c.getConta() << endl;
    cout << c.getOperacao() << endl;

    cout << c;

    cout << c.getSaldo() << endl;

    c.deposito( 500 );

    cout << c.getSaldo() << endl;

    c.saque( 65 );

    cout << c.getSaldo() << endl;

    

    return 0;
}