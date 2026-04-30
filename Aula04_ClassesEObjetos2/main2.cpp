#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Cubo {
private:
    double aresta;
public:
    void setAresta(double);
    double getAresta() const;
    double calcularVolume() const;
    double calcularAreaSuperficie() const;

    // Adicionando as declarações dos métodos que já estavam implementados
    double calcularAreaSuperficieLateral() const;
    double calcularDiagonal() const;
};

void Cubo::setAresta(double a) {
    if (a <= 0) {
        aresta = 1.0;
    } else {
        aresta = a;
    }
}

// Implementando o método Get que estava faltando
double Cubo::getAresta() const {
    return aresta;
}

// Implementando o Cálculo do Volume (aresta * aresta * aresta)
double Cubo::calcularVolume() const {
    return pow(aresta, 3);
}

// Implementando a Área da Superfície (6 * aresta * aresta)
double Cubo::calcularAreaSuperficie() const {
    return 6 * pow(aresta, 2);
}

double Cubo::calcularAreaSuperficieLateral() const {
    return 4 * pow(aresta, 2);
}

double Cubo::calcularDiagonal() const {
    return aresta * sqrt(3.0);
}

int main() {
    Cubo a;

    // 5. Declarando a variável local antes de usá-la no cin
    double aresta;

    cin >> aresta;
    a.setAresta(aresta);

    cout << a.getAresta();
    cout << a.calcularVolume();
    cout << a.calcularAreaSuperficie();
    cout << a.calcularAreaSuperficieLateral();
    cout << a.calcularDiagonal();

    return 0;
}
