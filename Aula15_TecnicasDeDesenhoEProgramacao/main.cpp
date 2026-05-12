#include <iostream>
using namespace std;

class Elemento {
private:
    int dado;
    Elemento *ptr_proximo;
public:
    Elemento() { ptr_proximo = NULL; }
    void setDado(int d) { dado = d; }
    int getDado() { return dado; }
    void setProximo(Elemento* p) { ptr_proximo = p; }
    Elemento* getProximo() { return ptr_proximo; }
};

class Fila {
private:
    Elemento *ptr_primeiro;
    Elemento *ptr_ultimo;
public:
    Fila() {
        ptr_primeiro = NULL;
        ptr_ultimo = NULL;
    }
    void inserir(Elemento*);
    Elemento* remover();
};

void Fila::inserir(Elemento* ptr_elemento) {
    ptr_elemento->setProximo(NULL); // O novo elemento será o fim, então aponta para NULL
    if (ptr_primeiro == NULL) {
        // Fila vazia: primeiro e último são o mesmo elemento
        ptr_primeiro = ptr_elemento;
        ptr_ultimo = ptr_elemento;
    } else {
        // Fila com dados: conecta o último atual ao novo e atualiza o ponteiro de fim
        ptr_ultimo->setProximo(ptr_elemento);
        ptr_ultimo = ptr_elemento;
    }
}

Elemento* Fila::remover() {
    if (ptr_primeiro == NULL) {
        return NULL;
    }
    Elemento* temp = ptr_primeiro;
    ptr_primeiro = ptr_primeiro->getProximo();

    // Se a fila esvaziou, o último também deve ser NULL
    if (ptr_primeiro == NULL) {
        ptr_ultimo = NULL;
    }

    return temp;
}

int main() {
     Elemento elementoA, elementoB, elementoC;
     int dado;
     cin >> dado;
     elementoA.setDado(dado);
     cin >> dado;
     elementoB.setDado(dado);
     cin >> dado;
     elementoC.setDado(dado);
     Fila fila;
     fila.inserir(&elementoA);
     fila.inserir(&elementoB);
     fila.inserir(&elementoC);
     cout << fila.remover()->getDado();
     cout << fila.remover()->getDado();
     cout << fila.remover()->getDado();
     return 0;
}
