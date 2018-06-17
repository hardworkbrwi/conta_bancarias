#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
using std::string;
using std::stringstream;
#include "conta.h"
#include "lista.h"
#include "movimentacao.h"

class Conta{
    private:
        static int contDeConta;
        string agencia; /**< Descreve codigo da agência da conta */
        string conta; /**< Descreve codigo da conta */
        string titular;
        double saldo; /**< Informa os saldo da conta */
        string operacao; /**< Informa a qual operação esta conta está relacionada (corrente, poupança, etc) */
        double limite; /**< Informa o limite total da conta */
        ListaLigada<Movimentacao> movimentacoes;
        //Saldo, extrato, saque, transferência, deposito

    public:
        Conta( string agencia, string operacao, string titular, double limite );
        Conta();
        Conta( Conta & );
        ~Conta();

        /*
        void saque( double );
        void transferencia( string, string, double );
        void deposito( string, string, double );
        */
        
        int getContDeConta();

        string getAgencia();
        void setAgencia( string );

        string getConta();
        void setConta( string );

        string getTitular();
        void setTitular( string );

        double getSaldo();
        void setSaldo( double );

        string getOperacao();
        void setOperacao( string );

        double getLimite();
        void setLimite( double );

        ListaLigada<Movimentacao> getMovimentacao();

        friend std::ostream& operator<< (std::ostream &o, Conta const c);

        
};



#endif