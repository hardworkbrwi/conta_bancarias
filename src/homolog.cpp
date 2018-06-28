#include <iostream>
using std::cout;
using std::endl;
//#include "data.h"
#include <string>
using std::string;
#include "lista.h"
//#include "movimentacao.h"
//#include "operacao_conta.h"

//g++ -Wall -ansi -std=c++11 -I ./include -o ./bin/homolog ./src/excecoes.cpp ./src/data.cpp ./src/movimentacao.cpp ./src/conta.cpp ./src/operacao_conta.cpp ./src/homolog.cpp


//int Conta::contDeConta = 0;

int main(){
    /* 
    Movimentacao mov;
    mov.setTipo("Saque");
    mov.setValor("550.45");
    Data d;
    mov.setData( std::make_shared<Data> (d) );

    cout << mov;

    //d.imprimeData();
     */
    ListaLigada<string> lista;
    lista.insereNoFinal("Bruno");
    lista.insereNoFinal("Mika");
    lista.insereNoInicio("Agatha");
    lista.imprimir();
    cout << lista.getCabeca() << endl;


    

    return 0;
}