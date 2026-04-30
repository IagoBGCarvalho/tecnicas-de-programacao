#include <iostream>
using namespace std;

class Poligono {
private:
    string nome;
    int numero_lados;
public:
    Poligono(string, int);
    string getNome(){ return nome;}
    int getNumeroLados(){ return numero_lados;}
};

Poligono::Poligono(string nome, int numero_lados){
     this->nome = nome;
     this->numero_lados = numero_lados;
}

class Triangulo : public Poligono {
private:
    float base;
    float altura;
public:
    Triangulo(float, float, string, int);
    float calcularArea();
};

Triangulo::Triangulo(float base, float altura, string nome, int numero_lados) : Poligono(nome, numero_lados) {
    this->base = base;
    this->altura = altura;
}

float Triangulo::calcularArea() {
    return (base * altura) / 2.0;
}

int main() {
    string nome; 
    float base, altura;   
    cin >> nome;
    cin >> base;
    cin >> altura;
    Triangulo triangulo(base, altura, nome, 3);
    cout << triangulo.getNome();
    cout << triangulo.getNumeroLados();
    cout << triangulo.calcularArea();
    return 0;
}