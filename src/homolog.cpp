#include <iostream>
using std::cout;
using std::endl;

#include "conta.h"
#include "movimentacao.h"
#include "lista.h"
#include "fruta.h"

//g++ -Wall -ansi -std=c++11 -I ./include -o homolog ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/homolog.cpp

int Conta::contDeConta = 0;

int main(){

    Conta c1("1", "Conta Corrente", "Bruno", 5000);
    c1.deposito( 500 );
    Conta c2("1", "Conta Corrente", "Willian", 5000);
    c2.deposito( 800 );
    /* 
    Fruta( int tag, std::string codigo, std::string descricao, short preco, 
			std::string data, short validade );
             */
    Fruta f1(1, "1", "banana", 1.50, "11/06/2018", 10);
    Fruta f2(1, "2", "maçã", 3.50, "11/06/2018", 10);
    //Movimentacao m( "Saque" );
    /* 
    

    cout << c1.getAgencia() << endl;
    cout << c1.getConta() << endl;
    cout << c1.getOperacao() << endl;

    cout << c1;

    cout << c1.getSaldo() << endl;

    

    cout << c1.getSaldo() << endl;

    c1.saque( 65 );

    cout << c1.getSaldo() << endl;

    

    if( c1 == c2 )
        cout << "Conta 1 é igual a Conta 2" << endl;
    else
        cout << "Conta 1 é diferente da Conta 2" << endl;

    if( c2 == c2 )
        cout << "Conta 1 é igual a Conta 2" << endl;
    else
        cout << "Conta 1 é diferente da Conta 2" << endl;

    
    cout << c2.getSaldo() << endl;
    c2.saque( 200 );
    cout << c2.getSaldo() << endl;

    c2.transferencia( c1, 150 );
    cout << c1.getSaldo() << endl;
    cout << c2.getSaldo() << endl;
     */
    ListaLigada<Conta> contas;
    contas.InsereNoFinal(c1);
    contas.InsereNoFinal(c2);

    ListaLigada<Movimentacao> mov;

    cout << c1;
    cout << c2;
    cout << c1.getSaldo() << endl;
    c1.saque( f1 + f2 );
    cout << c1.getSaldo() << endl;

    cout << c1;
    cout << endl << endl;


    

    return 0;
}