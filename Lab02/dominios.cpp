#include <string>
#include "dominios.hpp"

// As constantes de tipos complexos precisam ser inicializadas em arquivos .cpp!!
const string Estado::AFAZER = "A FAZER";
const string Estado::FAZENDO = "FAZENDO";
const string Estado::FEITO = "FEITO";

bool CodigoCliente::validar(int valor){
    if(valor > LIMITE)
        return false;
    return true;
}

bool CodigoCliente::setValor(int valor){
    if(!validar(valor))
        return false;

    this->valor = valor;
    return true;
}

bool Estado::validar(string estadoFornecido){
    if(estadoFornecido == AFAZER || estadoFornecido == FAZENDO || estadoFornecido == FEITO)
        return true;
    return false;
}

bool Estado::setEstado(string estadoFornecido){
    if(!validar(estadoFornecido))
       return false;

    this->estadoAtual = estadoFornecido;
    return true;
}
