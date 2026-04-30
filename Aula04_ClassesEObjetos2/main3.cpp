#include <iostream>
using namespace std;

class Rectangulo {
private:
    double largura;
    double altura;
public:
    // Correção 2: Declarando os setters que já estavam implementados fora
    void setLargura(double);
    void setAltura(double);

    double getLargura() const;
    double getAltura() const;
    double calcularArea() const;
    double calcularPerimetro() const;
};

inline void Rectangulo::setLargura(double l){
    largura = (l > 0) ? l : 1.0;
}

inline void Rectangulo::setAltura(double a){
    this->altura = (a > 0) ? a : 1.0;
}

// Correção 3: Implementando os getters
inline double Rectangulo::getLargura() const {
    return largura;
}

inline double Rectangulo::getAltura() const {
    return altura;
}

// Correção 3: Implementando os cálculos matemáticos
inline double Rectangulo::calcularArea() const {
    // Área = largura * altura
    return largura * altura;
}

inline double Rectangulo::calcularPerimetro() const {
    // Perímetro = 2 * (largura + altura)
    return 2 * (largura + altura);
}

int main() {
    // Correção 1: Declarando (instanciando) o objeto 'a' da classe Rectangulo
    Rectangulo a;

    double largura, altura;
    cin >> largura;
    cin >> altura;

    a.setLargura(largura);
    a.setAltura(altura);

    cout << a.getLargura();
    cout << a.getAltura();
    cout << a.calcularArea();
    cout << a.calcularPerimetro();

    return 0;
}
