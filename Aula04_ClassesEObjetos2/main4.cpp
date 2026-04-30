#include <iostream>
#include <cmath>
using namespace std;

class Circulo {
private:
    // 1. Declaração do atributo que estava faltando
    double raio;
    const double PI = acos(-1.0);

public:
    // 2. Declarações dos métodos (O Contrato)
    void setRaio(double);
    double getRaio();
    double calcularArea();
    double calcularPerimetro();
    double calcularDiametro();
};

void Circulo::setRaio(double r) {
    raio = (r >= 0) ? r : 0;
}

double Circulo::getRaio() {
    return raio;
}

double Circulo::calcularArea() {
    return PI * pow(raio, 2);
}

double Circulo::calcularPerimetro() {
    return 2 * PI * raio;
}

double Circulo::calcularDiametro() {
    return 2 * raio;
}

int main() {
    // 3. Declaração do objeto e da variável local
    Circulo a;
    double raio;

    cin >> raio;
    a.setRaio(raio);

    cout << a.getRaio();
    cout << a.calcularDiametro();
    cout << a.calcularArea();
    cout << a.calcularPerimetro();

    return 0;
}
