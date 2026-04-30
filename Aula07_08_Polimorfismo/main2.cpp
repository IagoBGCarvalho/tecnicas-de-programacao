#include <iostream>
using namespace std;

class Poligono {
private:
    string cor;
public:
    Poligono(string);
    virtual ~Poligono(){}
    string getCor();
    virtual float calcularPerimetro() = 0;
};

inline Poligono::Poligono(string cor) {
    this->cor = cor;
}

inline string Poligono::getCor() {
    return cor;
}

class Paralelograma : public Poligono {
private:
    float a;
    float b;
public:
    Paralelograma(float, float, string);
    float calcularPerimetro();
};

// O construtor repassa a 'cor' para a classe pai (Poligono)
inline Paralelograma::Paralelograma(float a, float b, string cor) : Poligono(cor) {
    this->a = a;
    this->b = b;
}

inline float Paralelograma::calcularPerimetro() {
    // Perímetro = 2 x (a + b)
    return 2 * (a + b);
}

class Trapezio : public Poligono {
private:
    float B;
    float b;
    float L1;
    float L2;
public:
    Trapezio(float, float, float, float, string);
    float calcularPerimetro();
};

// O construtor repassa a 'cor' para a classe pai (Poligono)
inline Trapezio::Trapezio(float B, float b, float L1, float L2, string cor) : Poligono(cor) {
    this->B = B;
    this->b = b;
    this->L1 = L1;
    this->L2 = L2;
}

inline float Trapezio::calcularPerimetro() {
    // Perímetro = B + b + L1 + L2
    return B + b + L1 + L2;
}

int main() {
    Poligono*ptr;
    string cor;

    float a, b, B, L1, L2;

    cin >> cor;
    cin >> a;
    cin >> b;
    cin >> B;
    cin >> L1;
    cin >> L2;

    ptr = new Paralelograma(a,b, cor);

    cout << ptr->getCor();
    cout << ptr->calcularPerimetro();

    delete ptr; // Liberando a memória do ponteiro

    ptr = new Trapezio(B, b, L1, L2, cor);
    
    cout << ptr->getCor();
    cout << ptr->calcularPerimetro();
    delete ptr;
    return 0;
}
