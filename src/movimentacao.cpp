#include "movimentacao.h"

Movimentacao::Movimentacao( int tipo, double valor ): tipo( tipo ), valor( valor ){
    cin >> dataTransacao;
    
}

Movimentacao::Movimentacao( Movimentacao& mov){
    this->tipo = mov.getTipo();
    this->valor = mov.getValor();
    this->dataTransacao = mov.getData();
}

Movimentacao::~Movimentacao(){}
/* 
void Movimentacao::saque( Conta& conta ){
    conta.setSaldo( conta.getSaldo() - valor );
}


void Movimentacao::transferencia( string, string, double ){}

void Movimentacao::deposito( Conta& conta ){
    conta.setSaldo( conta.getSaldo() + valor );
}

string Movimentacao::operacao (Conta& conta, int tipo ){
    string msg;
    switch(tipo){
        case 1:
            saque( conta );
            msg = "O saque de "  + std::to_string( valor ) + " foi efetuado com sucesso.";
            break;
        case 2:
            deposito( conta );
            msg = "O deposito de "  + std::to_string( valor ) + " foi efetuado com sucesso.";
            break;
    }

    return msg;
}
*/

int Movimentacao::getTipo(){
    return tipo;
}

double Movimentacao::getValor(){
    return valor;
}

Data Movimentacao::getData(){
    return dataTransacao;
}

std::ostream& operator<< (std::ostream &o, Movimentacao const mov){
    o << "Tipo:              " << mov.tipo << endl <<
         "Data da Transação: " << mov.dataTransacao << endl;
    return o;
}