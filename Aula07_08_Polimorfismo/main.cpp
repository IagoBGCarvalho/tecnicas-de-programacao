#include <iostream>
using namespace std;

class Poligono {
protected:
    // Atributo protegido para que as filhas possam acessar diretamente
    int numero_lados;
public:
    int getNumeroLados() const;
    // O '= 0' torna este método "Virtual Puro", fazendo de Poligono uma classe abstrata
    virtual float calcularArea() const = 0;
};

inline int Poligono::getNumeroLados() const {
    return numero_lados;
}

class Quadrado : public Poligono {
private:
    float lado;
public:
    Quadrado(float);
    float calcularArea() const;
};

inline Quadrado::Quadrado(float lado) {
    this->numero_lados = 4;
    this->lado = lado;
}

inline float Quadrado::calcularArea() const {
    // Área do Quadrado = lado x lado
    return lado * lado;
}

class Pentagono : public Poligono {
private:
    float lado;
    float apotema;
public:
    Pentagono(float, float);
    float calcularArea() const;
};

inline Pentagono::Pentagono(float lado, float apotema) {
    this->numero_lados = 5;
    this->lado = lado;
    this->apotema = apotema;
}

inline float Pentagono::calcularArea() const {
    // Área do Pentágono Regular = (5 * lado * apotema) / 2
    return (5 * lado * apotema) / 2.0f;
}

int main() {
    float lado, apotema;

    cin >> lado;
    cin >> apotema;

    Poligono* ptr; // Ponteiro genérico da superclasse
    ptr = new Quadrado(lado); // Aponta o ponteiro para um objeto da classe Quadrado

    cout << ptr->getNumeroLados();
    cout << ptr->calcularArea(); // O C++ acessa a VTable e roda o código do Quadrado

    ptr = new Pentagono(lado, apotema); // Agora aponta para um objeto da classe Pentagono

    cout << ptr->getNumeroLados();
    cout << ptr->calcularArea(); // O C++ acessa a VTable e roda o código do Pentágono
    return 0;
}
