#include "dominios.hpp"

void Dominio::validar(Tipo valor){
    // Implementar código de validação.
    // Lançar exceção quando o valor for inválido.
    try{



    }
    catch(invalid_argument &excecao){
        throw invalid_argument("Argumento invalido.");
    }
}

void Dominio::setValor(Tipo valor) {
    validar(valor);
    this->valor = valor;
}


try{
        dominio->setValor(VALOR_VALIDO);
        if (dominio->getValor() != VALOR_VALIDO)
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
