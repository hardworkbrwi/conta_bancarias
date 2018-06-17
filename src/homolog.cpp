#include <iostream>
using std::cout;
using std::endl;

#include "conta.h"
#include "movimentacao.h"

int Conta::contDeConta = 0;

int main(){
    //Movimentacao m( "Saque" );
    Conta c("1", "Conta Corrente", "Bruno", 5000);

    cout << c.getAgencia() << endl;
    cout << c.getConta() << endl;
    cout << c.getOperacao() << endl;

    cout << c;

    

    return 0;
}