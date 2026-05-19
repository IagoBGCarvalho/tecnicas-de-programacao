#include <iostream>
using namespace std;

/**
 * @class Ponto
 * @brief Classe que representa uma coordenada bidimensional como um Objeto Valor.
 */
class Ponto {
private:
    /** @brief Coordenada no eixo das abcissas. */
    double x;
    /** @brief Coordenada no eixo das ordenadas. */
    double y;
public:
    /**
     * @brief Construtor da classe Ponto.
     * @param x Valor da coordenada x.
     * @param y Valor da coordenada y.
     */
    Ponto(double x, double y) : x(x), y(y) {}

    /**
     * @brief Compara a igualdade entre dois pontos.
     * @param outro O ponto a ser comparado.
     * @return true se as coordenadas x e y forem estritamente iguais, false caso contrário.
     */
    bool operator == (const Ponto& outro) const;

    /**
     * @brief Obtém o valor da coordenada x.
     * @return O valor de x.
     */
    double getX() const;

    /**
     * @brief Obtém o valor da coordenada y.
     * @return O valor de y.
     */
    double getY() const;
};

inline double Ponto::getX() const {
    return x;
}

inline double Ponto::getY() const {
    return y;
}

inline bool Ponto::operator==(const Ponto& outro) const {
    return (this->x == outro.x && this->y == outro.y);
}

/**
 * @class Linha
 * @brief Classe que representa um segmento de reta delimitado por dois pontos (Objeto Valor).
 */
class Linha {
private:
    /** @brief Ponto inicial do segmento. */
    Ponto origem;
    /** @brief Ponto final do segmento. */
    Ponto destino;
public:
    /**
     * @brief Construtor da classe Linha.
     * @param origem Ponto de origem.
     * @param destino Ponto de destino.
     */
    Linha(Ponto origem, Ponto destino) : origem(origem), destino(destino) {}

    /**
     * @brief Compara a igualdade entre duas linhas.
     * @param outra A linha a ser comparada.
     * @return true se os pontos de origem e destino forem respetivamente iguais, false caso contrário.
     */
    bool operator == (const Linha& outra) const;

    /**
     * @brief Obtém o ponto de origem.
     * @return O ponto de origem.
     */
    Ponto getOrigem() const;

    /**
     * @brief Obtém o ponto de destino.
     * @return O ponto de destino.
     */
    Ponto getDestino() const;
};

inline Ponto Linha::getOrigem() const {
    return origem;
}

inline Ponto Linha::getDestino() const {
    return destino;
}

inline bool Linha::operator==(const Linha& outra) const {
    // Tira partido do operator== já implementado na classe Ponto
    return (this->origem == outra.origem && this->destino == outra.destino);
}

int main() {
    double x, y;

    cin >> x;
    cin >> y;
    Ponto pontoA(x,y);

    cin >> x;
    cin >> y;
    Ponto pontoB(x,y);

    cin >> x;
    cin >> y;
    Ponto pontoC(x,y);

    cin >> x;
    cin >> y;
    Ponto pontoD(x,y);

    if (pontoA == pontoB) {
        cout << "Pontos iguais";
    } else {
        cout << "Pontos diferentes";
    }

    if (pontoC == pontoD) {
        cout << "Pontos iguais";
    } else {
        cout << "Pontos diferentes";
    }

    Linha linhaA(pontoA, pontoB), linhaB(pontoC, pontoD);
    if (linhaA == linhaB) {
        cout << "Linhas iguais";
    } else {
        cout << "Linhas diferentes";
    }

    return 0;
}
