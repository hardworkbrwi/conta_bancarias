#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "lista.h"
#include "movimentacao.h"
#include "conta.h"
#include "data.h"

typedef struct{
    int tipo;
    double valor;
    Data dataTransacao;
}movimentacao;

class Conta{
    private:
        static int contDeConta;
        string agencia; /**< Descreve codigo da agência da conta */
        string conta; /**< Descreve codigo da conta */
        string titular;
        double saldo; /**< Informa os saldo da conta */
        string operacao; /**< Informa a qual operação esta conta está relacionada (corrente, poupança, etc) */
        double limite; /**< Informa o limite total da conta */
        //ListaLigada<movimentacao> movimentacoes;
        vector<movimentacao> movimentacoes;
        //Saldo, extrato, saque, transferência, deposito

    public:
        Conta( string agencia, string operacao, string titular, double limite );
        Conta();
        Conta( Conta & );
        ~Conta();

        void saque( double );
        void transferencia( Conta&, double );
        void deposito( double );
        
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

        //ListaLigada<movimentacao> getMovimentacao();
        vector<movimentacao> getMovimentacao();        

        friend std::ostream& operator<< (std::ostream &o, Conta const c);

        friend bool operator== (Conta& a, Conta& b);

        
};



#endif