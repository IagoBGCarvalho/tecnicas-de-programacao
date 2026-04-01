#include <iostream>

using namespace std;

class Estudante {

     private:
         string nome;
         static int contador;
     public:
          Estudante(string nomeDado){
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

int Estudante::contador = 0;

//int main(){
//
//     string nomeA, nomeB;
//
//     cin >> nomeA;
//
//     cin >> nomeB;
//
//     cout << Estudante::getContador();
//
//     Estudante estudanteA(nomeA);
//
//     cout << Estudante::getContador();
//
//     cout << estudanteA.getNome();
//
//     Estudante estudanteB(nomeB);
//
//     cout << Estudante::getContador();
//
//     cout << estudanteB.getNome();
//
//     return 0;
//
//}
