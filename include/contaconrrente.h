#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include <string>
using std::string;

class ContaCorrente{
    private:
        static int contDeConta;
        string agencia; /**< Descreve codigo da agência da conta */
        string conta; /**< Descreve codigo da conta */
        double saldo; /**< Informa os saldo da conta */
        bool status; /**< Informa se a conta é especial ou não */
        double limite; /**< Informa o limite total da conta */
        //Saldo, extrato, saque, transferência, deposito

    public:
        ContaCorrente( string, bool, double );
        ContaCorrente();
        ContaCorrente( ContaCorrente & );
        ~ContaCorrente();

        void saque( double );
        void transferencia( string, string, double );
        void deposito( string, string, double );

        string getAgencia();
        void setAgencia( string );

        string getConta();
        void setConta( string );

        double getSaldo();
        void setSaldo( double );

        bool getStatus();
        void setStatus( bool );

        double getLimite();
        void setLimite( double );
};

#endif