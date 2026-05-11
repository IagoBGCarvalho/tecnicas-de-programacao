#include <iostream>
using namespace std;

class Elemento{
	private:
		int dado;
		Elemento* ptr_proximo;
	public:
		void setDado(int);
		int getDado();
		void setProximo(Elemento*);
		Elemento* getProximo();
};

inline void Elemento::setDado(int dado){
	this->dado = dado;
}

inline int Elemento::getDado(){
	return dado;
}

inline void Elemento::setProximo(Elemento *ptr_elemento){
	ptr_proximo = ptr_elemento;
}

inline Elemento* Elemento::getProximo(){
	return ptr_proximo;
}

class Pilha {
	private:
		Elemento* ptr_primeiro;
	public:
		Pilha() { ptr_primeiro = NULL; }
		void inserir(Elemento*);
		Elemento* remover();
};

// Implementações dos métodos
void Pilha::inserir(Elemento* ptr_elemento) {
    // O próximo do novo elemento aponta para o atual topo da pilha
    ptr_elemento->setProximo(ptr_primeiro);

    // O topo da pilha passa a ser este novo elemento
    ptr_primeiro = ptr_elemento;
}

Elemento* Pilha::remover() {
    // Verificação de segurança: se a pilha estiver vazia, retorna NULL
    if (ptr_primeiro == NULL) {
        return NULL;
    }

    // Guarda a referência do elemento que está no topo
    Elemento* elemento_removido = ptr_primeiro;

    // O novo topo passa a ser o elemento que estava logo abaixo
    ptr_primeiro = ptr_primeiro->getProximo();

    // Retorna o elemento extraído
    return elemento_removido;
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

	Pilha pilha;
	pilha.inserir(&elementoA);
	pilha.inserir(&elementoB);
	pilha.inserir(&elementoC);

	cout << pilha.remover()->getDado();
	cout << pilha.remover()->getDado();
	cout << pilha.remover()->getDado();

	return 0;
}
