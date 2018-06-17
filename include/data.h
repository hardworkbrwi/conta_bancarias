#ifndef DATA_H
#define DATA_H

//sessão de inclusão de libs
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

//Classe Data
//Define os atributos e métodos de uma Data
class Data{
    private:
        int m_dia;
        int m_mes;
        int m_ano;

    public:
        //Construtor padrão da classe Data
        Data();

        //Destrutor padrão da classe Data
        ~Data();

        //Sobrecarga do operador de entrada padrão
        //Redefine o istream para receber os dados de data na entrada padrão
        friend std::istream& operator>> (std::istream &i, Data &d);
        //Sobrecarga do operador de saída padrão
        //Redefine o ostream para mostrar os dados de data na saída padrão
        friend std::ostream& operator<< (std::ostream &o, Data d);
        
        //Retorna a data completa em formato string
        static std::string obterDataNumerica(void); 
        //Retorna a data resumida em formato string
        static std::string obterDataNumericaAnoResumido(void);

        //Retorna a data pro extenso em formato string
        std::string DataPorExtenso();        

        //Sessão de Encapsulamento
        //Coleção de métodos get e set da classe Funcionario

        //Encapsulamento do atributo m_dia
        int getDia();
        void setDia(int dia);
        //Encapsulamento do atributo m_mes
        int getMes();
        void setMes(int mes);
        //Encapsulamento do atributo m_ano
        int getAno();
        void setAno(int ano);
};
#endif