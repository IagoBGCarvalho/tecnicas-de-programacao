#include <iostream>
#include <stdexcept>
using namespace std;

class Matriz {
private:
    unsigned int linhas, colunas;
    double** dados;
public:
    // Declarações faltantes que o professor implementou fora da classe
    Matriz(unsigned int linhas, unsigned int colunas);
    ~Matriz();
    double& operator()(unsigned int l, unsigned int c) const;
    Matriz operator*(const Matriz&) const;

    // A função externa precisa ser 'friend' para acessar as variáveis privadas
    friend ostream& operator<<(ostream& os, const Matriz& matriz);

    Matriz operator+(const Matriz&) const;
    Matriz operator-(const Matriz&) const;
};

// Implementação da Soma (+)
Matriz Matriz::operator+(const Matriz& matriz) const {
    if (this->linhas != matriz.linhas || this->colunas != matriz.colunas) {
        throw invalid_argument("Tamanho incompativel.");
    }

    Matriz resultado(linhas, colunas);
    for (unsigned int i = 0; i < linhas; ++i) {
        for (unsigned int j = 0; j < colunas; ++j) {
            resultado.dados[i][j] = this->dados[i][j] + matriz.dados[i][j];
        }
    }
    return resultado;
}

// Implementação da Subtração (-)
Matriz Matriz::operator-(const Matriz& matriz) const {
    if (this->linhas != matriz.linhas || this->colunas != matriz.colunas) {
        throw invalid_argument("Tamanho incompativel.");
    }

    Matriz resultado(linhas, colunas);
    for (unsigned int i = 0; i < linhas; ++i) {
        for (unsigned int j = 0; j < colunas; ++j) {
            resultado.dados[i][j] = this->dados[i][j] - matriz.dados[i][j];
        }
    }
    return resultado;
}

Matriz::Matriz(unsigned int linhas, unsigned int colunas) : linhas(linhas), colunas(colunas) {
    dados = new double*[linhas];
    for (unsigned int i = 0; i < linhas; i++) {
        dados[i] = new double[colunas];
        for (unsigned int j = 0; j < colunas; j++) {
            dados[i][j] = 0;
        }
    }
}

Matriz::~Matriz() {
    if (dados != nullptr) {
        for (unsigned int i = 0; i < linhas; ++i) {
            delete[] dados[i];
        }
        delete[] dados;
    }
}

double& Matriz::operator()(unsigned int l, unsigned int c) const {
    return dados[l][c];
}

Matriz Matriz::operator*(const Matriz& matriz) const {
    if (colunas != matriz.linhas)
        throw invalid_argument("Tamanho incompativel.");
    Matriz resultado(linhas, matriz.colunas);
    for (unsigned int i = 0; i < linhas; ++i) {
        for (unsigned int j = 0; j < matriz.colunas; ++j) {
            for (unsigned int k = 0; k < colunas; ++k) {
                    resultado.dados[i][j] += dados[i][k] * matriz.dados[k][j];
            }
        }
    }
    return resultado;
}

ostream& operator<<(ostream& os, const Matriz& matriz) {
    for (unsigned int i = 0; i < matriz.linhas; ++i) {
        for (unsigned int j = 0; j < matriz.colunas; ++j) {
            os << matriz.dados[i][j] << " ";
        }
    }
    return os;
}

int main() {
    try {
        Matriz m1(2, 2), m2(2,2);
        cin >> m1(0,0) >> m1(0,1) >> m1(1,0) >> m1(1,1);
        cin >> m2(0,0) >> m2(0,1) >> m2(1,0) >> m2(1,1);
        cout << (m1 + m2);
        cout << (m1 - m2);
        cout << (m1 * m2);
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }
    return 0;
}
