#include <iostream>
#include <stdexcept> // Biblioteca que contém as exceções
using namespace std;

const int TAMANHO_MAXIMO = 5;

class Nome {
    private:
        string valor;
        void validar(string);
    public:
        void set(string);
        string get();
};

void Nome::validar(string valorDado) {
    // Verifica se o comprimento da string excede o limite definido
    if (valorDado.length() > TAMANHO_MAXIMO) {
        // Lança a exceção com a mensagem exata solicitada pelo corretor
        throw invalid_argument("Argumento invalido");
    }
}

void Nome::set(string valorDado) {
    // O método validar atua como um "portão". Se falhar, o código para aqui.
    // A exceção lançada por validar é passada para o set que pode vir a ser capturada por um catch
    validar(valorDado);
    // Se passou da linha de cima, a atribuição ocorre com segurança.
    this->valor = valorDado;
}

string Nome::get() {
    return this->valor;
}

int main(){
    string dadoA, dadoB;

    cin >> dadoA;
    cin >> dadoB;

    Nome nome;

    try{
        nome.set(dadoA);
    }
    // O C++ captura a exceção por referência (&) para evitar cópias desnecessárias na memória
    catch(invalid_argument &excessao){
        cout << excessao.what(); // acessa a memória do objeto do erro e retornar a mensagem de texto exata que o programador definiu no momento em que o erro foi disparado
    }

    try{
        nome.set(dadoB);
    }
    catch(invalid_argument &excessao){
        cout << excessao.what();
    }
    return 0;
}
