#include <iostream>
using std::endl;
using std::cerr;
#include <string>
using std::string;
#include <exception>

//#include "lista.h"
//#include "movimentacao.h"
#include "conta.h"

//namespace contabancaria{

    Conta::Conta( string agencia, int operacao, string titular, double limite ):
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

    void Conta::aumentaLimite( double valor ){
        this->limite += valor;
    }

    void Conta::diminuiLimite( double valor ){
        this->limite -= valor;
    }

    string Conta::converteOperacao( int op ){
        switch( op ){
            case 1:
                return "SAQUE";
                break;
            case 2:
                return "TRANSFERÊNCIA";
                break;
            case 3:
                return "DEPÓSITO";
                break;
            default:
                return "OPERACÃO INVÁLIDA";
                break;
        }
    }

    /* 
    void Conta::saque( double valor ){
        cout << "###### SAQUE ######" << endl;
        cout << "Valor: " << valor << endl;
        try{
            
        }
        movimentacao op;
        op.tipo = 1;
        op.valor = valor;
        cin >> op.dataTransacao;
        //movimentacoes.InsereNoFinal( op );
        movimentacoes.push_back( op );
        this->saldo -= valor;
        cout << "###### SAQUE EFETUADO COM SUCESSO ######" << endl;

    }

    void Conta::transferencia( Conta& contaB, double valor ){
        cout << "###### TRANSFERÊNCIA ######" << endl;
        cout << "Valor: " << valor << endl;
        cout << contaB << endl;
        movimentacao op;
        op.tipo = 3;
        op.valor = valor;
        cin >> op.dataTransacao;
        //movimentacoes.InsereNoFinal( op );
        this->movimentacoes.push_back( op );
        contaB.movimentacoes.push_back( op );
        this->saldo -= valor;
        contaB.setSaldo( contaB.getSaldo() + valor );
        cout << "###### TRANSFERÊNCIA EFETUADA COM SUCESSO ######" << endl;
    }

    void Conta::deposito( double valor ){
        cout << "###### DEPÓSITO ######" << endl;
        cout << "Valor: " << valor << endl;
        movimentacao op;
        op.tipo = 2;
        op.valor = valor;
        cin >> op.dataTransacao;
        //movimentacoes.InsereNoFinal( op );
        movimentacoes.push_back( op );
        this->saldo += valor;
        cout << "###### DEPÓSITO EFETUADO COM SUCESSO ######" << endl;
    }
 */
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

    int Conta::getOperacao(){
        return operacao;
    }

    void Conta::setOperacao( int operacao ){
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
    ListaLigada<movimentacao> Conta::getMovimentacao(){
        return movimentacoes;
    }

    void Conta::setMovimentacao( Movimentacao mov ){
        movimentacaoes.insereNoFinal( mov );
    }

    bool operator== (Conta& a, Conta& b){
        if( a.getAgencia() == b.getAgencia() && a.getConta() == b.getConta() )
            return true;

        return false;
    }

    std::ostream& operator<< (std::ostream &o, Conta const c){
        o << "###### INFORMAÇÕES DA CONTA ######" << endl
        << "Agência: " << c.agencia << " | " << "Conta: " << c.conta << endl
        << "Operaçao: " << c.tiposContas[c.operacao-1] << endl
        << "Titular: " << c.titular << endl    
        << "Limite: " << c.limite << endl;

        return o;
    }

//}