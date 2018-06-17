#include <iostream>
#include <string>
using std::string;
#include "lista.h"
#include "movimentacao.h"
#include "conta.h"


Conta::Conta( string agencia, string operacao, string titular, double limite ):
            agencia( agencia ),
            titular( titular ),
            saldo( 0 ),
            operacao( operacao ),
            limite( limite ){
                Conta::contDeConta++;
                this->conta = std::to_string(contDeConta);
}

Conta::Conta(){}

Conta::Conta( Conta& c ){
    this->agencia = c.getAgencia();
    this->conta = c.getConta();
    this->titular = c.getTitular();
    this->saldo = c.getSaldo();
    this->operacao = c.getOperacao();
    this->limite = c.getLimite();
    this->movimentacoes = c.getMovimentacao();
}

Conta::~Conta(){}


void Conta::saque( double valor ){
    movimentacao op;
    op.tipo = 1;
    op.valor = valor;
    cin >> op.dataTransacao;
    //movimentacoes.InsereNoFinal( op );
    movimentacoes.push_back( op );
    this->saldo -= valor;

}

void Conta::transferencia( Conta& contaB, double valor ){
    movimentacao op;
    op.tipo = 3;
    op.valor = valor;
    cin >> op.dataTransacao;
    //movimentacoes.InsereNoFinal( op );
    this->movimentacoes.push_back( op );
    contaB.movimentacoes.push_back( op );
    this->saldo -= valor;
    contaB.setSaldo( contaB.getSaldo() + valor );
}

void Conta::deposito( double valor ){
    movimentacao op;
    op.tipo = 2;
    op.valor = valor;
    cin >> op.dataTransacao;
    //movimentacoes.InsereNoFinal( op );
    movimentacoes.push_back( op );
    this->saldo += valor;
}

string Conta::getAgencia(){
    return agencia;
}

void Conta::setAgencia( string agencia ){
    this->agencia = agencia;
}

string Conta::getConta(){
    return conta;
}

void Conta::setConta( string conta ){
    this->conta = conta;
}

string Conta::getTitular(){
    return titular;
}

void Conta::setTitular( string titular ){
    this->titular = titular;
}

double Conta::getSaldo(){
    return saldo;
}

void Conta::setSaldo( double saldo ){
    this->saldo = saldo;
}

string Conta::getOperacao(){
    return operacao;
}

void Conta::setOperacao( string operacao ){
    this->operacao = operacao;
}

double Conta::getLimite(){
    return limite;
}

void Conta::setLimite( double limite ){
    this->limite = limite;
}
/* 
ListaLigada<movimentacao> Conta::getMovimentacao(){
    return movimentacoes;
}
 */
vector<movimentacao> Conta::getMovimentacao(){
    return movimentacoes;
}

bool operator== (Conta& a, Conta& b){
    if( a.getAgencia() == b.getAgencia() && a.getConta() == b.getConta() )
        return true;

    return false;
}

std::ostream& operator<< (std::ostream &o, Conta const c){
    o << "###### INFORMAÇÕES DA CONTA ######" << endl
    << "Agência: " << c.agencia << " | " << "Conta: " << c.conta << endl
    << "Operaçao: " << c.operacao << endl
    << "Titular: " << c.titular << endl    
    << "Limite: " << c.limite << endl;

    return o;
}