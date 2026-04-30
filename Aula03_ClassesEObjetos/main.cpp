#include <iostream> // Biblioteca para entrada (cin) e saída (cout) de dados

using namespace std;

class Codigo {
     // Classe domínio que representa um código no mundo real. Deve possuir o campo de valor e os métodos set e get de acesso da propriedade.
     private:
          int valor;

     public:
          void set(int); // Apenas declara para futura implementação
          int get(){ 
               return valor; // Faz declaração inline de código que será inserido na compilação, mas tudo bem pois é um código pequeno
          };
};

void Codigo::set(int valor){
     // Uso de operador de resolução de escopo (::) para fazer a implementação do método set da classe Codigo
     this->valor = valor; // this altera o valor das propriedades do objeto instanciado
}

int main(){
     Codigo codigo; // Instanciando um objeto da classe Codigo e o chamando de codigo

     int valor;

     cin >> valor; // cin atribui o que foi digitado no teclado pelo usuário a variável valor

     codigo.set(valor); // Chama o método set da classe Codigo passando a variável valor e alterando o valor do código

     cout << codigo.get(); // Joga na saída do terminal o resultado do get

     return 0;
}
