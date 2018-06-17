#include <iostream>
using std::cout;
using std::endl;

#include "conta.h"
#include "movimentacao.h"

//g++ -Wall -ansi -std=c++11 -I ./include -o homolog ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/homolog.cpp

int Conta::contDeConta = 0;

int main(){
    //Movimentacao m( "Saque" );
    Conta c1("1", "Conta Corrente", "Bruno", 5000);

    cout << c1.getAgencia() << endl;
    cout << c1.getConta() << endl;
    cout << c1.getOperacao() << endl;

    cout << c1;

    cout << c1.getSaldo() << endl;

    c1.deposito( 500 );

    cout << c1.getSaldo() << endl;

    c1.saque( 65 );

    cout << c1.getSaldo() << endl;

    Conta c2("1", "Conta Corrente", "Willian", 5000);

    if( c1 == c2 )
        cout << "Conta 1 é igual a Conta 2" << endl;
    else
        cout << "Conta 1 é diferente da Conta 2" << endl;

    if( c2 == c2 )
        cout << "Conta 1 é igual a Conta 2" << endl;
    else
        cout << "Conta 1 é diferente da Conta 2" << endl;

    c2.deposito( 800 );
    cout << c2.getSaldo() << endl;
    c2.saque( 200 );
    cout << c2.getSaldo() << endl;

    c2.transferencia( c1, 150 );
    cout << c1.getSaldo() << endl;
    cout << c2.getSaldo() << endl;
    


    

    return 0;
}