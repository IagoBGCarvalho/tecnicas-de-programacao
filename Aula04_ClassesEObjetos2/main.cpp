#include <iostream>
#include <cmath> // Biblioteca com funções matemáticas como o pow() - potenciação
using namespace std;

class Cilindro {
private:
    double raio;
    double altura;
    const double PI = acos(-1.0);
public:
    // Construtor implementado com valores default. Permite com que o objeto seja instanciado de várias maneiras
    // Cilindro c;, o C++ usará r = 1.0 e a = 1.0
    // Cilindro c(5.0);, o C++ usará r = 5.0 e a = 1.0
    // Cilindro c(5.0, 10.0);, o C++ usará r = 5.0 e a = 10.0
    Cilindro(double r = 1.0, double a = 1.0) : raio(r), altura(a) {}

    double getRaio() const;
    double getAltura() const;
    double calcularVolume() const;
    double calcularAreaLateral() const;

    // Correção 2: Adicionada a declaração do método que já estava implementado fora
    double calcularAreaSuperficieTotal() const;
};

inline double Cilindro::getRaio() const {
    return raio;
}

inline double Cilindro::getAltura() const {
    return altura;
}

// Correção 3: Implementação das fórmulas matemáticas
inline double Cilindro::calcularVolume() const {
    // Volume = PI * raio * raio * altura
    return PI * pow(raio, 2) * altura;
}

inline double Cilindro::calcularAreaLateral() const {
    // Área lateral = 2 * PI * raio * altura
    return 2 * PI * raio * altura;
}

// Implementação que já estava no código
inline double Cilindro::calcularAreaSuperficieTotal() const {
    return calcularAreaLateral() + (2 * PI * pow(raio, 2));
}

int main() {
    // Correção 1: Declaração das variáveis locais antes do cin
    double raio, altura;

    cin >> raio;
    cin >> altura;

    Cilindro cilindro(raio, altura);

    cout << cilindro.getRaio();
    cout << cilindro.getAltura();
    cout << cilindro.calcularVolume();
    cout << cilindro.calcularAreaLateral();
    cout << cilindro.calcularAreaSuperficieTotal();

    return 0;
}
