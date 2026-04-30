#include <iostream>
#include <stdexcept> 
using namespace std;

class Codigo {
private:
    int valor;
    void validar(int);
public:
    void set(int);
    int get();
};

class Preco {
private:
    int valor;
    void validar(int);
public:
    void set(int);
    int get();
};

class Pedido {
private:
    Codigo codigo;
    Preco preco;
public:
    void setCodigo(Codigo);
    void setPreco(Preco);
    Codigo getCodigo();
    Preco getPreco();
};

void Codigo::validar(int valorDado) {
    if (valorDado > 100) {
        throw invalid_argument("Argumento invalido");
    }
}

void Codigo::set(int valorDado) {
    validar(valorDado);
    this->valor = valorDado;
}

int Codigo::get() {
    return this->valor;
}

void Preco::validar(int valorDado) {
    if (valorDado > 200) {
        throw invalid_argument("Argumento invalido");
    }
}

void Preco::set(int valorDado) {
    validar(valorDado);
    this->valor = valorDado;
}

int Preco::get() {
    return this->valor;
}

void Pedido::setCodigo(Codigo codigoDado) {
    this->codigo = codigoDado;
}

void Pedido::setPreco(Preco precoDado) {
    this->preco = precoDado;
}

Codigo Pedido::getCodigo() {
    return this->codigo;
}

Preco Pedido::getPreco() {
    return this->preco;
}

int main(){
    int dadoA, dadoB;
    cin >> dadoA;
    cin >> dadoB;

    Codigo codigo;
    Preco preco;

    try{
        codigo.set(dadoA);
        preco.set(dadoB);
    }
    catch(invalid_argument &excecao){
        cout << "FALHA";
        return 0;
    }

    Pedido pedido;
    pedido.setCodigo(codigo);
    pedido.setPreco(preco);

    cout << pedido.getCodigo().get();
    cout << pedido.getPreco().get();

    return 0;
}
