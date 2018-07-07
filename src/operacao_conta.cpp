#include "operacao_conta.h"

//namespace cbancaria{

template<typename TContainer>
void print_elements(const TContainer& collection, const char* label="",
const char separator=' '){
    std::cout << label;
    for( auto it = collection.begin(); it != collection.end(); it++  ){
        std::cout << (*it) << separator;
    }
    std::cout << std::endl;
}

bool OperacaoConta::leBancoDeDados( string nomeArquivo ){
    std::ifstream bancoDados( nomeArquivo );
    const char separador = ';';
    string str, agencia, conta, titular, saldo, tipoConta, limite, tipoMov, origem, valor, dia, mes, ano, horas, minutos, segundos, diasemana;

    vector<std::shared_ptr<Conta>> contas;

    try{
        if( bancoDados.is_open() ){
            while( !bancoDados.eof() ){
                while( str != "->" ){
                    std::getline(cin, str, separador);
                    agencia = str;
                    std::getline(cin, str, separador);
                    conta = str;
                    std::getline(cin, str, separador);
                    tipoConta = str;
                    std::getline(cin, str, separador);
                    titular = str;
                    std::getline(cin, str, separador);
                    saldo = str;
                    std::getline(cin, str, separador);
                    limite = str;
                    Conta * c = new Conta( agencia, std::stoi(tipoConta), titular, std::stod(limite) );
                    contas.push_back(std::make_shared<Conta>(*c));
                }
            }

            return true;


        }else{
            throw Excecoes();
            return false;
        }
    }catch( Excecoes &ex ){ return false; }
}

bool OperacaoConta::armazenarContas( vector<shared_ptr<Conta>> c ){
    std::ofstream arqCadastro("Base de contas.txt", std::ios::app);
    const char separador = ';';
    try{
        if( arqCadastro.is_open() ){
            for(auto it = c.begin(); it != c.end(); it++){
                arqCadastro << (*it)->getAgencia() << separador;
                arqCadastro << (*it)->getConta() << separador;
                arqCadastro << std::to_string( (*it)->getTipo() ) << separador;
                arqCadastro << (*it)->getTitular() << separador;
                arqCadastro << std::to_string( (*it)->getSaldo() ) << separador;
                arqCadastro << std::to_string( (*it)->getLimite() ) << separador;
                arqCadastro << TAGMOV;
                for( int i = 0; i < (*it)->getMovimentacao().getTamanho(); i++){
                    arqCadastro << (*it)->getMovimentacao().getElemento(i).getTipo() << separador;
                    arqCadastro << (*it)->getMovimentacao().getElemento(i).getOrigem() << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getValor() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getDia() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getMes() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getAno() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getHoras() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getMinutos() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getSegundos() ) << separador;
                    arqCadastro << std::to_string( (*it)->getMovimentacao().getElemento(i).getData()->getDiaSemana() ) << separador;
                }
                
                arqCadastro << TAGCONTA << endl;
            }

            return true;        
        }else{
            throw Excecoes();
            return false;
        }
    }catch( Excecoes &ex){
        std::cerr << ex.what() << std::endl;
        return false;
    }catch( ... ){
        std::cerr << "Erro desconhecido para a operacao de SAQUE!" << std::endl;
        return false;
    }
}

shared_ptr<Conta> OperacaoConta::CriarContas( string agencia, string titular, int tipoConta, double limite ){
    Conta c( agencia, tipoConta, titular, limite );
    return std::make_shared<Conta> ( c );
}

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
        if( contaA.getSaldo() < valor || contaB.getSaldo() + valor > contaB.getLimite() ) throw Excecoes();
        else{
            //Bloco Conta A
            Movimentacao mov;
            mov.setTipo( "TRANSFERÊNCIA" );
            mov.setOrigem( contaA.getTitular() );
            mov.setValor( valor );
            
            contaA.setSaldo( contaA.getSaldo() - valor );

            Data d;
            mov.setData( std::make_shared<Data> ( d ) );

            contaA.adicionarMovimentacao( mov );

            //Bloco conta B            
            contaB.setSaldo( contaB.getSaldo() + valor );

            contaB.adicionarMovimentacao( mov );

            return true;
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

void OperacaoConta::exibeSaldo( Conta &conta ){
    Data d;
    int op;
    //int tipo;
    cout << "1 << MOSTRA EM TELA" << endl
         << "2 << IMPRIME EM ARQUIVO" << endl;
    cin >> op;
    cin.ignore();
    if(op == 1){
        cout << "########## SALDO ##########" << endl
                << "Agência: " << conta.getAgencia() << endl
                << "Conta: " << conta.getConta() << endl
                << "Titular: " << conta.getTitular() << endl;
                d.imprimeData();
        cout << "Saldo Atual: " << conta.getSaldo() << endl
                << "########## Fim do Saldo ##########" << endl;
    }else{
        //std::ofstream arqSaida("Saldo_"+conta.getTitular()+".txt", std::ios::trunc);
        //arqSaida.open();
        std::ofstream arqSaida("teste.txt");
        //arqSaida.open();

        if(arqSaida.is_open()){
            cout << "Arquivo criado!" << endl;

            arqSaida << "########## SALDO ##########" << endl
                    << "Agência: " << conta.getAgencia() << endl
                    << "Conta: " << conta.getConta() << endl
                    << "Titular: " << conta.getTitular() << endl
                    << d << endl
                    << "Saldo Atual: " << conta.getSaldo() << endl
                    << "########## Fim do Saldo ##########" << endl;

            arqSaida.close();
        }else{
            cout << "Erro ao tentar abrir o arquivo" << endl;
        }

    }
}

void OperacaoConta::exibeExtrato( Conta &conta, int periodo = 5 ){
    Data d;
    //(diaAtual - periodo)mod30
    int dataPeriodo = ( d.getDia() - periodo ) % 30;
    Movimentacao mov;

    cout << "########## EXTRATO ##########" << endl
         << "Agência: " << conta.getAgencia() << endl
         << "Conta: " << conta.getConta() << endl
         << "Titular: " << conta.getTitular() << endl;
         d.imprimeData();
    cout << "Saldo Atual: " << conta.getSaldo() << endl << endl;    
    
    for(int i = 0; i < conta.getMovimentacao().getTamanho(); i++){
        mov = conta.getMovimentacao().getElemento(i);
        if( mov.getData()->getDia() >= dataPeriodo ){
            cout << mov << endl;
        }
    }
    cout << "########## Fim do Extrato ##########" << endl;
}
/*
std::ostream& operator<< (std::ostream &o, Movimentacao const moviment){
    o << "Tipo:              " << moviment.mov.tipo << endl <<
         "Data da Transação: " << moviment.mov.dataTransacao << endl;
    return o;
}
*/

//}