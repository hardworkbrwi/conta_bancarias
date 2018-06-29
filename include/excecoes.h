#ifndef EXCECOES_H
#define EXCECOES_H

#include <exception>
using std::exception;
#include <stdexcept>
using std::invalid_argument;

class Excecoes : public exception {
    private:
        std::string msgErro;
    public:
        //Excecoes();
        //invalid_argument( std::string msgErro );
        const char* what(){ return "ERRO NO PROCEDIMENTO EFETUADO NA CONTA"; }

        void lancaMsg( std::string msgErro ){
            this->msgErro = msgErro;
        }

};



#endif