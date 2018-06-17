#include "movimentacao.h"

Movimentacao::Movimentacao( string tipo ): tipo( tipo ){
    cin >> dataTransacao;
}

Movimentacao::~Movimentacao(){}
/*
void Movimentacao::saque( double ){

}
void Movimentacao::transferencia( string, string, double ){}
void Movimentacao::deposito( string, string, double ){}
*/
std::ostream& operator<< (std::ostream &o, Movimentacao const mov){
    o << "Tipo:              " << mov.tipo << endl <<
         "Data da Transação: " << mov.dataTransacao << endl;
    return o;
}