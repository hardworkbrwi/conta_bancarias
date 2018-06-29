#include <iostream>
using std::cout;
using std::endl;
#include "data.h"
#include <string>
using std::string;
#include "lista.h"
#include "movimentacao.h"
#include "operacao_conta.h"
#include <vector>
using std::vector;

//g++ -Wall -ansi -std=c++11 -I ./include -o ./bin/homolog ./src/excecoes.cpp ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/operacao_conta.cpp ./src/homolog.cpp


int Conta::contDeConta = 0;

int main(){
    Movimentacao mov;
    mov.setTipo("Saque");
    mov.setValor( 550.45 );
    Data d;
    mov.setData( std::make_shared<Data> (d) );
    cout << mov.getData();

    cout << mov;

    //d.imprimeData();

    Conta c1("1", 1, "Bruno", 10000);
    Conta c2("1", 2, "Ágatha", 30000);
    Conta c3("1", 1, "Mika", 15000);
    Conta c4("1", 2, "João Pedro", 25000);

    cout << c1;
    cout << "Saldo em conta: R$ " << c1.getSaldo() << endl;
    OperacaoConta::saque( c1, 350.58 );
    OperacaoConta::deposito( c1, 558.68 );
    cout << "Saldo em conta: R$ " << c1.getSaldo() << endl;
    OperacaoConta::saque( c1, 350.58 );
    OperacaoConta::deposito( c1, 9960.67 );
    cout << "Saldo em conta: R$ " << c1.getSaldo() << endl;
    cout << c1;
    OperacaoConta::deposito( c2, 558.68 );

    OperacaoConta::transferencia( c2, c1, 256.34 );

    cout << endl;
    c1.getMovimentacao().imprimir();
    c2.getMovimentacao().imprimir();

    OperacaoConta::alteraLimite( c1 );
    cout << c1;

    OperacaoConta::alteraTipoConta( c1 );

    c1.exibirExtrato(5);
/* 
    vector<Conta> contas;
    contas.push_back(c1);
    contas.push_back(c2);
    contas.push_back(c3);
    contas.push_back(c4);
    
    for(int i = 0; i < (int)contas.size(); i++){
        cout << contas[i] << endl;
    }
     */


    

    return 0;
}