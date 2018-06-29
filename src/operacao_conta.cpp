#include "operacao_conta.h"

bool OperacaoConta::saque( Conta &conta, double valor){
    try{
        if( conta.getSaldo() < valor ) throw Excecoes();
        else{
            Movimentacao mov;
            mov.setTipo( "SAQUE" );
            mov.setValor( valor );
            
            conta.setSaldo( conta.getSaldo() - valor );

            Data d;
            mov.setData( std::make_shared<Data> ( d ) );

            conta.adicionarMovimentacao( mov );

            return true;
        }
    }catch( Excecoes &ex ){
        //ex.lancaMsg( "SALDO EM CONTA INSULFICIENTE!" );
        std::cerr << ex.what() << std::endl;
          return false;
    }catch( ... ){
        std::cerr << "Erro desconhecido para a operacao de SAQUE!" << std::endl;
        return false;
    }
}

bool OperacaoConta::deposito( Conta &conta, double valor ){
    try{
        if( conta.getSaldo() + valor > conta.getLimite() ) throw Excecoes();
        else{
            Movimentacao mov;
            mov.setTipo( "DEPÓSITO" );
            mov.setValor( valor );
            
            conta.setSaldo( conta.getSaldo() + valor );

            Data d;
            mov.setData( std::make_shared<Data> ( d ) );

            conta.adicionarMovimentacao( mov );

            return true;
        }
    }catch( Excecoes &ex ){
        //ex.lancaMsg( "SALDO EM CONTA INSULFICIENTE!" );
        std::cerr << ex.what() << std::endl;
          return false;
    }catch( ... ){
        std::cerr << "Erro desconhecido para a operacao de Deposito!" << std::endl;
        return false;
    }
}

bool OperacaoConta::transferencia( Conta &contaA, Conta &contaB, double valor ){
    try{
        if( !(saque( contaA, valor )) && !(deposito( contaB, valor )) ) throw Excecoes();
        else{
            saque( contaA, valor );
            deposito( contaB, valor );
        }
    }catch( Excecoes &ex ){
        //ex.lancaMsg( "SALDO EM CONTA INSULFICIENTE!" );
        std::cerr << ex.what() << std::endl;
          return false;
    }catch( ... ){
        std::cerr << "Erro desconhecido para a operacao de Transferência!" << std::endl;
        return false;
    }
    
    return true;
}

bool OperacaoConta::alteraLimite( Conta &conta ){
    char op;
    double valor;
    cout << "1 << AUMENTAR LIMITE DA CONTA" << endl
         << "2 << REDUZ LIMITE DA CONTA" << endl;
    cin >> op;
    cin.ignore();
    cout << "Entre com o valor: ";
    cin >> valor;
    cin.ignore();
    switch( op ){
        case '1':
            conta.setLimite( conta.getLimite() + valor );
            break;
        case '2':
            conta.setLimite( conta.getLimite() - valor );
            break;
        default:
            cout << "Operação inválida.";
            return false;
    }

    return true;
}

bool OperacaoConta::alteraTipoConta( Conta &conta ){
    int op;
    //int tipo;
    cout << "1 << CONTA CORRENTE" << endl
         << "2 << CONTA POUPANÇA" << endl
         << "3 << CONTA SALÁRIO" << endl;
    cin >> op;
    cin.ignore();
    
    switch( op ){
        case 1:
        case 2:
        case 3:
            if( conta.getTipo() != op ){
                conta.setTipo( op );
                cout << "O tipo da conta foi alterado para " << conta.tiposContas[op-1] << endl;
            }else{
                cout << "A conta já é do tipo selecionado. Transição não efetuada." << endl;
            }
            break;
        default:
            cout << "Operação inválida.";
            return false;
    }

    return true;
}

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
std::ostream& operator<< (std::ostream &o, Movimentacao const moviment){
    o << "Tipo:              " << moviment.mov.tipo << endl <<
         "Data da Transação: " << moviment.mov.dataTransacao << endl;
    return o;
}
*/