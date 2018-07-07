#include <iostream>
using std::cout;
using std::endl;
#include "data.h"
#include <string>
using std::string;
#include "lista.h"
#include "conta.h"
#include "movimentacao.h"
#include "operacao_conta.h"
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <memory>


//using namespace cbancaria;

//g++ -Wall -ansi -std=c++11 -I ./include -o ./bin/homolog ./src/excecoes.cpp ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/operacao_conta.cpp ./src/homolog.cpp


int Conta::contDeConta = 0;

int main(){
    Movimentacao mov;
    mov.setTipo("Saque");
    mov.setValor( 550.45 );
    Data d;
    mov.setData( std::make_shared<Data> ( d ) );
    cout << mov.getData();

    cout << mov;

    //d.imprimeData();

    Conta c1("1", 1, "Bruno", 10000);
    Conta c2("1", 2, "Ágatha", 30000);
    Conta c3("1", 1, "Mika", 15000);
    Conta c4("1", 2, "João Pedro", 25000);
    
    Conta *c5 = new Conta("1", 3, "Willian", 10000);
    //c5->setTitular("Willian");
    vector<std::shared_ptr<Conta>> contas;
    cout << (*c5);
    contas.push_back(std::make_shared<Conta>(c1));
    contas.push_back(std::make_shared<Conta>(*c5));
    contas.push_back(std::make_shared<Conta>(c3));
    contas.push_back(std::make_shared<Conta>(c4));
    contas.push_back(std::make_shared<Conta>(c2));
    //OperacaoConta::armazenarContas( contas );
    
    for( auto it = contas.begin(); it != contas.end(); it++){
        cout << (*it)->getSaldo() << endl;
    }
    
    //cout << c1;
    cout << "Saldo em conta: R$ " << contas[0]->getSaldo() << endl;
    OperacaoConta::saque( *contas[0], 350.58 );
    OperacaoConta::deposito( *contas[0], 558.68 );
    cout << "Saldo em conta: R$ " << contas[0]->getSaldo() << endl;
    OperacaoConta::saque( *contas[0], 350.58 );
    OperacaoConta::deposito( *contas[0], 9960.67 );
    cout << "Saldo em conta: R$ " << contas[0]->getSaldo() << endl;
    cout << *contas[0];
    OperacaoConta::deposito( *contas[4], 558.68 );
    cout << contas[4]->getSaldo() << endl;

    OperacaoConta::transferencia( *contas[4], *contas[0], 256.34 );

    cout << endl;
    contas[0]->getMovimentacao().imprimir();
    contas[4]->getMovimentacao().imprimir();

    OperacaoConta::alteraLimite( *contas[0] );
    cout << *contas[0];

    OperacaoConta::alteraTipoConta( *contas[0] );
    cout << endl;

    contas[0]->exibirExtrato(5);

    cout << contas[4]->getSaldo();

    OperacaoConta::exibeExtrato( *contas[4], 5 );

    OperacaoConta::exibeExtrato( *contas[0], 5 );

    OperacaoConta::exibeSaldo( *contas[4] );

    OperacaoConta::armazenarContas( contas );
    //list<std::shared_ptr<Conta>> contas;
    //contas.push_back(c1);
    //contas.push_back(c1);
/* 
    ListaLigada<Conta> contas;
    contas.insereNoFinal(c1);
    contas.insereNoFinal(c2);
    contas.insereNoFinal(c3);
    contas.insereNoFinal(c4); */
/* 
    list<Conta> contas;
    contas.push_back(c1);
    contas.push_back(c2);
    contas.push_back(c3);
    contas.push_back(c4);
 */    /* 
    for(int i = 0; i < (int)contas.size(); i++){
        cout << *contas[i] << endl;
    }
 */


    

    return 0;
}