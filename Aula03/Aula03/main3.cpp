#include <iostream>

using namespace std;

class Nome {

     private:
         string valor;
     public:
          void set(string);
          string get();
};

class Matricula {

     private:
         int valor;
     public:
          void set(int);
          int get();
};

class Estudante {

     private:
         Nome nome;
         Matricula matricula;
     public:
          Estudante(Nome&, Matricula&);
          Nome getNome();
          Matricula getMatricula();
};

void Nome::set(string valorDado){
    this->valor = valorDado;
}

string Nome::get() {
    return this->valor;
}

void Matricula::set(int valorDado){
    this->valor = valorDado;
}

int Matricula::get() {
    return this->valor;
}

Estudante::Estudante(Nome& nomeDado, Matricula& matriculaDada) {
    this->nome = nomeDado;
    this->matricula = matriculaDada;
}

Nome Estudante::getNome() {
    return this->nome;
}

Matricula Estudante::getMatricula() {
    return this->matricula;
}

//int main(){
//
//     string dadoA;
//
//     int dadoB;
//
//     cin >> dadoA;
//
//     cin >> dadoB;
//
//     Nome nome;
//
//     Matricula matricula;
//
//     nome.set(dadoA);
//
//     matricula.set(dadoB);
//
//     Estudante estudante(nome, matricula);
//
//     cout << estudante.getNome().get();
//
//     cout << estudante.getMatricula().get();
//
//     return 0;
//
//}
