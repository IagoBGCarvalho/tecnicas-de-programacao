#include <iostream>
using namespace std;

class Ponto {
private:
    double x, y;
public:
    Ponto(double x, double y) : x(x), y(y){}
    bool operator == (const Ponto&) const;
    friend ostream& operator<<(ostream&, const Ponto&);
};

// 1. Implementação faltante: Comparação entre dois Pontos
inline bool Ponto::operator == (const Ponto& outro) const {
    return (this->x == outro.x && this->y == outro.y);
}

ostream& operator<<(std::ostream& os, const Ponto& ponto) {
    os << ponto.x;
    os << ponto.y;
    return os;
}

class Linha {
private:
    Ponto inicio, fim;
public:
    Linha(Ponto inicio, Ponto fim) : inicio(inicio), fim(fim){}
    bool operator == (const Linha&) const;
    friend ostream& operator<<(ostream&, const Linha&);
    Ponto getInicio() const;
    Ponto getFim() const;
};

// 2. Implementação faltante: Comparação entre duas Linhas
inline bool Linha::operator == (const Linha& outra) const {
    // Como o C++ já sabe comparar Pontos, pode-se usar o '==' diretamente aqui
    return (this->inicio == outra.inicio && this->fim == outra.fim);
}

inline Ponto Linha::getInicio() const{
    return inicio;
}

inline Ponto Linha::getFim() const{
    return fim;
}

ostream& operator<<(std::ostream& os, const Linha& linha) {
    os << linha.inicio;
    os << linha.fim;
    return os;
}

int main() {
    double x0, y0, x1, y1;
    cin >> x0;
    cin >> y0;
    cin >> x1;
    cin >> y1;
    Linha linhaA({x0,y0},{x1,y1});

    cin >> x0;
    cin >> y0;
    cin >> x1;
    cin >> y1;
    Linha linhaB({x0,y0},{x1,y1});

    cout << linhaA.getInicio() << linhaA.getFim() ;
    cout << linhaB.getInicio() << linhaB.getFim() ;

    if (linhaA == linhaB){
        cout << "iguais" << endl;
    }
    else {
        cout << "diferentes" << endl;
    }
    return 0;
}
