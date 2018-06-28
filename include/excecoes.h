#ifndef EXCECOES_H
#define EXCECOES_H

#include <exception>
using std::exception;
#include <stdexcept>
using std::invalid_argument;

class Excecoes : public exception {
    public:
        //Excecoes() : invalid_argument(""){}
        const char* what(){ return ""; }

};

#endif