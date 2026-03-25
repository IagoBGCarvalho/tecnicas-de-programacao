#include <iostream>
#include <string>
#include "dominios.hpp"

using namespace std;

int main() {
    // Criar ponteiro para objeto da classe domínio
    CodigoCliente *cliente;

    // Criar objeto e armazenar o seu identificador (endereço) no ponteiro.
    cliente = new CodigoCliente();

    int valorDigitado;

    cout << "Digite o valor para verificacao: ";
    cin >> valorDigitado;

    // Armazenar valor no objeto e validar
    if(cliente->setValor(valorDigitado)){ // Uso do operador '->' pois o objeto está armazenado em um ponteiro
        cout << "Deu bom! O valor armazenado foi: " << cliente->getValor() << "!!" << endl;
    } else {
        cout << "Cabouse pro betinha... Valor invalido e nao armazenado." << endl;
    }

    // Destruir objeto apontado para liberar a memória
    delete cliente;

    // --- Classe dominio da especificação do trabalho ---
    Estado *estado = new Estado();
    string estadoDigitado;

    // Limpa o buffer de entrada (remove o 'Enter' deixado pelo cin)
    cin.ignore();

    cout << "Digite o estado para verificacao: ";
    getline(cin, estadoDigitado); // getline permite a leitura de espacos em branco

    if(estado->setEstado(estadoDigitado)){
        cout << "Deu bom! O valor do estado foi armazenado: " << estado->getEstado() << "!!" << endl;
    } else {
        cout << "Cabouse pro betinha... Estado invalido e nao armazenado." << endl;
    }

    delete estado;

    return 0;
}
