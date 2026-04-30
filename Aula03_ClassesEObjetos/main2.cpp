#include <iostream>

using namespace std;

class Estudante {
    private:
        string nome;
        static int contador; // static define que um membro (variável ou função) pertence à classe em si, e não a instâncias (objetos) específicas, mantendo seu valor ou escopo durante toda a execução do programa.
    public:
        Estudante(string nomeDado){
            // Método construtor da classe que é chamado toda vez que a classe é instanciada.
            // Está atribuindo o valor do nome do objeto e aumentando o contador da classe
            nome = nomeDado;
            contador = contador + 1;
        };

        static int getContador(){
            return contador;
        };

        string getNome();
};

string Estudante::getNome(){
    return nome;
}

int Estudante::contador = 0; // Atribui ao contador o valor de 0

int main(){
    string nomeA, nomeB;

    cin >> nomeA;
    cin >> nomeB;

    cout << Estudante::getContador();

    Estudante estudanteA(nomeA); // Instanciando um Estudante e já atribuindo valores as suas propriedades utilizando do método construtor da classe

    cout << Estudante::getContador();
    cout << estudanteA.getNome();

    Estudante estudanteB(nomeB);

    cout << Estudante::getContador();
    cout << estudanteB.getNome();

    return 0;
}
