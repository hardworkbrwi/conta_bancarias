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

    Conta::Conta( string agencia, int tipo, string titular, double limite ):
                agencia( agencia ),
                titular( titular ),
                saldo( 0 ),
                tipo( tipo ),
                limite( limite ){
                    Conta::contDeConta++;
                    this->conta = std::to_string( contDeConta );
    }

    Conta::Conta(){
        this->saldo = 0;
        this->limite = 0;
        Conta::contDeConta++;
        this->conta = std::to_string( contDeConta );
    }

    Conta::Conta( Conta& c ){
        this->agencia = c.getAgencia();
        this->conta = c.getConta();
        this->titular = c.getTitular();
        this->saldo = c.getSaldo();
        this->tipo = c.getTipo();
        this->limite = c.getLimite();
        this->movimentacoes = c.getMovimentacao();
    }

    Conta::~Conta(){}

    void Conta::adicionarMovimentacao( Movimentacao mov ){
        this->movimentacoes.insereNoInicio( mov );
    }

    void Conta::exibirExtrato( int periodo = 5 ){
        Data d;
        int dataPeriodo = ( d.getDia() - periodo ) % 30;
        //(diaAtual - periodo)mod30
        for(int i = 0; i < this->movimentacoes.getTamanho(); i++){
            Movimentacao mov;
            mov = this->movimentacoes.getElemento(i);
            if( mov.getData()->getDia() >= dataPeriodo ){
                cout << mov << endl;
            }
        }        
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

    int Conta::getTipo(){
        return tipo;
    }

    void Conta::setTipo( int tipo ){
        this->tipo = tipo;
    }

    double Conta::getLimite(){
        return limite;
    }

    void Conta::setLimite( double limite ){
        this->limite = limite;
    }
    
    ListaLigada<Movimentacao> Conta::getMovimentacao(){
        return movimentacoes;
    }

    void Conta::setMovimentacao( ListaLigada<Movimentacao> mov ){
        this->movimentacoes = mov;
    }

    bool operator== ( Conta& a, Conta& b ){
        if( a.getAgencia() == b.getAgencia() && a.getConta() == b.getConta() )
            return true;

        return false;
    }

    std::ostream& operator<< ( std::ostream &o, Conta const c ){
        o << endl << "###### INFORMAÇÕES DA CONTA ######" << endl
        << "Agência: " << c.agencia << " | " << "Conta: " << c.conta << endl
        << "Operaçao: " << c.tiposContas[ c.tipo-1 ] << endl
        << "Titular: " << c.titular << endl;
        o.precision(2);
        o << "Limite: R$ " << std::fixed << c.limite << endl << endl;
        
        return o;
    }

//}