#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Senha
 * @brief Classe que representa uma Senha como um Objeto Valor (Value Object).
 */
class Senha {
private:
    /** @brief String que armazena a sequência de dígitos da senha. */
    string valor;

    /**
     * @brief Valida o formato da senha segundo as regras de negócio.
     * @param str A string a ser validada.
     * @return true se a senha atende a todas as regras, false caso contrário.
     */
    bool validar(const string& str) const;
public:
    /**
     * @brief Construtor da classe Senha.
     * @param valor String contendo a senha.
     * @exception std::invalid_argument Lança exceção se a senha for inválida.
     */
    Senha(const string& valor);

    /**
     * @brief Compara a igualdade de valor entre duas senhas.
     * @param outra Objeto Senha a ser comparado.
     * @return true se as senhas forem idênticas, false caso contrário.
     */
    bool operator==(const Senha& outra) const;

    /**
     * @brief Obtém a string correspondente ao valor da senha.
     * @return O valor da senha.
     */
    string getValor() const;
};

Senha::Senha(const string& valor) {
    if (!validar(valor)) {
        throw invalid_argument("Senha invalida");
    }
    this->valor = valor;
}

bool Senha::validar(const string& str) const {
    // 1. A senha deve ter exatamente 6 dígitos
    if (str.length() != 6) {
        return false;
    }

    for (int i = 0; i < 6; ++i) {
        // 2. Não pode existir o dígito zero e deve ser numérico ('1' a '9')
        if (str[i] < '1' || str[i] > '9') {
            return false;
        }

        // 3. Não podem existir dígitos repetidos
        for (int j = i + 1; j < 6; ++j) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }

    return true;
}

bool Senha::operator==(const Senha& outra) const {
    // Comparação de valor direto (característica do Value Object)
    return this->valor == outra.valor;
}

inline string Senha::getValor() const {
    return valor;
}

int main() {
    string valorA, valorB;
    cin >> valorA;
    cin >> valorB;
    try {
        Senha senhaA(valorA);
        Senha senhaB(valorB);
        if(senhaA == senhaB){
            cout << "Senhas iguais";
        } else {
            cout << "Senhas diferentes";
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
