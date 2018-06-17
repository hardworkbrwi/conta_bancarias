//sessão de inclusão de libs
#include "data.h"

//Construtor padrão da classe Data
Data::Data(){}
//Destrutor padrão da classe Data
Data::~Data(){}

//Sobrecarga do operador de entrada padrão
//Redefine o istream para receber os dados de data na entrada padrão
std::istream& operator>> (std::istream &i, Data &d){
    do{
        std::cout << "Entre com o dia (1 - 31): ";
        i >> d.m_dia;
        i.ignore();
        if( d.m_dia < 1 || d.m_dia > 31 )
            std::cout << "DIA INVÁLIDO!" << std::endl << "- Digite novamente. " << std::endl;
    }while( d.m_dia < 1 || d.m_dia > 31 );

    do{
        std::cout << "Entre com o mês (1 - 12): ";
        i >> d.m_mes;
        i.ignore();
        if( d.m_mes < 1 || d.m_mes > 12 )
            std::cout << "MÊS INVÁLIDO!" << std::endl << "- Digite novamente. " << std::endl;
    }while( d.m_mes < 1 || d.m_mes > 12 );

    do{
        std::cout << "Entre com o ano a partir de 4 digitos: ";
        i >> d.m_ano;
        i.ignore();
        if( d.m_ano < 1918 )
            std::cout << "ANO INVÁLIDO!" << std::endl << "- Digite novamente. " << std::endl;
    }while( d.m_ano < 1918 );

    return i;
}
//Sobrecarga do operador de saída padrão
//Redefine o ostream para mostrar os dados de data na saída padrão
std::ostream& operator<< (std::ostream &o, Data d){
    o << d.DataPorExtenso();

    return o;
}

//Retorna a data completa em formato string
std::string Data::obterDataNumerica(void) {
 
    time_t dataAdmissao;
    struct tm *dataAdmissaoInfo;
    char buffer[20];
 
    time(&dataAdmissao);
    dataAdmissaoInfo = localtime(&dataAdmissao);
 
    strftime(buffer, 20, "%d/%m/%Y", dataAdmissaoInfo);
 
    return std::string(buffer);
}

//Retorna a data resumida em formato string
std::string Data::obterDataNumericaAnoResumido(void) {
 
    time_t dataAdmissao;
    struct tm *dataAdmissaoInfo;
    char buffer[20];
 
    time(&dataAdmissao);
    dataAdmissaoInfo = localtime(&dataAdmissao);
 
    strftime(buffer, 20, "%d/%m/%y", dataAdmissaoInfo);
 
    return std::string(buffer);
}

//Retorna a data pro extenso em formato string
std::string Data::DataPorExtenso() {
    time_t dataAdmissao; //Instancia objeto time_t dataAdmissao
    struct tm *dataAdmissaoInfo; //Define um struct time dataAdmissaoInfo
    char buffer[40]; //Define char de caracteres buffer com tamanho 40
    std::string data; //Define a string data
 
    //Inicializa os atibutos do struct dataAdmissaoInfo com a conversão do objeto time_t dataAdmissao
    //inicializa ano, mês, dia, hora, minuto e segundo
    dataAdmissaoInfo = localtime(&dataAdmissao);
    dataAdmissaoInfo->tm_year = m_ano - 1900; //diferença da data inicial do sistema ano - 1900
    dataAdmissaoInfo->tm_mon = m_mes - 1; //atribuição do mês no intervalo de 0 a 11
    dataAdmissaoInfo->tm_mday = m_dia;
    dataAdmissaoInfo->tm_hour = 0;
    dataAdmissaoInfo->tm_min = 0;
    dataAdmissaoInfo->tm_sec = 0;

    //Atribui o atributo dia da struct dataAdmissaoInfo ao atributo buffer
    strftime(buffer, 40, "%d", dataAdmissaoInfo);
    //Adiciona o conteúdo de buffer a variável string data
    data = buffer;
 
    data += " de ";
    
    //Substitui o valor de mês do struct pelo mês por extenso adicionando ao buffer
    //e adicinando a variável string data
    strftime(buffer, 40, "%m", dataAdmissaoInfo);
    if (strcmp(buffer, "01") == 0) {
        data += "janeiro de ";
    } else if (strcmp(buffer, "02") == 0) {
        data += "fevereiro de ";
    } else if (strcmp(buffer, "03") == 0) {
        data += "março de ";
    } else if (strcmp(buffer, "04") == 0) {
        data += "abril de ";
    } else if (strcmp(buffer, "05") == 0) {
        data += "maio de ";
    } else if (strcmp(buffer, "06") == 0) {
        data += "junho de ";
    } else if (strcmp(buffer, "07") == 0) {
        data += "julho de ";
    } else if (strcmp(buffer, "08") == 0) {
        data += "agosto de ";
    } else if (strcmp(buffer, "09") == 0) {
        data += "setembro de ";
    } else if (strcmp(buffer, "10") == 0) {
        data += "outubro de ";
    } else if (strcmp(buffer, "11") == 0) {
        data += "novembro de ";
    } else if (strcmp(buffer, "12") == 0) {
        data += "dezembro de ";
    }
    
    //Atribui o atributo ano da struct dataAdmissaoInfo ao atributo buffer
    //e o adciona a variável string data
    strftime(buffer, 40, "%Y", dataAdmissaoInfo);
    data += buffer;
    
    //Retorna a data por extenso
    return data;
}

//Sessão de Encapsulamento
//Coleção de métodos get e set da classe Funcionario

//Encapsulamento do atributo m_dia
int Data::getDia(){
    return m_dia;
}
void Data::setDia(int dia){
    m_dia = dia;
}

//Encapsulamento do atributo m_mes
int Data::getMes(){
    return m_mes;
}
void Data::setMes(int mes){
    m_mes = mes;
}

//Encapsulamento do atributo m_ano
int Data::getAno(){
    return m_ano;
}
void Data::setAno(int ano){
    m_ano = ano;
}