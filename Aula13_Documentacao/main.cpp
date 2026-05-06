#include <iostream>
#include <stdexcept>
using namespace std;

class Calculadora {
private:
    double memoria;
public:
    void armazenar(double);
    double ler() const;
    void somar(double);
    void subtrair(double);
    void multiplicar(double);
    void dividir(double);
};

inline void Calculadora::armazenar(double valor){
    memoria = valor;
}

inline double Calculadora::ler() const {
    return memoria;
}

inline void Calculadora::somar(double valor){
    memoria += valor;
}

inline void Calculadora::subtrair(double valor){
    memoria -= valor;
}

inline void Calculadora::multiplicar(double valor){
    memoria *= valor;
}

inline void Calculadora::dividir(double valor){
    if (valor == 0) {
        throw std::invalid_argument("Divisao por zero");
    }
    memoria /= valor;
}

class TesteUnitarioCalculadora {
private:
    Calculadora *unidade;
    double *valores;
    bool resultado;
public:
    void inicializar(double*);
    void encerrar();
    void testarSomar();
    void testarSubtrair();
    void testarMultiplicar();
    void testarDividir();
    bool executar(double*);
};

void TesteUnitarioCalculadora::inicializar(double *v) {
    unidade = new Calculadora();
    valores = v;
    resultado = true;
}

void TesteUnitarioCalculadora::encerrar(){
    delete unidade;
}

void TesteUnitarioCalculadora::testarSomar() {
    unidade->armazenar(valores[0]);
    unidade->somar(valores[1]);
    if(unidade->ler() != valores[3]){
       resultado = false;
    }
}

void TesteUnitarioCalculadora::testarSubtrair() {
    unidade->armazenar(valores[0]);
    unidade->subtrair(valores[1]);
    if(unidade->ler() != valores[4]){
       resultado = false;
    }
}

void TesteUnitarioCalculadora::testarMultiplicar() {
    unidade->armazenar(valores[0]);
    unidade->multiplicar(valores[1]);
    if(unidade->ler() != valores[5]){
       resultado = false;
    }
}

void TesteUnitarioCalculadora::testarDividir() {
    // Caminho de sucesso esperado
    try {
        unidade->armazenar(valores[0]);
        unidade->dividir(valores[1]);
        if(unidade->ler() != valores[6]){
            resultado = false;
        }
    }
    catch (const std::invalid_argument& e) {
        resultado = false;
    }

    // Caminho de falha esperado (Divisão por zero)
    try {
        unidade->armazenar(valores[0]);
        unidade->dividir(valores[2]);
        resultado = false; // Se não lançar a exceção, o teste falha
    }
    catch (const std::invalid_argument& e) {
        // Se capturar a exceção, o comportamento está correto e o teste passa
    }
}

bool TesteUnitarioCalculadora::executar(double *v) {
    inicializar(v);
    testarSomar();
    testarSubtrair();
    testarMultiplicar();
    testarDividir();
    encerrar();
    return resultado;
}

int main() {
    double valores[7];
    cin >> valores[0];
    cin >> valores[1];
    cin >> valores[2];
    cin >> valores[3];
    cin >> valores[4];
    cin >> valores[5];
    cin >> valores[6];

    Calculadora calculadora;

    calculadora.armazenar(valores[0]);
    calculadora.somar(valores[1]);
    cout << calculadora.ler();

    calculadora.armazenar(valores[0]);
    calculadora.subtrair(valores[1]);
    cout << calculadora.ler();

    calculadora.armazenar(valores[0]);
    calculadora.multiplicar(valores[1]);
    cout << calculadora.ler();

    calculadora.armazenar(valores[0]);
    calculadora.dividir(valores[1]);
    cout << calculadora.ler();

    TesteUnitarioCalculadora teste;
    if(teste.executar(valores))
        cout << "Sucesso";
    else
        cout << "Falha";

    return 0;
}
