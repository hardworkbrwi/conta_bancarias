#include "movimentacao.h"

Movimentacao::Movimentacao(){}

Movimentacao::Movimentacao( Movimentacao& moviment){
    this->tipo = moviment.getTipo();
    this->valor = moviment.getValor();
    this->dataTransacao = moviment.getData();
}

string Movimentacao::getTipo(){
    return tipo;
}

void Movimentacao::setTipo( string tipo ){
    this->tipo = tipo;
}

double Movimentacao::getValor(){
    return valor;
}

void Movimentacao::setValor( double valor ){
    this->valor = valor;
}

shared_ptr<Data> Movimentacao::getData(){
    return dataTransacao;
}

void Movimentacao::setData( shared_ptr<Data> data ){
    this->dataTransacao = data;

}
Movimentacao::~Movimentacao(){}
std::ostream& operator<< (std::ostream &o, Movimentacao const moviment){
    o << "Tipo: " << moviment.tipo << endl;
    o.precision( 2 );
    o << "Valor: R$ " << std::fixed << moviment.valor << endl <<
         "Data da Transação: " /*<< moviment.dataTransacao */<< endl;
         moviment.dataTransacao->imprimeData();
    return o;
}