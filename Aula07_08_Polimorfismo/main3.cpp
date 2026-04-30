#include <iostream>
using namespace std;

class Ponto {
private:
    double x, y;
public:
    Ponto(double x, double y) : x(x), y(y){}
    bool operator == (const Ponto&) const;
    double getX() const;
    double getY() const;
};

inline double Ponto::getX() const {
    return this->x;
}

inline double Ponto::getY() const {
    return this->y;
}

// Implementação da sobrecarga do operador ==
inline bool Ponto::operator == (const Ponto& outroPonto) const {
    // Compara o X e o Y da instância atual com o X e Y do ponto recebido
    return (this->x == outroPonto.x && this->y == outroPonto.y);
}

// Sobrecarga do operador << 
ostream& operator<<(std::ostream& os, const Ponto& ponto) {
    os << ponto.getX() ;
    os << ponto.getY() ;
    return os;
}

int main() {
    double x, y;
    cin >> x;
    cin >> y;
    Ponto pontoA(x,y);
    cin >> x;
    cin >> y;
    Ponto pontoB(x,y);
    cout << pontoA;
    cout << pontoB;
    if (pontoA == pontoB){
        cout << "iguais" ;
    }
    else {
        cout << "diferentes" ;
    }
    return 0;
}
