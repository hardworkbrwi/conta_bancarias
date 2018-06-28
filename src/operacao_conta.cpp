#include "operacao_conta.h"

bool OperacaoConta::saque( Conta &conta, double valor){
    try{
        if( conta.getSaldo() < valor ) throw Excecoes();
        else{
            Movimentacao mov;
            mov.setTipo( "SAQUE" );
            mov.setValor( std::to_string( valor ) );
            
            conta.setSaldo( conta.getSaldo() + valor );

            Data d;
            mov.setData( std::make_shared<Data> ( d ) );

            conta.setMovimentacao( mov );

            return true;
        }
    }catch( Excecoes &ex ){
        std::cerr << ex.what() << std::endl;
          return false;
    }catch( ... ){
        std::cerr << "Erro desconhecido para a operacao de SAQUE!" << std::endl;
        return false;
    }
}

bool OperacaoConta::deposito( Conta &, double ){return true;}
bool OperacaoConta::transferencia( Conta &, Conta &, double ){return true;}
bool OperacaoConta::alteraLimite( Conta &, double ){return true;}
bool OperacaoConta::alteraTipoConta( Conta & ){return true;}

string OperacaoConta::conversaoOperacoes( int op ){
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
//########################################

string Movimentacao::conversaoOperacoes( int op ){
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
            return "OPERACÃO INVÁLIDA"
            break;
    }
}

void Movimentacao::transferencia( Conta &contaA, Conta &contaB, double valor ){
    try{
        if( conta.getSaldo() < valor ) throw Excecoes();
        else{
            this->mov.tipo = 2;
            this->mov.valor = valor;
            contaA.setSaldo( contaA.getSaldo() - valor );
            contaB.setSaldo( contaB.getSaldo() + valor );
            this->mov.dataTrasacao = new Data();
        }
    }catch( Excecoes &ex )
        cerr << ex.what() << endl;
    catch( ... )
        cerr << "Erro desconhecido para a operacao de " << conversaoOperacoes( this->mov.tipo ) << endl;
}
void Movimentacao::deposito( double ){}


movimentacao Movimentacao::getMovimentacao(){
    return mov;
}
std::ostream& operator<< (std::ostream &o, Movimentacao const moviment){
    o << "Tipo:              " << moviment.mov.tipo << endl <<
         "Data da Transação: " << moviment.mov.dataTransacao << endl;
    return o;
}
*/