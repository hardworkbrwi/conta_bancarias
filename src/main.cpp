#include <iostream>
using std::cout;
using std::endl;

#include "conta.h"
#include "movimentacao.h"
#include "lista.h"
#include "fruta.h"
#include "bebida.h"

//g++ -Wall -ansi -std=c++11 -I ./include -o homolog ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/homolog.cpp

int Conta::contDeConta = 0;

int main(){

    Conta conta("1", "Conta Corrente", "João Paulo", 5000);
    conta.deposito( 500 );

    Bebida bebida(1, "1", "schim", 2.50, 35);
    Fruta fruta(1, "2", "maçã", 1.35, "11/06/2018", 10);

    cout << conta;
    cout << conta.getSaldo() << endl;
    conta.saque( bebida + fruta );
    cout << conta.getSaldo() << endl;

    cout << conta;
    cout << endl << endl;


    

    return 0;
}