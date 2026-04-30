#include <iostream>
using namespace std;

class Poligono {
protected:
    int numero_lados;
public:
    int getNumeroLados() const;
};

inline int Poligono::getNumeroLados() const {
    return numero_lados;
}
// A sintaxe ": public Poligono" estabelece a herança. Retangulo herda de Poligono
class Retangulo : public Poligono {
private:
    float base;
    float altura;
public:
    Retangulo(float, float);
    float calcularArea() const;
    float calcularPerimetro() const;
};

inline Retangulo::Retangulo(float b, float a) {
    // Acessa a variável 'numero_lados' diretamente pois ela é 'protected' na classe pai
    this->numero_lados = 4;
    this->base = b;
    this->altura = a;
}

inline float Retangulo::calcularArea() const {
    // Área = base * altura
    return base * altura;
}

inline float Retangulo::calcularPerimetro() const {
    // Perímetro = 2 * (base + altura)
    return 2 * (base + altura);
}

int main() {
    float base, altura;
    cin >> base;
    cin >> altura;
    Retangulo retangulo(base, altura);
    cout << retangulo.getNumeroLados();
    cout << retangulo.calcularArea();
    cout << retangulo.calcularPerimetro();
    return 0;
}
