#include <iostream>

using namespace std;

class Nome {
    private:
        string valor;
    public:
        void set(string);
        string get();
};

class Matricula {
    private:
        int valor;
    public: 
        void set(int);
        int get();
};

class Estudante {
    // A classe Estudante (entidade) possui, como propriedades, dois objetos (dominios) da classe Nome e Matricula. 
    // Cada objeto possui as suas propriedades de valor.
    private:
        Nome nome;
        Matricula matricula;
    public:
        // O padrão do C++ é a passagem por valor. Caso um objeto fosse passado no construtor, uma cópia inteira dele seria inserida na memória ram.
        // Para resolver isso, usa-se a chamada por referência (&), que diz ao compilador: "Não faça uma cópia deste objeto. Apenas me passe o endereço de memória onde o objeto original está guardado"
        Estudante(Nome&, Matricula&);
        // Como nome e matrícula são privados, é necessário criar métodos de get da classe Estudante que utiliza o get das classes domínio para retornar seus valores
        Nome getNome();
        Matricula getMatricula();
};

void Nome::set(string valorDado) {
    this->valor = valorDado;
}

string Nome::get() {
    return this->valor;
}

void Matricula::set(int valorDado) {
    this->valor = valorDado;
}

int Matricula::get() {
    return this->valor;
}

// O construtor de Estudante recebe o endereço dos objetos e atribui aos atributos do objeto Estudante os valores apontados por referência
Estudante::Estudante(Nome& nomeDado, Matricula& matriculaDada) {
    this->nome = nomeDado;
    this->matricula = matriculaDada;
}

// Implementando gets que retornam o valor dos objetos dos domínio que estão dentro do objeto Estudante
// Nome: É o Tipo de Retorno. O método vai devolver um objeto da classe Nome
// Estudante:: É o Dono do Método. Informa ao compilador: "Vá na classe Estudante e procure o método que vou implementar agora".
// getNome(): É o Nome do Método e seus parâmetros.
Nome Estudante::getNome() {
    return this->nome;
}

Matricula Estudante::getMatricula() {
    return this->matricula;
}

int main(){
    string dadoA;
    int dadoB;

    cin >> dadoA;
    cin >> dadoB;

    Nome nome;
    Matricula matricula;
    
    nome.set(dadoA);
    matricula.set(dadoB);

    Estudante estudante(nome, matricula);

    cout << estudante.getNome().get(); // getNome() retorna o objeto nome de Estudante e get() retorna o valor do nome
    cout << estudante.getMatricula().get();

    return 0;
}
