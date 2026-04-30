#include <iostream>
#include <stdexcept>
using namespace std;

class Codigo {
private:
    int valor;
public:
    // A constante precisa ser pública e estática para o TUCodigo acessá-la via Codigo::LIMITE
    static const int LIMITE = 100;

    int getValor();
    void setValor(int);
};

class TUCodigo {
public:
    bool run(int);
};

inline int Codigo::getValor(){
    return valor;
}

void Codigo::setValor(int valor){
    if (valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
    this->valor = valor;
}

bool TUCodigo::run(int valor){
    Codigo codigo;
    bool estado = true;

    // Testa o cenário de SUCESSO (valor válido)
    if(valor <= Codigo::LIMITE)
         try{
             codigo.setValor(valor);
             // Se não salvou corretamente, o teste falha
             if (codigo.getValor() != valor)
                 estado = false;
         }
         catch(invalid_argument &excecao){
             // Se lançou exceção com valor válido, o teste falha
             estado = false;
         }
    // Testa o cenário de FALHA (valor inválido)
    else
         try{
             codigo.setValor(valor);
             // Se salvou um valor inválido e não deu erro, o teste falha
             estado = false;
         }
         catch(invalid_argument &excecao){
             // Verifica se o valor original da classe se manteve inalterado (como deveria)
             if (codigo.getValor() == valor)
                 estado = false;
         }
    return estado;
}

int main(){
     TUCodigo teste;
     int dado;
    cin >> dado;
    switch(teste.run(dado)){
        case true : cout << "SUCESSO" << endl;
                   break;
        case false: cout << "FALHA" << endl;
                    break;
    }
     return 0;
}
