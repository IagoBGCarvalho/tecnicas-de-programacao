#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main() {
    CodigoCliente *cliente;

    cliente = new CodigoCliente();

    int valorDigitado;

    cout << "Digite o valor para verificacao: ";
    cin >> valorDigitado;

    if(cliente->setValor(valorDigitado)){
        cout << "Deu bom! O valor armazenado foi: " << cliente->getValor() << "!!" << endl;
    } else {
        cout << "Cabouse pro betinha... Valor invalido e nao armazenado." << endl;
    }

    delete cliente;

    Estado *estado = new Estado();
    string estadoDigitado;

    cin.ignore();

    cout << "Digite o estado para verificacao: ";
    getline(cin, estadoDigitado);

    if(estado->setEstado(estadoDigitado)){
        cout << "Deu bom! O valor do estado foi armazenado: " << estado->getEstado() << "!!" << endl;
    } else {
        cout << "Cabouse pro betinha... Estado invalido e nao armazenado." << endl;
    }

    delete estado;

    return 0;
}
