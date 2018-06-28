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

string Movimentacao::getValor(){
    return valor;
}

void Movimentacao::setValor( string valor ){
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
    o << "Tipo: " << moviment.tipo << endl <<
         "Valor: R$ " << moviment.valor << endl <<
         "Data da Transação: " /*<< moviment.dataTransacao */<< endl;
         moviment.dataTransacao->imprimeData();
    return o;
}