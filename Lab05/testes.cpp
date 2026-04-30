#include "testes.hpp"

void TUDominio::setUp(){
    dominio = new Dominio();
    estado = SUCESSO;
}

void TUDominio::tearDown(){
    delete dominio;
}

void TUDominio::testarCenarioValorValido(){
    try{
        dominio->setValor(VALOR_VALIDO);
        if (dominio->getValor() != VALOR_VALIDO)
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDominio::testarCenarioValorInvalido(){
    try{
        dominio->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (dominio->getValor() == VALOR_INVALIDO)
        estado = FALHA;
    }
}

int TUDominio::run(){
    setUp();
    testarCenarioValorValido();
    testarCenarioValorInvalido();
    tearDown();
    return estado;
}
