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

//namespace cbancaria{

class Conta{
    private:
        static int contDeConta;
        string agencia; /**< Descreve codigo da agência da conta */
        string conta; /**< Descreve codigo da conta */
        string titular; /**< Define o titular da conta */
        double saldo; /**< Informa os saldo da conta */
        int tipo; /**< Informa a qual o tipo de conta está relacionada (corrente, poupança, etc) */
        double limite; /**< Informa o limite total da conta */
        ListaLigada<Movimentacao> movimentacoes; /**< Lista de movimentações realizadas */
        //vector<movimentacao> movimentacoes;
        

    public:
        string tiposContas[3] = {"Conta Corrente", "Conta Poupança", "Conta Salário"};
        Conta( string agencia, int tipo, string titular, double limite );
        Conta();
        Conta( Conta & );
        ~Conta();

        void adicionarMovimentacao( Movimentacao mov );

        void exibirExtrato( int );
        
        int getContDeConta();

        string getAgencia();
        void setAgencia( string );

        string getConta();
        void setConta( string );

        string getTitular();
        void setTitular( string );

        double getSaldo();
        void setSaldo( double );

        int getTipo();
        void setTipo( int );

        double getLimite();
        void setLimite( double );

        //ListaLigada<movimentacao> getMovimentacao();
        ListaLigada<Movimentacao> getMovimentacao();
        void setMovimentacao( ListaLigada<Movimentacao> );       

        friend std::ostream& operator<< (std::ostream &o, Conta const c);

        friend bool operator== (Conta& a, Conta& b);
};

//}

#endif