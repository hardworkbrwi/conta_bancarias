#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
using std::string;
//#include <vector>
//using std::vector;
#include "lista.h"
#include "conta.h"
#include "data.h"
#include "movimentacao.h"

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
        string titular; /**< Define o titular da conta */
        double saldo; /**< Informa os saldo da conta */
        int operacao; /**< Informa a qual operação esta conta está relacionada (corrente, poupança, etc) */
        double limite; /**< Informa o limite total da conta */
        ListaLigada<Movimentacao> movimentacoes; /**< Lista de movimentações realizadas */
        //vector<movimentacao> movimentacoes;
        

    public:
        string tiposContas[3] = {"Conta Corrente", "Conta Poupança", "Conta Salário"};
        Conta( string agencia, int operacao, string titular, double limite );
        Conta();
        Conta( Conta & );
        ~Conta();

        string converteOperacao( int op );

        void aumentaLimite( double );
        void diminuiLimite( double );
        
        int getContDeConta();

        string getAgencia();
        void setAgencia( string );

        string getConta();
        void setConta( string );

        string getTitular();
        void setTitular( string );

        double getSaldo();
        void setSaldo( double );

        int getOperacao();
        void setOperacao( int );

        double getLimite();
        void setLimite( double );

        //ListaLigada<movimentacao> getMovimentacao();
        ListaLigada<movimentacao> getMovimentacao();
        void setMovimentacao( Movimentacao );       

        friend std::ostream& operator<< (std::ostream &o, Conta const c);

        friend bool operator== (Conta& a, Conta& b);
        
};

#endif